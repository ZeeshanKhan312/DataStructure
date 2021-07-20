//Hamiltonian Cycle -->to find a path that visit each vertex exactly one there's an edge from the last vertex to source thus forming a cycle
#include<stdio.h>
#include<stdbool.h>

bool isSafe(int V,int v, int graph[V][V], int path[], int pos)
{

	if (graph [ path[pos-1] ][ v ] == 0) //to check whether this vertex is connected to prvs vertex
		return false;
	for (int i = 0; i < pos; i++) //checking whether this vertex is already been visited 
		if (path[i] == v) 
			return false;

	return true;
}

int hamCycle(int V,int graph[V][V], int path[], int pos,int cycle[])
{
	if (pos == V)
	{
		if ( graph[ path[pos-1] ][ path[0] ] == 1 )//to check whether last vertex is connected to 1st vertex to complete the cycle
		{
		    for (int i = 0; i < V; i++)
	      	printf(" %d ", path[i]);  	
    	printf(" %d\n", path[0]); // Printing the first vertex again to show the complete cycle
		cycle[0]++;
		return 1;
		}
		 else //if no Cycle is present 
		   return 0;
	}
	for (int v = 1; v < V; v++)
	{
		if (isSafe(V,v, graph, path, pos)) // Check if this vertex can be added to Hamiltonian Cycle 
		{
			path[pos] = v;
			if (hamCycle(V,graph, path, pos+1,cycle) == true) // recall to construct rest of the path 
			{
			    path[pos] = -1; //removing the last vertex after printing 1 cycle set in order to chechk for more
			}
		}
	}
}

int main()
{
	int V;
	printf("Enter the No. of Vertices :");
	scanf("%d",&V);
    int graph[V][V];
	
	for(int i=0;i<V;i++)
	{
		printf("Enter the Vertices of %d : ",i+1);
		for(int j=0;j<V;j++)
		{
		int x;
		scanf("%d",&x);
		graph[i][j]=x;
		}
	}
	int cycle[1]={0};
    int path[V];
    path[0] = 0;
    hamCycle(V,graph, path, 1,cycle); //calling the function   
	if(cycle[0]==0) //if no cycle is found
		printf("\nNo Solution found");
	return 0;
}