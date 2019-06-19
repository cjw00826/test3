#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;

//	printf();

	if((pid = fork()) < 0){
		perror("fork error\n");
	} else if (pid == 0) {
		printf("child\n");
	} else {
		printf("parent\n");
	}
	
	
	return 0;
}
