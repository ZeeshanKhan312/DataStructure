//Articulation Point in Graph
//A point/vertices  removing it will disconnect the Graph and divie it into two
#include<stdio.h>
#include<stdbool.h>
struct Edge{
    int start;
    int dest;
};
struct Graph{
    int V,E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = malloc(sizeof(struct Edge));
	return graph;
}

void Graph APUtil(int u, bool visited[], int disc[],
                                      int low[], int parent[], bool ap[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Count of children in DFS Tree
    int children = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // u is an articulation point in following cases
 
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1)
               ap[u] = true;
 
            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
void AP(int V)
{
    bool *visited[V];
    int *disc[V];
    int *low[V];
    int *parent[V];
    bool *ap[V]; // To store articulation points
 
    // Initialize parent and visited, and ap(articulation point) arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NULL;
        visited[i] = false;
        ap[i] = false;
    }
    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
 
    // Now ap[] contains articulation points, print them
    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            printf("%d ",i);
}
void main()
{
    int v,e;
    printf("Enter the nuber of Vertices and Edges:");
    scanf("%d %d",&v,&e);
    struct Graph* graph=creategraph(v,e);
    for(int i=0;i<e;i++)
    {
        printf("Enter the source and destination:");
        scanf("%d %d",&graph->edge[i].start,&graph->edge[i].dest);
    }
    AP(v);
}