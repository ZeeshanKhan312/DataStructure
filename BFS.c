#include<stdio.h>
int a[20][20],queue[20],visited[20];
int n,i,j,f=0,r=0,k=0;
void bfs(int v,int arr[n]) 
{  
	for (i=0;i<n;i++)
	  if(a[v][i] && !visited[i])
    {
	   queue[++r]=i;
    }
  	if(k<n)
    {
		if(!visited[queue[f]])
		{
			arr[k]=queue[f];
			++k;
		}
		visited[queue[f++]]=1;
		bfs(queue[f],arr);
    }
}
void main() 
{
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	printf("\n Enter graph data in matrix form:\n");
	for (i=0;i<n;i++)
	  for (j=0;j<n;j++)
	   scanf("%d",&a[i][j]);
	int arr[n];   
	printf("\n Enter the root vertex:");
  int v;
	scanf("%d",&v);
  queue[r]=v;
	bfs(v,arr);
	printf("\n The BFS of this Graph is:- \n");
	for (i=0;i<n;i++)
	   printf("%d\t",arr[i]); 
}