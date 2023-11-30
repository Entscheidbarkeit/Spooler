#include <stdio.h> // For printf(...)
#include <stdlib.h> // For EXIT_SUCCESS
#include <stdbool.h>
#include "jukebox.h"
#include "requester.h"
#include "songs.h"

void printHelp(char* progName);
bool stringCompare(char* s1, char* s2);

int main(int argc, char* argv[]){
	if (argc != 6)
		printHelp(argv[0]);
	else {
		if (stringCompare(argv[1], "-jukebox\0") && stringCompare(argv[2], "-path\0") && stringCompare(argv[4], "-delay\0")) {
			runJukebox(argv[3], charToInt(argv[5]));
		}
		else if (stringCompare(argv[1], "-request\0") && stringCompare(argv[2], "-path\0") && stringCompare(argv[4], "-id\0")) {
			int id = charToInt(argv[5]);
			if (id < 0 || id > NUM_SONGS) {
				printf("Invalid song ID %d. Has to be from range 0 to %d\n", id, NUM_SONGS);
				return EXIT_FAILURE;
			}
			requestSong(argv[3],id);
		}
		else printHelp(argv[0]);
	}
	return 0;
}

bool stringCompare(char* s1, char* s2) {
	int i = 0;
	bool flag = true;
	while (s1[i] != '\0' || s2[i] != '\0') {
		if (s1[i] != s2[i]) {
			flag = false;
			break;
		}
		i++;
	}
	return flag;
}


void printHelp(char* progName) {
	printf("================Help================\n");
	printf("%s -jukebox -path <char*> -delay <int> : Starts a spooler jukebox process with the path for the named pipe and a delay in seconds between lines.\n", progName);
	printf("%s -request -path <char*> -id <int> : Request the given song id at the given named pipe path.\n", progName);
	printf("%s -help : Prints this help.\n", progName);
	printf("====================================\n");
}
