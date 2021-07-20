#include <stdio.h>
void main() 
{
	int i, j, n;
	printf("Enter the last number\n");
	scanf_s("%d", &n);
	printf("List of all the prime numbers between 1- %d are as follows \n",n);
	for (i = 2; i <= n; i++) 
	{
		int Prime = 1;
		for (j = 2; j < i; j++) 
		{
			if (i % j == 0) 
			{
				Prime = 0;
			}
		}
	  if (Prime) 
      {
			printf("%d \n", i);
	  }
	}
}