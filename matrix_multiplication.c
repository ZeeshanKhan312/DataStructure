#include<stdio.h>
#define max 50
void main()
{
	int arow, acolumn, brow, bcolumn;
	printf("Enter the no. of rows & column in 1st matrix\n ");
	scanf_s("%d %d", &arow, &acolumn);
	printf("Enter the no. of rows & column in 2nd matrix\n ");
	scanf_s("%d %d", &brow, &bcolumn);
	int a[max][max],b[max][max],product[max][max];
	if (acolumn!=brow )
	{
		printf("Sorry Matrix couldn't be formed. Pls check the matrix order\n");
	}
	else
	{
		printf("Enter the elements of 1st matrix\n");
		int i, j,k;
		for (i = 0; i < arow; i++)
		{
			for (j = 0; j < acolumn; j++)
			{
				scanf_s("%d", &a[i][j]);
			}
		}
		printf("Enter the elements of 2nd matrix\n");
		for (i = 0; i < brow; i++)
		{
			for (j = 0; j < bcolumn; j++)
			{
				scanf_s("%d", &b[i][j]);
			}
		}
		//Multiplying the matrix
		int sum = 0;
		for (i = 0; i < arow; i++)
		{
			for (j = 0; j < brow; j++)
			{
				for (k = 0; k < brow; k++)
				{
					sum += a[i][k] * b[k][j];
				}
				product[i][j] = sum ;
				sum = 0;
			}
		}
		printf("Resultant Matrix\n");
		for (i = 0; i < arow; i++)
		{
			for (j = 0; j < bcolumn; j++)
			{
				printf("%d ", product[i][j]);
			}
			printf("\n");
		}
	}
}
