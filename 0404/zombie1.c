#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	pid_t pid;
	int i;

	for(i=0; i<5; i++) {
		if((pid = fork()) < 0) {
			perror("fork error");
		} else if(pid == 0) {
			printf("bye from child %d : %d\n", i, getpid());
			return(0);
		}
	}

	sleep(5);
	printf("bye from parent\n");

	return (0);
}
