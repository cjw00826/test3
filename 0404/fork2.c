#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int glob = 42;

int main() {			// e-campus자료랑 결과 다르게 나옴
	int var;
	pid_t pid;
	var = 88;
	
	if((pid = fork ()) < 0){
		perror("fork error");
	} else if(pid == 0){
		printf("child pid : %d\n", getpid());
		glob++;
		var++;
	} else {
		printf("parent pid : %d\n", getpid());
		sleep(1);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	
	return(0);
}
