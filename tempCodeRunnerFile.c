#include<stdio.h>
void main()
{
    int V,i,j;
    scanf("%d",&V);
      int arr[V][V];
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("Enter the vertices weight going from vertex %d to %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
    printf("Adjacency matrices of cost of edges\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    int root;
    printf("Enter the root: ");
    scanf("%d", &root);

    //bfs()
}