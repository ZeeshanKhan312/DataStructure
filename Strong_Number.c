//Strong number is a special number whose sum of factorial of digits is equal to the original number. 
#include<stdio.h>
void main()
{
	int n, i, j, r, x, q, sum;
	printf("Enter the last number\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		r = 0;
		sum = 0;
		x = i;
		while (i > 0)
		{
			r = i % 10;
			q = 1;
			for (j = 1; j <= r; j++)
			{
				q = q * j;
			}
			sum += q;
			i = i / 10;
		}
		i = x;
		if (i == sum)
		{
			printf("Strong Number=%d\n", i);
		}
	}
}