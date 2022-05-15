#include <iostream>
using namespace std;
#include <limits.h>

#define V 6

void print(int dist[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

int mindist(int dist[], bool shortest_path[])
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (shortest_path[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void dijkstra(int G[V][V], int src)
{
	int dist[V];
	bool shortest_path[V];
	for (int i = 0; i < V; i++)
		dist[i] = 9999, shortest_path[i] = false;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = mindist(dist, shortest_path);
		shortest_path[u] = true;

		for (int v = 0; v < V; v++)
			if (!shortest_path[v] && G[u][v] && dist[u] != INT_MAX && dist[u] + G[u][v] < dist[v])
				dist[v] = dist[u] + G[u][v];
	}

	print(dist);
}

int main()
{

  int G[V][V]=
  {
  	{0,3,1,2,4,5},
  	{3,0,6,1,2,1},
  	{1,6,0,2,7,4},
  	{2,1,2,0,2,3},
  	{4,2,7,2,0,6},
  	{5,1,4,3,6,0}
  };

	dijkstra(G, 0); // 0 to be the start point

	return 0;
}
