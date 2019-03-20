#include <stdio.h>
#include <stdlib.h>

#define inf 65535
int g[500][500], weight[500][500], dis[500], cost[500], path[500];
int n, m, s, d;

int findmindist(int collected[])
{
    int minv, v;
    int mindis = inf;

    for(v = 0; v < n; v++) {
        if(collected[v]==0 && dis[v] < mindis) {
            mindis = dis[v];
            minv = v;
        }
    }
    if(mindis < inf) return minv;
    else return -1;
}

void dijkstra(int s)
{
    int collected[n];
    int v, w;
    
    for(v = 0; v < n; v++) {
        dis[v] = g[s][v];
        cost[v] = weight[s][v];
        if(dis[v] < inf) path[v] = s;
        else path[v] = -1;
        collected[v] = 0;
    }

    dis[s] = 0;
    collected[s] = 1;

    while(1) {
        v = findmindist(collected);
        if(v == -1) break;
        collected[v] = 1;
        for(w = 0; w < n; w++) {
            if(collected[w]==0 && g[v][w] < inf) {
                if(dis[v] + g[v][w] < dis[w]) {
                    dis[w] = dis[v] + g[v][w];
                    path[w] = v;
                    cost[w] = cost[v] + weight[v][w];
                }
                else if(dis[v] + g[v][w] == dis[w]) {
                    if(cost[v] + weight[v][w] < cost[w]) {
                        dis[w] = dis[v] + g[v][w];
                        path[w] = v;
                        cost[w] = cost[v] + weight[v][w];
                    }
                }
            }
        }
    } 
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            g[i][j] = inf;
            weight[i][j] = inf;
        }
    }
    for(int i = 0; i < m; i++) {
        int v, w, dis, cost;
        scanf("%d %d %d %d", &v, &w, &dis, &cost);
        g[v][w] = g[w][v] = dis;
        weight[v][w] = weight[w][v] = cost;
    }
    dijkstra(s);
    int tempath[n], cnt = 0;
    for(int v = d; v != -1; v = path[v])
        tempath[cnt++] = v;
    // int tempcnt = cnt;
    for(int i = cnt-1; i >= 0; i--)
        printf("%d ", tempath[i]);
    printf("%d %d\n", dis[d], cost[d]);
    return 0;
}