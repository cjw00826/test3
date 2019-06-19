#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include "helpers.h"

int main() {
	pid_t pid;

	printf("before fork (%d)\n", getpid());
	if((pid = fork()) < 0) {
		perror("fork error\n");
	} else if (pid == 0) {
		printf("hi from child! (%d)\n", getpid());
		printf("hi from child! (%d)\n", getppid());
	} else {
		printf("hi from parent! (%d)\n", getpid());
		printf("hi from parent! (%d)\n", getppid());	//bash 값
	}

	printf("bye (%d)\n", getpid());
	
	return(0);
	//exit(EXIT_SUCCESS);
}
