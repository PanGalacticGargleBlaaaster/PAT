#include <stdio.h>

int main()
{
    int i, n, t;
    scanf("%d", &n);
    int e[n+1];
    e[0] = 0;
    t = 0;
    for(i = 1; i <= n; i++) {
        scanf("%d", &e[i]);
        if(e[i] > e[i-1]) t += (e[i]-e[i-1])*6;
        else if(e[i] < e[i-1]) t += (e[i-1]-e[i])*4;
        t += 5;
    }
    printf("%d", t);
}