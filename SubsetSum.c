//To find the subsets Sum 
#include<stdio.h>
#include<stdbool.h>
int tab[1000][1000];
bool sums(int n,int arr[],int sum)
{
    if(sum==0)
        return 1;
    if(n<=0)
        return 0;
    if (tab[n - 1][sum] != -1) //if the no. has already been visited then we will skip it
		return tab[n - 1][sum];
    if (arr[n - 1] > sum) //to check whether the Number is greater than the current sum
		return tab[n - 1][sum] = sums( n - 1,arr, sum);
	else
	{
        if(sums( n - 1,arr, sum - arr[n-1])) //checking if the element can be formed by including the last element
        return tab[n - 1][sum] = sums( n - 1,arr, sum - arr[n-1] );
        else
		return tab[n - 1][sum] = sums( n - 1,arr, sum );
	}
}
void main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum;
    scanf("%d",&sum);
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
            tab[i][j]=-1;
    }
    if(sums(n,arr,sum))
    printf("YES");
    else
    printf("NO");
}