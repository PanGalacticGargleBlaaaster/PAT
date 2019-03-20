#include <stdio.h>
#include <stdlib.h>

int in[30], post[30];
int n, cnt = 0;
typedef struct node lnode;
struct node {
    int data;
    int index;
};
lnode level[30];

int cmp(const void *a, const void *b)
{
    lnode x = *(lnode*)a;
    lnode y = *(lnode*)b;
    return x.index - y.index;
}


void tolevel(int root, int left, int right, int index)
{
    if(left > right) return;
    level[cnt].data = post[root];
    level[cnt].index = index;
    cnt++;
    int i = left;
    while(i < right && in[i] != post[root]) i++;
    tolevel(root-1-right+i, left, i-1, 2*index+1);
    tolevel(root-1, i+1, right, 2*index+2);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    tolevel(n-1, 0, n-1, 0);
    qsort(level, n, sizeof(lnode), cmp);
    for(int i = 0; i < n; i++) {
        if(i != n-1) printf("%d ", level[i].data);
        else printf("%d\n", level[i].data);
    }
    return 0;
}