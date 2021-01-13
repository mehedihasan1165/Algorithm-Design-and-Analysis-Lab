#include <iostream>
#include <stdlib.h>
#define INF 99999
using namespace std;
struct Edge{
    int startNode;
    int endNode;
    int weight;
};
struct Graph{
    int totalNode;
    int totalEdge;
    struct Edge *edge;
};
void bellmanFord(struct Graph *g, int source);
int main(){
    //input 6 6 0 2 2 0 3 4 2 3 -1 1 2 10 3 4 7 3 5 5
    int n, m, a, b, c;
    cin >> n >> m;
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->totalEdge = m;
    g->totalNode = n;

    g->edge = (struct Edge *)malloc(g->totalEdge * sizeof(struct Edge));
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g->edge[i].startNode = a;
        g->edge[i].endNode = b;
        g->edge[i].weight = c;
    }
    bellmanFord(g, 1);
    return 0;
}
void bellmanFord(struct Graph *g, int source){
    int tNode = g->totalNode;
    int tEdge = g->totalEdge;
    int dist[tNode];
    for (int i = 0; i < tNode; i++){
        dist[i] = INF;
    }
    dist[source] = 0;
    for (int i = 1; i < tNode - 1; i++){
        for (int j = 0; j < tEdge; j++){
            int u = g->edge[j].startNode;
            int v = g->edge[j].endNode;
            int w = g->edge[j].weight;
            if (dist[u] != INF && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < tNode; i++){
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    }
}
