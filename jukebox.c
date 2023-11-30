#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include "jukebox.h"
#include "songs.h"

// Whether the jukebox should run.
int shouldRun = 0;
int votes[32] = { 0 };
pthread_t reader1, reader2;

int max(int votes[]);

void runJukebox(char* pipeFilePath, int delay) {
	printf("Welcome to the GBS Jukebox!\n");
	shouldRun = 1;
	startStdinReader();
	startPipeReader(pipeFilePath);
	while (shouldRun == 1) {
		int nextSong = max(votes);
		int pid = getpid();
		if (votes[nextSong] != 0) {
			pid = fork();
			if (pid == 0) { // child process
				votes[nextSong] = 0;
				printf("Playing: %s\n", SONGS[nextSong].title);
				for (size_t i = 0; i < SONGS[nextSong].lines; i++) {
					printf("%s", SONGS[nextSong].lyrics[i]);
					sleep(delay);
				}
				exit(0);
			}
			else { // father process
				wait((int*)WNOHANG);
			}
		}
		sleep(1);
	}
	//pthread_kill(reader1, SIGKILL);
	//pthread_kill(reader2, SIGKILL);
	wait((int*)WNOHANG);
	printf("Goodbye\n");
	exit(0);
}

int max(int votes[]) {
	int max = 0;
	for (int i = 0; i < 32; i++) {
		if (votes[i] > votes[max])
			max = i;
	}
	return max;
}

//-----------------------------pipe-Thread---------------------------------------
void* p_func(void* path);

void startPipeReader(char* pipeFilePath) {
	mkfifo(pipeFilePath, NAMED_PIPE_ACCESS_RIGHT);
	pthread_create(&reader1, NULL, p_func, (void *)pipeFilePath);
}

void* p_func(void* path) {
	int bufferSize = 100;
	char* buffer = malloc(bufferSize);
	while (shouldRun==1) {
		int fd = open((char*)path, O_RDONLY);
		read(fd, buffer, bufferSize);
		int songNum = charToInt(buffer);
		if (songNum<0 || songNum>=NUM_SONGS) {
			printf("Invalid song ID %d\n", songNum);
		}
		else {
			printf("Vote for song id %d received.\n", songNum);
			votes[songNum]++;
		}
	}
	pthread_exit(NULL);
}

int charToInt(char* param) {
	int length = 0;
	int result = 0;
	while (true) {
		if (param[length] != '\n'&&param[length] != '\0')
			length++;
		else
			break;
	}
	int schritt = 1;
	for (int i = 0; i < length-1; i++) {
		schritt *= 10;
	}
	for (int i = 0; i < length; i++) {
		result += ((int)param[i] - 48) * schritt;
		schritt /= 10;
	}
	if(result < 0)
	   result = -300 - result;
	return result;
}

//-----------------------------stdin-Thread--------------------------------------
void* reading(void* param);
bool qDetermin(char* string);

void startStdinReader() { 
	pthread_create(&reader2, NULL, reading, NULL);
}


void* reading(void* param) {
	(void)param;
	char* content = malloc(100);
	while (true) {
		scanf("%s", content);
		if (qDetermin(content))
			break;
	}
	shouldRun = 0;
	pthread_exit(NULL);
}

bool qDetermin(char* string) {
	int i = 0;
	bool hasQ = false;
	while (true) {
		if (string[i] == '\0')
			break;
		if (string[i] == 'q') {
			hasQ = true;
			break;
		}
		i++;
	}
	return hasQ;
}
