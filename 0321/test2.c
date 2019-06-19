/**/
#include <stdio.h>
#include <stdlib.h>
#include "cal.h"


int sum(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);

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

	switch(op){
		case'+':
			result = sum(num1,num2);
			break;
		case'-':
			result = sub(num1, num2);
			break;
		case'*':
			result = mul(num1, num2);
			break;
		case'/':
			result = div(num1, num2);
			break;
	}

	printf("출력 : %d\n", result);

	return 0;
}

}
