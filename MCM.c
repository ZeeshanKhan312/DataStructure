//Matrix Chain Multiplication

#include<stdio.h>
void main()
{
    int n;
    printf("Enter the no. of Matrix: ");
    scanf("%d",&n);
    int d[n+1],mult[n+1][n+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
    printf("Enter the row size for Matrix %d:",i+1);
    scanf("%d",&d[i]);
    }
    for(i=0;i<=n;i++)//to store the value of same 'i' and 'j' bcuz it's cost will be 0 
		mult[i][i] = 0;
    for(int x=1; x < n; x++)
	{
		for(i=1,j=i+x; i<=n-x; i++,j++)//storing the data in cost[0][1] then cost [1][2] way bcuz of formula
		{
			mult[i][j]=9999;
			for(int k=i;k<j;k++)
			{
				int c=mult[i][k]+mult[k+1][j]+(d[i-1]*d[k]*d[j]);// finding the min cost value for cost[i][j]
				if(c<mult[i][j])
				{
				mult[i][j]=c;
				}
			}
		}
	}
    printf("Minimum multiplication requires is %d",mult[1][n]);
}