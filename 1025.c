#include <stdio.h>
#include <stdlib.h>

struct user {
    long long id;
    int place;
    int score;
    int localrank;
}user[30000];

int cmp(const void *a, const void *b)
{
    struct user x = *(struct user*)a;
    struct user y = *(struct user*)b;
    int ret;
    if(x.score!=y.score) ret = y.score - x.score;
    else ret = (x.id - y.id > 0) ? 1 : -1;
    return ret;
}

int main()
{
    int n, k, start, cnt = 0, place = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        start = cnt;
        for(int j = 0; j < k; j++) {
            scanf("%lld %d", &user[cnt].id, &user[cnt].score);
            user[cnt].place = place;
            cnt++;
        }
        qsort(&user[start], k, sizeof(struct user), cmp);
        int rank = 1, temp = 1;
        for(int l = start; l < start+k; l++) {
            if(l!=start && user[l].score == user[l-1].score) {
                user[l].localrank = temp;
                rank++;
            }
            else {
                user[l].localrank = rank;
                temp = rank;
                rank++;
            }
        }
        place++;
    }
    qsort(user, cnt, sizeof(struct user), cmp);
    printf("%d\n", cnt);
    int rank = 1;
    for(int i = 0; i < cnt; i++) {
        if(i != 0 && user[i].score == user[i-1].score)
            printf("%013lld %d %d %d\n", user[i].id, rank, user[i].place, user[i].localrank);
        else {
            rank = i+1;
            printf("%013lld %d %d %d\n", user[i].id, rank, user[i].place, user[i].localrank);
        }
    }
    return 0;
}