#include<stdio.h>
#include<stdbool.h>
#define INT_MAX 9999
#define V 5
int weight[V][V];
int min(int dist[],bool set[])
{
	int min=INT_MAX, min_Index;
	for(int z=0;z<V;z++)
	{
		if(set[z]==false && dist[z]<min)
		{
			min=dist[z];
			min_Index=z;
		}
	}
	return min_Index;

}
void printArr(int dist[])// to print the solution
{
	printf("Vertex Distance from Source:\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(int src )
{
	int dist[V];
	bool  set[V];
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		set[i]= false;
	}
	dist[src] = 0;
	for (int i = 0; i < V-1; i++)
	{
		int u=min(dist,set);
		set[u]=true;
		for (int j = 0; j < V; j++)
		{
			if(set[j]!=true && weight[u][j]!=0 && dist[u] + weight[u][j] < dist[j])
				dist[j] = weight[u][j] + dist[u];
		}
	}
	printArr(dist);
}
void main()
{
	int  E;
	printf("Enter the No. of Edges: ");
	scanf("%d", &E);
	int ver[V];
	for (int i = 0; i < E; i++)
	{
		int start, dest;
		printf("Enter the source and dest.of the edge : ");
		scanf("%d %d", &start, &dest);
		printf("Enter the weight of Edge: ");
		scanf("%d", &weight[start][dest]);
	}
	int src;
	printf("Enter the Source: ");
	scanf("%d", &src);
	dijkstra(src);
}
