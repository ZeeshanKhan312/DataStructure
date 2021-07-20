// Travelling Salesman problem-- to find the shortest path to cover all the vertices 

#include<stdio.h>
void reduce_matric(int x,int z,int n,int graph[n][n],int cost)
{
    int reduction=0;
    int min;
    int temp=0;
    if(x!=z)
    {
        temp=graph[x][z];
        graph[z][0]=999;
    for(int i=0;i<n;i++)
    {
        graph[x][i]=999;
        graph[i][z]=999;
    }
    }

    for(int i=0;i<n;i++) //reducing From Row first
    {
        min=9999;
        for(int j=0;j<n;j++) //searching the smallest element in row
        {
            if(graph[i][j]<min)
            min=graph[i][j];
        }
        for(int j=0;j<n;j++) //subtracting the min from each vertex of that row
        {
            if(graph[i][j]==999)
            graph[i][j]=999;
            else
            graph[i][j]=graph[i][j]-min;
        }
        reduction+=min;
    }
    
    for(int j=0;j<n;j++) //reducing From Column now
    {
        min=9999;
        for(int i=0;i<n;i++) //searching the smallest element in column
        {
            if(graph[i][j]<min)
            min=graph[i][j];
        }
        for(int i=0;i<n;i++) //subtracting the min from each vertex of that column
        {
            if(graph[i][j]==999)
            graph[i][j]=999;
            else
            graph[i][j]=graph[i][j]-min;
        }
        reduction+=min;
    }
    cost=reduction + cost + temp;
}
void travelSalesman(int n,int graph[n][n],int ub,int cost)
{
    for(int i=0;i<n;i++)
    {
        if(graph[x][i]<999);
    }
}
void main()
{
    int n;
    printf("Enter the No. of vertices: ");
    scanf("%d",&n);
    int graph[n][n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the Edge weight from %d vertex : ",i+1);
        for(int j=0;j<n;j++)
        scanf("%d",&graph[i][j]);
    }
    int ub=999;
    int cost;
    reduce_matric(0,0,n,graph,cost); //reducing the graph
    travelSalesman(n,graph,ub,cost);
    for(int i=0;i<n;i++)// printing the soln
    {
        for(int j=0;j<n;j++)
        printf("%d\t",graph[i][j]);
        printf("\n");
    }
}