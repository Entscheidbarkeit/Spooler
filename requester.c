#define _POSIX_C_SOURCE  200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "requester.h"

void requestSong(char* pipeFilePath, int songId) {
	printf("Requesting song %d...", songId);
	int fd = open(pipeFilePath, O_WRONLY);
	dprintf(fd, "%d\n", songId);
	printf("Song %d requested.\n", songId);
	close(fd);
	exit(0);
}
