#include<stdio.h>
int min(int a,int b)
{
    return (a<b)?a:b;
}
void flyod_warshal(int v,int arr[v][v]) //used to find all pairs shortest path
{
    for(int k=0;k<v;k++)
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    } //time coplexity is of O(n^3)
}
void main()
{
   int v;
   printf("Enter the number of Vertices:");
   scanf("%d",&v);
   int arr[v][v];
   for(int i=0;i<v;i++) //adding edges in graph
   {
       for(int j=0;j<v;j++)
       {
           printf("Enter the Edge value from %d to %d: ",i+1,j+1); //Enter the value as 999 for no edges and 0 for the same vertice
           scanf("%d",&arr[i][j]);
       }
   } 
   flyod_warshal(v,arr);
    for(int i=0;i<v;i++) //printing the output
   {
       printf("\nminimun distancre from source %d: \n",i+1);
       for(int j=0;j<v;j++)
       {   
           printf("%d\t",arr[i][j]);
       }
   }
}