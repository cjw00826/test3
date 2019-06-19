#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int glob = 6;		// initialized data	초기화된 데이터

int main()
{
	int var;		// automatic variable
	pid_t pid;
	var = 88;
	printf("before vfork\n");

	if((pid = vfork()) < 0)
	{
		perror("vfork() error");
	}
	else if(pid == 0)		// child
	{						// modify parent's variables
		glob++;
		var++;
		_exit(0);			// child terminates
	}						// parent continues here

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);

	return 0;
}
