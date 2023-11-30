#pragma once

/**
 * Access right for the named pipe in octal.
 * Do not change!
 **/
#define NAMED_PIPE_ACCESS_RIGHT 0666

void runJukebox(char* pipeFilePath, int delay);
void startPipeReader(char* pipeFilePath);
void startStdinReader();
int charToInt(char* param);
