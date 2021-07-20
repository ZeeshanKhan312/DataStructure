#include<stdio.h>
void main()
{
	float num1, num2;
	char op,n;
	float result;
	printf("Enter the statement\n");
	scanf("%f%c%f",&num1,&op,&num2);
	switch (op)
	{
	case '-':
		result = num1 - num2;
		printf("Result=%f", result);
		break;
	case'+':
		result = num1 + num2;
		printf("Result=%f", result);
		break;
	case'*':
		result = num1 * num2;
		printf("Result=%f", result);
		break;
	case'/':
		result = num1 / num2;
		printf("Result=%f", result);
		break;
	default:
		printf("The operator is not valid");
	}
	printf("\nDo you want to continue write 'y' if yes: ");
	scanf(" %c", &n);
	if (n == 'y')
		main();
	else
		printf("-----------------------------------------");
}