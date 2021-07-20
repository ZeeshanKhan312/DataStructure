#include<stdio.h>
void main()
{
	int a, b, c;
	printf("Enter the value of A\n");
	scanf("%d", &a);
	printf("Enter the value of B\n");
	scanf("%d", &b);
	c = a + b;
	b = c - b;
	a = c - a;
	printf("The value of A & B after swapping is %d & %d respectively", a, b);
}