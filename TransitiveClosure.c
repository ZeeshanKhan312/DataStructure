<<<<<<< HEAD
//transitive closure using Floyd Warshall Algorithm
#include<stdio.h>
#define V 4

void printSolution(int reach[][V])
{
	printf ("Following matrix is transitive");
	printf("closure of the given graph\n");
=======
//Transitive closure using Floyd Warshall Algorithm
#include<stdio.h>
#define V 4
void printSolution(int reach[][V])
{
	printf ("Following matrix is transitive closure of the given graph\n");
>>>>>>> temporary
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
<<<<<<< HEAD
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
=======
>>>>>>> temporary
				printf ("%d ", reach[i][j]);
		}
		printf("\n");
	}
}
<<<<<<< HEAD

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
=======
void transitiveClosure(int graph[][V])  // using Floyd Warshall algorithm
{
	int reach[V][V], i, j, k;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			reach[i][j] = graph[i][j]; //copying the matrix
	// Checking whether there is a path K on path of  i & j 
	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)    //selecting all vertices as source one by 
		{
			for (j = 0; j < V; j++)  //selecting all vertices as destination one by one
			{
				if(i==j)    //if it's same vertex then it can be visited
				reach[i][j]=1;
				else        // If vertex k is on a path  from i to j
				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
			}
		}
	}
	printSolution(reach);
}

int main()
{
	int graph[V][V] = { {1, 1, 0, 0},
                        {0, 0, 1, 0},
                        {0, 0, 1, 1},
                        {1, 0, 0, 1}
                      };
	transitiveClosure(graph);
	return 0;
}
>>>>>>> temporary
