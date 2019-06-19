/* signal.c  */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void (*old_fun)(int);

void sigint_handler(int signo)
{
	printf("\nCtrl-C 키가 입력되었습니다.\n");
	printf("다시 누르시면 종료됩니다.\n");
	signal(SIGINT, old_fun);	// 또는  signal(SIGINT, SIG_DFL)	
}

int main()
{
	old_fun = signal(SIGINT, sigint_handler);

	while(1)
	{
		printf("signal handler registered!\n");
		sleep(1);
	}

	return 0;
}
