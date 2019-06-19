#include <stdio.h>

int func(int x);

int main(void)
{
	int x;

	printf("Hello world\n");

	x = func(10);

	printf("%d\n", x);

	return 0;
}

int func(int x)
{
	return x + 10;
}
