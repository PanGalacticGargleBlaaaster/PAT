#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 500
#define INFINITY 65535
typedef int Vertex;
typedef int WeightType;

typedef struct ENode * PtrToENode;
struct ENode{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode * PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    int Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph create_graph(int vertexnum);
MGraph build_graph(int nv, int ne);
void insert_edge(MGraph Graph, Edge E);
void Dijkstra(MGraph Graph, Vertex s, Vertex d);
Vertex find_mindist(MGraph Graph, int dist[], int collected[]);

int main()
{
    int nv, ne;
    Vertex c1, c2;
    scanf("%d %d %d %d", &nv, &ne, &c1, &c2);

    MGraph Graph = build_graph(nv, ne);
    Dijkstra(Graph, c1, c2);
    
}

MGraph create_graph(int vertexnum)
{
    Vertex v, w;
    MGraph Graph;
    
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = vertexnum;
    Graph->Ne = 0;
    for(v = 0; v < Graph->Nv; v++) {
        Graph->Data[v] = 0;
        for(w = 0; w < Graph->Nv; w++)
            Graph->G[v][w] = INFINITY;
    }
        
    return Graph;
}

MGraph build_graph(int nv, int ne)
{
    MGraph Graph;
    Edge E;
    Vertex v;
    int i;
    Graph = create_graph(nv);
    Graph->Ne = ne;

    for(v = 0; v < nv; v++)
        scanf("%d", &(Graph->Data[v]));

    if(ne!=0) {
        E = (Edge)malloc(sizeof(struct ENode));
        for(i = 0; i < ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            insert_edge(Graph, E);
        }
    }
    return Graph;
}

void insert_edge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

void Dijkstra(MGraph Graph, Vertex s, Vertex d)
{
    int collected[Graph->Nv], dist[Graph->Nv], path[Graph->Nv], num[Graph->Nv], ways[Graph->Nv];
    Vertex v, w;
    for(v=0; v<Graph->Nv; v++) {
        dist[v] = Graph->G[s][v];
        if(dist[v] < INFINITY) {
            path[v] = s;
            num[v] = Graph->Data[s] + Graph->Data[v];
            ways[v] = 1;
        }
        else {
            path[v] = -1;
            ways[v] = 0;
        }
        collected[v] = 0;
    }

    dist[s] = 0;
    collected[s] = 1;
    num[s] = Graph->Data[s];
    ways[s] = 1;
    while(1){
        v = find_mindist(Graph, dist, collected);
        if(v ==  -1) break;
        collected[v] = 1;
        for(w=0; w<Graph->Nv; w++) {
            if(collected[w] == 0 && Graph->G[v][w]<INFINITY) {
                if(Graph->G[v][w]<0) return;
                if(dist[v]+Graph->G[v][w] < dist[w]) {
                    dist[w]=dist[v]+Graph->G[v][w];
                    path[w]=v;
                    num[w] = num[v]+ Graph->Data[w];
                    ways[w] = ways[v];
                }
                else if(dist[v]+Graph->G[v][w] == dist[w]) {
                    ways[w] = ways[w] + ways[v];
                    if(num[w] < num[v]+ Graph->Data[v]) {
                        dist[w]=dist[v]+Graph->G[v][w];
                        path[w]=v;
                        num[w] = num[v]+ Graph->Data[w];
                    }
                }
            }
        }
    }
    printf("%d %d\n", ways[d], num[d]);
    return;
}

Vertex find_mindist(MGraph Graph, int dist[], int collected[])
{
    Vertex Minv, v;
    int MinDist = INFINITY;
    for(v = 0; v < Graph->Nv; v++) {
        if(collected[v]==0 && dist[v] < MinDist) {
            MinDist = dist[v];
            Minv = v;
        }
    }
    if(MinDist < INFINITY) return Minv;
    else return -1;
}