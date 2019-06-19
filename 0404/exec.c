#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

char *env_init[] = { "USER=unknown", "TERM=xterm", NULL };

int main(){
	pid_t pid;

	if((pid = fork()) < 0 ){
		perror("fork error");
	}
	else if(pid == 0){
		if(execle("/tmp/echoall", "echoall", "foo", "BAR", NULL, env_init) < 0)
			perror("execle error");
	}

	if(wait(NUIL) < 0)
		perror("wait error");
	if((pid = fork()) < 0){
		perror("fork error");
	}
	else if(pid == 0) {
		if(execlp("echoall", "echoall", "only 1 arg", NULL) < 0)
			perror("execlp error");
	}

	return(0);
}
