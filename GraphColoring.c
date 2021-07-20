#include<stdio.h>
#include<stdlib.h>
#define c 5
struct Edge {  // a structure to represent a weighted edge in graph
	int start, dest;
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
	graph->edge = malloc(sizeof(struct Edge));
	return graph;
}
int safecolor(int v,int j,int col[],struct Graph* graph,int e)
{
	for(int i=0;i<e;i++) //for finding all the neighbour vertices
	{
		if(graph->edge[i].start==v)
		{
			int dest=graph->edge[i].dest;
			if(col[dest]==j) //check whether the vertex has been given a color or not
			{
			 return 0;
			}
		}
	}
	return 1;
}
void GraphCol(int v,int n,int col[],struct Graph* graph,int e)
{
	for(int j=1;j<=c;j++)//giving the colour to the vertices
	{
	if(safecolor(v,j,col,graph,e)) //checking if the colour is safe or not
	{
		col[v]=j;
	}
	else{  //if colour is not safe 
		if(j==c) //if it's the last colour and U can't check more
		return ;
		else{
		col[v]=-1;
		continue; //will skip the remaining part of this loop and will start from the next 'j'
		}
	}	
	if(v==n-1) //if it's the last vertex which means all the vertex has een given colour
	return ;
	GraphCol(v+1,n,col,graph,e); //calling it again to give the next vertex a colour 
	if(col[v+1]!=-1)
	return ;
	else 
	continue;
	}
	if(col[v]==-1) //if no colour is found
		printf("No colour found ");
	
}
void main()
{
    int n,e;
    printf("Enter the No. of vertices and Edges : ");
    scanf("%d %d",&n,&e);
	e=2*e; //bcuz of undirected graph so it will point both sides
    struct Graph* graph = createGraph(n, e);//Creating the graph
    int col[n];
	for(int i=0;i<e;i++)
	{
		int start, dest;
		printf("Enter the Starting point and Destination:");
		scanf("%d %d", &start, &dest);
		graph->edge[i].start = start;
		graph->edge[i].dest = dest;
		i++;
		graph->edge[i].start = dest; //giving an edge from dest. to start bcuz it's undirected graph
		graph->edge[i].dest = start;
	}
    GraphCol(0,n,col,graph,e);
	if(col[n-1]!=-1)
	{
	for(int i=0;i<n;i++) //printing the solution
	{
		printf("Vertex %d---->Color %d\n",i,col[i]);
	}
	}
}