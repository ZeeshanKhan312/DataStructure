//Optimal BST for Successfull and UnSucessfull search
//For only Successfull BST fill the unsuccessfull value as '0'

#include<stdio.h>
#include<conio.h>
struct keys{ 
    int node;
    int p;
    int q;
};
void main()
{
    int n;
    printf("Enter the number of elements:");
	scanf("%d",&n);
    struct keys data[n+1];
    int i,j;
	printf("Enter the unsucees Probability from -Infinity to 1st Data:");
	scanf("%d",&data[0].q);
    for(i=1; i <= n; i++)
	{
		printf("Enter the Element of %d:",i);
		scanf("%d",&data[i].node);
        printf("Enter the success Probability of %d:",i);
		scanf("%d",&data[i].p);
        printf("Enter the unsucees Probability of %d:",i);
		scanf("%d",&data[i].q);
	}
    int cost[n+1][n+1],w[n+1][n+1],root[n+1][n+1];//initialising the cost,weight and root 
	for(i=0;i<=n;i++)//to store the value of same 'i' and 'j' bcuz it's cost will be 0 
	{
		w[i][i] = data[i].q;
		cost[i][i] = 0;
		root[i][i] = 0;
	}
    for(int x=1; x <= n; x++)
	{
		for(i=0,j=x; j <= n; i++,j++)//storing the data in cost[0][1] then cost [1][2] way bcuz of formula
		{
				w[i][j]=w[i][j-1]+data[j].p+data[j].q;// formulla to find weight of uncommon 'i' and 'j'
			    cost[i][j]=9999;
			for(int k=i+1;k<=j;k++)
			{
				int c=cost[i][k-1]+cost[k][j];// finding the min cost value for cost[i][j]
				if(c<cost[i][j])
				{
				cost[i][j]=c;
				root[i][j]=k;
				}
			}
			    cost[i][j]+=w[i][j];	//adding weight value to get the final value of cost[i][j]
		}
	}
	printf("The Minimum cost of BST is %d\nRoot is %d",cost[0][n],root[0][n]);
}