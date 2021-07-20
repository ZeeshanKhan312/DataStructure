#include<stdio.h>
int n,k=0;
void dfs(int a[n][n],int visited[n],int arr[n],int root) 
{  	
    arr[k++]=root;
    visited[root]=1;
for(int i=0;i<n;i++)
   {
       if(a[root][i]==1&&!visited[i])
            dfs(a,visited,arr,i);
   }
}
void main() 
{
	int i,j;
	int arr[n],visited[n];
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	int a[n][n];
	printf("\n Enter graph data in matrix form:\n");
	for (i=0;i<n;i++)
	{
		visited[i]=0;
	  for (j=0;j<n;j++)
	   scanf("%d",&a[i][j]);
	}  
	printf("\n Enter the root vertex:");
    int v;
	scanf("%d",&v);
	dfs(a,visited,arr,v);
	printf("\n The DFS of this Graph is:- \n");
	for (i=0;i<n;i++)
	   printf("%d\t",arr[i]); 
}