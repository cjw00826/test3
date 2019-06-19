#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid_t pid2;

	printf("before fork() : %d\n", getpid());

	if((pid = fork()) < 0){
		perror("fork() error");
	}
	//for 1st child
	else if(pid == 0){
		printf("hi from 1st child : my pid %d\n", getpid());

		// fork() again
		if((pid2 = fork()) < 0){
			perror("fork() error");
		}

		//for 2nd child
		else if(pid2 == 0){
			// 2nd child

			sleep(3);

			printf("hi from 2nd child : my pid %d\n", getpid());
			printf("hi from2nd child : my ppid %d\n", getppid());
		}
		else {
			// 1st child
			exit(0);
		}
	}
	else {
	}


	return 0;
}
