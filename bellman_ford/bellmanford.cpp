#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
using namespace std;
 
struct Edge
{
    int src, dest, weight;
};
typedef struct Edge Edge;

struct Graph
{
    int V, E;
    Edge* edge;
};
typedef struct Graph Graph;
 
Graph* graphInit(int V, int E)
{
    Graph* graph = (Graph*) malloc( sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*) malloc( graph->E * sizeof(Edge ) );
    return graph;
}
 
void printSoln(int dist[], int n)
{
    cout<<"\nVertices\tDistance from src\n";
    for (int i = 0; i < n; ++i){
        cout<<i<<"\t\t"<<dist[i]<<"\n";
    }   
}
 
void belman(Graph* graph, int src)
{
    int V = graph->V;
     int E = graph->E;
     int weights[V];

    for (int i = 0; i < V; i++)
        weights[i] = 9999;
 
    weights[src] = 0;

    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
             int v = graph->edge[j].dest;
             int weight = graph->edge[j].weight;
             if (weights[u] + weight < weights[v])
                weights[v] = weights[u] + weight;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
         int v = graph->edge[i].dest;
         int weight = graph->edge[i].weight;
         if (weights[u] + weight < weights[v])
            cout<<"\nThis graph has -ve cycle. Algo doesn't work\n";
    }
     printSoln(weights, V);
     return;
}
 
int main()
{
    int V=4,E=5,S=0;
 

    Graph* graph = graphInit(V, E);

    graph->edge[0].src=0;
    graph->edge[0].dest=1;
    graph->edge[0].weight=3;

    graph->edge[1].src=1;
    graph->edge[1].dest=2;
    graph->edge[1].weight=2;

    graph->edge[2].src=2;
    graph->edge[2].dest=3;
    graph->edge[2].weight=3;

    graph->edge[3].src=3;
    graph->edge[3].dest=0;
    graph->edge[3].weight=1;

    graph->edge[4].src=0;
    graph->edge[4].dest=2;
    graph->edge[4].weight=6;
    
 
    belman(graph, S);
    return 0;
}