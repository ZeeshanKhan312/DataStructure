#include<stdio.h>
void main() 
{
	int ch;
	float f, c;
	printf("Enter your choice\n");
	printf("1. Celcius to Fahrenhite\n");
	printf("2. Fahrenhite to Celcius\n");
	scanf("%d",&ch);
	switch (ch) 
	{
	case 1:
		printf("Enter the temperature in Celcius \n");
		scanf("%f", &c);
		f = (1.8 * c + 32);
		printf("Temperature in Fahrenhite= %f \n", f);
		break;
	case 2:
		printf("Enter the temperature in Fahrenhite \n");
		scanf("%f", &f);
		c = (f - 32) * 0.55;
		printf("Temperature in Celciuse= %f \n", c);
		break;
	default:
		printf("Invalid choice");
		break;
	}
}
