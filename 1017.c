#include <stdio.h>
#include <stdlib.h>

#define start 28800
#define end   61200

typedef struct cusNode custom;
struct cusNode {
    int arrive;
    int ptime;
};
custom cus[10000];

int cmp(const void *a, const void *b)
{
    custom x = *(custom*)a;
    custom y = *(custom*)b;
    return x.arrive - y.arrive;
}

int main()
{
    int i, j, n, k, hh, mm, ss, ptime, cnt = 0;
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &ptime);
        if(hh*3600+mm*60+ss > end) continue;
        cus[cnt].arrive = hh*3600+mm*60+ss;
        cus[cnt].ptime = ptime*60;
        cnt++;
    }
    qsort(cus, cnt, sizeof(custom), cmp);
    int win[k];
    for(i = 0; i < k; i++)
        win[i] = start;
    double awt = 0.0;
    for(i = 0; i < cnt; i++) {
        int minwin = 0, mintime = win[0];
        for(j = 0; j < k; j++) {
            if(mintime > win[j]) {
                mintime = win[j];
                minwin = j;
            }
        }
        if(cus[i].arrive >= win[minwin]) {
            win[minwin] = cus[i].arrive + cus[i].ptime;
        }
        else {
            awt += (win[minwin] - cus[i].arrive);
            win[minwin] += cus[i].ptime;
        }
        
    }
    printf("%.1f",  awt/cnt/60.0);
    return 0;
}