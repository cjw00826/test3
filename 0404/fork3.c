#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char buf[] = "write to stdout\n";

int main() {		
	pid_t pid;
	
	// write() is a system call provide by OS
	if(write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf))
		perror("write error");

	// printf() is provided from glibc	(C언어 라이브러리에서 제공)
	// buffer is used for various reasons
	printf("printf by %d: before fork\n", getpid());

	if((pid = fork ()) < 0){
		perror("fork error");
	}
	else if(pid == 0){
		printf("printf by %d : hi from child! \n", getpid());
	}
	else {
		printf("printf by %d : hi from parent! \n", getpid());
	}

	printf("printf by %d : bye\n", getpid());
	
	return(0);
}
