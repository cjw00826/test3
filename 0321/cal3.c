#include <stdio.h>
#include <stlib.h>
#include <cal.h>

int main()
{
	char op;
	int num1, num2;
	int result;
	
	printf("입력1 : ");
	scanf("%s", &op);

	printf("입력2 : ");
	scanf("%d", &num1);

	printf("입력3 : ");
	scanf("%d", &num2);

	printf("출력 : %d\n", result);

	return 0;
}


/*
int sum(int num1, int num2)
{
	int result = 0;
	result = num1 + num2;

	return result;
}

int sub(int num1, int num2)
{
	int result =0;
	result = num1 - num2;
	return result;
}

int mul(int num1, int num2)
{
	int result =0;
	result = num1 * num2;
	return result;
}

int div(int num1, int num2)
{
	int result =0;
	result = num1 / num2;
	return result;
}
 */
