
#include<iostream>
#include <stdio.h>
#include <limits.h>
 using namespace std;
int V;

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j]==-1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void printSolution(int dist[], int n, int parent[])
{
    int src = 0;
    printf("Vertex\t  Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}

void dijkstra(int graph[][10], int src)
{
    int dist[V];
    bool sptSet[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printSolution(dist, V, parent);
}

int main()
{
	int c;
	cout<<"\n Enter the number of vertices: ";
	cin>>V;
	cout<<"\n Enter the adjacency matrix: \n";
	int graph[10][10];
	for( int i = 0; i < V; i++)
	{
		for( int j = 0; j < V; j++ )
		{
			cin>>graph[i][j];
		}
	}
	cout<<"\n Enter the source node: ";
	cin>>c;
	cout<<"\n";
    dijkstra(graph, c);
return 0;
}
