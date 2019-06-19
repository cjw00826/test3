#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction act_new();
struct sigaction act_old();

int main()
{
	sigset_t sigset;
	int index;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigprocmask(SIG_BLOCK, &sigset, NULL);

	sigaction(SIGINT, &act_new, &act_old);

	for(index = 10; 0 < index; index--)
	{	
		printf("카운트 다운 : %d", index);
		sleep(1);
	}

	printf("");
	sigprocmask(SIG_UNBLOCK, &sigset, NULL);
	printf("");

	return 0;
}
