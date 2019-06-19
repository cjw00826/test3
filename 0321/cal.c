#include <stdio.h>

int cal( )
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
			result = num1 + num2;
			break;
		case'-':
			result = num1-num2;
			break;
		case'*':
			result = num1 * num2;
			break;
		case'/':
			result = num1 / num2;
			break;
	}

	printf("출력 : %d\n", result);

	return 0;
}
