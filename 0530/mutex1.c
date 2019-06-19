#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int ncount;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;		// 쓰레드 초기화

void* do_loop(void *data)
{
	int i;

	pthread_mutex_lock(&mutex);

	for(i=0; i<5; i++)
	{
		printf("th_func1 : %d\n", ncount);
		ncount++;
		sleep(1);
	}

	pthread_mutex_unlock(&mutex);
}

void* do_loop2(void *data)
{
	int i;

	pthread_mutex_lock(&mutex);

	for(i=0; i<5; i++)
	{
		printf("th_func2 : %d\n", ncount);
		ncount++;
		sleep(1);
	}

	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t p_thread[2];

	int thr_id;
	int status;
	int a=1;

	ncount=0;
	thr_id = pthread_create(&p_thread[0], NULL, do_loop, (void *)&a);
	thr_id = pthread_create(&p_thread[1], NULL, do_loop2, (void *)&a);

	pthread_join(p_thread[0], (void *)&status);
	pthread_join(p_thread[1], (void *)&status);

	status = pthread_mutex_destroy(&mutex);

	printf("code = %d\n", status);
	printf("progamming is end");

	return 0;
}
