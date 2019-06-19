/* sigaction1.c  */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction act_new;
struct sigaction act_old;

/*
 man sigaction


struct sigaction{
	void (*sa_handler)(int);
	void (*sa_sigaction)(int, )

};
 
 */

void sigint_handler(int signo)
{
	printf("\nCtrl-C 입력됨\n");
	printf("다시 입력시 종료\n");
	sigaction(SIGINT, &act_old, NULL);
}

int main()
{
	act_new.sa_handler = sigint_handler;	//	시그널 핸들러 지정
	sigemptyset(&act_new.sa_mask);			//	시그널 처리 중 블록될 시그널은 없음

	sigaction(SIGINT, &act_new, &act_old);

	while(1)
	{
		printf("sigaction\n");
		sleep(1);
	}

	return 0;
}
