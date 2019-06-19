#include <stdio.h>
#include <signal.h>

int main()
{
	sigset_t set;

	sigemptyset(&set);			// 시그널 집합 변수의 내용을 모두 제거합니다.
	sigaddset(&set, SIGINT);	// 시그널 집합 변수에 SIGINT를 추가합니다.


	// SIGINT가 등록되었는지 확인합니다.
	switch(sigismember(&set, SIGINT))
	{
		case 1 : printf("SIGINT는 포합되어 있습니다.\n");
				 break;
		case 0 : printf("SIGINT는 없습니다.\n");
				 break;
		default: printf("sigismember() 호출에 실패했습니다.\n");
	}

	// SIGSYS가 등록되었는지 확인합니다.
	switch(sigismember(&set, SIGSYS))
	{
		case 1 : printf("SIGSYS는 포합되어 있습니다.\n");
				 break;
		case 0 : printf("SIGSYS는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출에 실패했습니다.\n");
	}


	return 0;
}
