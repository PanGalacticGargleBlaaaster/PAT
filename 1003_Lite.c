#include <stdio.h>

#define INF 65535
int n, m, c1, c2;
int e[500][500], weight[500], dis[500], num[500], w[500], visited[500];

int main()
{
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
        dis[i] = INF;
        visited[i] = 0;
        for(int j = 0; j < n; j++)
            e[i][j] = INF;
    }
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 1;
    w[c1] = weight[c1];
    num[c1] = 1;
    while(1) {
        int Minv = -1, Mindata = INF;
        for(int i = 0; i < n; i++) {
            if(visited[i] == 0 && dis[i] < Mindata) {
                Minv = i;
                Mindata = dis[i];
            }
        }
        if(Minv == -1) break;
        visited[Minv] = 1;
        for(int v = 0; v < n; v++) {
            if(visited[v] == 0 && e[Minv][v] != INF) {
                if(dis[Minv] + e[Minv][v] < dis[v]) {
                    dis[v] = dis[Minv] + e[Minv][v];
                    num[v] = num[Minv];
                    w[v] = w[Minv] + weight[v];
                }
                else if(dis[Minv] + e[Minv][v] == dis[v]) {
                    num[v] += num[Minv];
                    if(w[v] < w[Minv] + weight[v]) {
                        w[v] = w[Minv] + weight[v];
                    }
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}