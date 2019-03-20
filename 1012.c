#include <stdio.h>
#include <stdlib.h>

typedef struct stuNode {
    int Score[4];
    int Rank[4];
    int ID, best;
}stuNode;
stuNode stu[2005];
int index[1000000], flag = -1;

int cmp(const void *a, const void *b)
{
    stuNode x = *(stuNode*)a;
    stuNode y = *(stuNode*)b;
    return x.Score[flag] < y.Score[flag];
}

int main()
{
    int i, j, n, m, id;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++) {
        scanf("%d %d %d %d", &stu[i].ID, &stu[i].Score[1], &stu[i].Score[2], &stu[i].Score[3]);
        stu[i].Score[0] = (stu[i].Score[1]+stu[i].Score[2]+stu[i].Score[3])/3.0 + 0.5;
    }
    for(flag = 0; flag <= 3; flag++) {
        qsort(stu, n, sizeof(stuNode), cmp);
        stu[0].Rank[flag] = 1;
        for(i = 1; i < n; i++) {
            stu[i].Rank[flag] = i+1;
            if(stu[i].Score[flag] == stu[i-1].Score[flag])
                stu[i].Rank[flag] = stu[i-1].Rank[flag];
        }
    }
    for(i = 0; i < n; i++) {
        index[stu[i].ID] = i+1;
        stu[i].best = 0;
        int minn = stu[i].Rank[0];
        for(j = 1; j <= 3; j++) {
            if(stu[i].Rank[j] < minn){
                minn = stu[i].Rank[j];
                stu[i].best = j;
            }
        }
    }
    char c[] = {'A', 'C', 'M', 'E'};
    for(i = 0; i < m; i++) {
        scanf("%d", &id);
        int temp = index[id];
        if(temp) {
            int best = stu[temp-1].best;
            printf("%d %c\n", stu[temp-1].Rank[best], c[best]);
        }
        else printf("N/A\n");
    }
    return 0;
}