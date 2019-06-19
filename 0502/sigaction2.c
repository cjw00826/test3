#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signo)
{
	int index;

	printf("\nCtrl-C 키가 입력\n");
	printf("10초간 대기, Ctrl-Z 입력시 일시정지\n");

	for(index = 10; 0 < index; index--)
	{
		printf("%d초 남았습니다.", index);
		sleep(1);
	}
}

int main()
{
	struct sigaction act;

	act.sa_handler = sigint_handler;
	sigfillset(&act.sa_mask);

	sigaction(SIGINT, &act, NULL);

	while(1)
	{
		printf("signal handler registered for SIGINT\n");
		sleep(1);
	}

	return 0;
}
