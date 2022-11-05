#include <stdio.h> // For printf(...)
#include <stdlib.h> // For EXIT_SUCCESS

void printHelp(char* progName);

int main(int argc, char* argv[]){
	return EXIT_FAILURE;
}

void printHelp(char* progName) {
	printf("================Help================\n");
	printf("%s -jukebox -path <char*> -delay <int> : Starts a spooler jukebox process with the path for the named pipe and a delay in seconds between lines.\n", progName);
	printf("%s -request -path <char*> -id <int> : Request the given song id at the given named pipe path.\n", progName);
	printf("%s -help : Prints this help.\n", progName);
	printf("====================================\n");
}
