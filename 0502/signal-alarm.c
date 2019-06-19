/* signal-alarm.c  */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int counter = 0;

void sig_handler(int signo)
{
	printf("알람 발생 %d\n", counter++);
	alarm(1);
}

int main()
{
	signal(SIGALRM, sig_handler);
	alarm(1);

	while(1)
	{
	}

	return 0;
}
