#include<stdio.h>
#include<math.h>
void main()
{
	float ans, num1, num2;
	char op;
	printf("Enter the  number\n");
	scanf("%f", &num1);
	printf("Enter the operation\n");
	scanf(" %c", &op);
	printf("Enter the number\n");
	scanf("%f", &num2);
	if (op == '+')
	{
		ans = num1 + num2;
		printf("ans=%f", ans);
	}
	else if (op == '-')
	{
		ans = num1 - num2;
		printf("ans=%f", ans);
	}
	else if (op == '*')
	{
		ans = num1 * num2;
		printf("ans=%f", ans);
	}
	else if (op == '/')
	{
		ans = num1 / num2;
		printf("ans=%f", ans);
	}
	else
		printf("Operaion not valid");
}