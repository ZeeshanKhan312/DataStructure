//transitive closure using Floyd Warshall Algorithm
#include<stdio.h>
#define V 4

void printSolution(int reach[][V])
{
	printf ("Following matrix is transitive");
	printf("closure of the given graph\n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			/* because "i==j means same vertex"
			and we can reach same vertex
			from same vertex. So, we print 1....
			and we have not considered this in
			Floyd Warshall Algo. so we need to
			make this true by ourself
			while printing transitive closure.*/
			if(i == j)
				printf("1 ");
			else
				printf ("%d ", reach[i][j]);
		}
		printf("\n");
	}
}

// Prints transitive closure of graph[][]
// using Floyd Warshall algorithm
void transitiveClosure(int graph[][V])
{
	int reach[V][V], i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			reach[i][j] = graph[i][j]; //copying the matrix

	
	for (k = 0; k < V; k++)
	{
		// Pick all vertices as
		// source one by one
		for (i = 0; i < V; i++)
		{
			// Pick all vertices as
			// destination for the
			// above picked source
			for (j = 0; j < V; j++)
			{
				// If vertex k is on a path
				// from i to j,
				// then make sure that the value
				// of reach[i][j] is 1
				reach[i][j] = reach[i][j] ||
				(reach[i][k] && reach[k][j]);
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(reach);
}




int main()
{
	int graph[V][V] = { {1, 1, 0, 1},
						{0, 1, 1, 0},
						{0, 0, 1, 1},
						{0, 0, 0, 1}
					};

	// Print the solution
	transitiveClosure(graph);
	return 0;
}
