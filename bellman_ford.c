// shortest path algorithm.
#include <stdio.h>
#include<stdlib.h>
#define INT_MAX 999
struct Edge {  // a structure to represent a weighted edge in graph
	int start, dest, weight;
};
struct Graph {
	int V, E;  // V-> Number of vertices, E-> Number of edges
	struct Edge* edge;  // graph is represented as an array of edges.
};
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*)malloc(sizeof(struct Edge));
	return graph;
}
void printArr(int dist[], int V)// to print the solution
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}
void BellmanFord(struct Graph* graph, int start)//the main code
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	// Step 1: Initialize distances from start to all other vertices as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[start] = 0;
	// Step 2: Relax all edges |V| - 1 times.
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].start;
			printf("%d %d ",u,dist[u]);
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
		printArr(dist, V);
	}

	/* Step 3: check for negative-weight cycles. The above step guarantees shortest distances if graph doesn't contain
    negative weight cycle. If we get a shorter path, then there is a -ve cycle.*/
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].start;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return; // If negative cycle is detected, simply return
		}
	}	
	printArr(dist, V);
	return;
}

// Driver program to test above functions
int main()
{
	int V,E ;
	printf("Enter the number of vertices and Edges:");
	scanf("%d %d", &V,&E);
	struct Graph* graph = createGraph(V, E);//Creating the graph
	for(int i=0;i<E;i++)
	{
		int start, dest, weight;
		printf("Enter the Starting point and Destination:");
		scanf("%d %d", &start, &dest);
		printf("Enter the weight of edge:");
		scanf("%d", &weight);
		graph->edge[i].start = start;
		graph->edge[i].dest = dest;
		graph->edge[i].weight = weight;
	}
	int src;
	printf("Enter the Source: ");
	scanf("%d",&src);
	BellmanFord(graph, src);
	return 0;
}
