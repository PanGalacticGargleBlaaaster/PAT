#include <stdio.h>

int G[1010][1010], visited[1010], n, m, k;

void dfs(int w)
{
    visited[w] = 1;
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i] && G[w][i])
            dfs(i);
    }
}

int main()
{
    int i, j, w, c1, c2, v, cnt;
    scanf("%d %d %d", &n, &m, &k);
    for(i = 0; i < m; i++) {
        scanf("%d %d", &c1, &c2);
        G[c1][c2] = 1;
        G[c2][c1] = 1;
    }
    
    for(i = 0; i < k; i++) {
        scanf("%d", &v);
        for(j = 1; j <= n; j++)
            visited[j] = 0;
        // 可能会有不止一个连通分量， 所以通过dfs来求连通分量的个数
        visited[v] = 1;
        cnt = 0;
        for(w = 1; w <= n; w++) { 
            if(!visited[w]) {
                dfs(w);
                cnt++;
            }
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}