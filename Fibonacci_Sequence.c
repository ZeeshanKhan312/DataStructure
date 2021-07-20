// Fibonacci sequence is such that each number is the sum of the two preceding ones, starting from 0 and 1.
#include <stdio.h>
void main()
{
	int n,i,j,x,a,b;
	printf("Enter the number\n");
	scanf("%d", &n);
	a= 0;
	b = 1;
	for (i = 1; i <= n ; i++)
	{
		printf("%d ", a);
		x = a + b;
		a = b;
		b = x;
	}
}