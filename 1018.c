#include <stdio.h>
#include <stdlib.h>

#define MAX 510
#define INF 65535

struct path {
    int size;
    int vp[MAX];
}path[MAX];
int g[MAX][MAX], data[MAX], visited[MAX], dist[MAX];
int stack[MAX], top = 0;
int anspath[MAX], x = 0;
int cmax, n, m, sp;
int minsend = INF, minback = INF;

void Dfs(int v)
{
    stack[top++] = v;
    if(v == 0) {
        int send = 0, back = 0;
        for(int i = top-2; i >= 0; i--) {
            int id = stack[i];
            if(data[id] > 0) {
                back += data[id];
            }
            else {
                if(back > (-data[id])) {
                    back += data[id];
                }
                else {
                    send += (-data[id] - back);
                    back = 0;
                }
            }
        }
        if(send < minsend || (send == minsend && back < minback)) {
            minsend = send;
            minback = back;
            x = 0;
            for(int i = top-1; i >= 0; i--)
                anspath[x++] = stack[i];
        }
        return;
    }
    for(int i = 0; i < path[v].size; i++) {
        Dfs(path[v].vp[i]);
        top--;
    }
}

int main()
{
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    // 读入节点数据
    for(int i = 1; i <= n; i++) {
        scanf("%d", &data[i]);
        data[i] = data[i] - cmax/2;
    }
    // 初始化图
    for(int i = 0; i <= n; i++) {
        visited[i] = 0;
        for(int j = 0; j <= n; j++) {
            g[i][j] = INF;
        }
    }
    // 读入边
    for(int i = 0; i < m; i++) {
        int x, y, weight;
        scanf("%d %d", &x, &y);
        scanf("%d", &weight);
        g[x][y] = g[y][x] = weight;
    }
    // 初始化path
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            path[i].vp[j] = -1;
    // 初始化diat和路径
    for(int i = 0; i <= n; i++) {
        dist[i] = g[0][i];
        if(i != 0 && g[0][i] < INF)
            path[i].vp[path[i].size++] = 0;
    }
    // dijkstra找到多条路径
    visited[0] = 1;
    int min, v, w;
    for(int i = 1; i <= n; i++) {
        min = INF;
        for(int j = 0; j <= n; j++) {
            if(visited[j] == 0 && dist[j] < min) {
                min = dist[j];
                v = j;
            }
        }
        visited[v] = 1;
        for(w = 0; w <= n; w++) {
            if(visited[w] == 0 && g[v][w] < INF) {
                if(dist[w] > dist[v] + g[v][w]) {
                    dist[w] = dist[v] + g[v][w];
                    path[w].vp[0] = v;
                    path[w].size = 1;
                }
                else if(dist[w] == dist[v] + g[v][w])
                    path[w].vp[path[w].size++] = v;
            }
        }
    }
    Dfs(sp);
    printf("%d ", minsend);
    for(int i = 0; i < x-1; i++)
        printf("%d->", anspath[i]);
    printf("%d %d", sp, minback);

    return 0;
}