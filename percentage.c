#include<stdio.h>
void main()
{
	float s1, s2, s3,s4,s5, percent;
	int n;
	printf("Enter the Number of Student\n");
	scanf("%d", &n);
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
	printf("Enter the marks of student %d\n",i );
	printf("\n");
	printf("Enter the marks of subejt1\n");
	scanf("%f", &s1);
	printf("Enter the marks of subejt2\n");
	scanf("%f", &s2);
	printf("Enter the marks of subejt3\n");
	scanf("%f", &s3);
	printf("Enter the marks of subject4\n");
	scanf("%f", &s4);
	printf("Enter the marks of subject5\n");
	scanf("%f", &s5);
	
	percent = ((s1 + s2 + s3+s4+s5) / 500) * 100;
	printf("Percentage=%f\n", percent);
		if (percent >= 80)
			printf("A Grade\n");
		else if (percent >= 70)
				printf("B Grade\n");
		else if (percent >= 60)
				printf("C Grade\n");
		else if (percent >= 50)
				printf("D Grade\n");
		else if (percent >= 40)
				printf("E Grade\n");
		else
		{
			printf("F Grade\n");
		}
		printf("\n");
	}
}