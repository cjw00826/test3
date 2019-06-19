int cal(char op, int num1, int num2)
{
	int result;

	switch(op){
		case'+':
			result = num1 + num2;
			break;
		case'-':
			result = num1 - num2;
			break;
		case'*':
			result = num1 * num2;
			break;
		case'/':
			result = num1 / num2;
			break;
	}
	
	return result;
}
