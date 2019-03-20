#include <stdio.h>
#include <stdlib.h>

// typedef struct tNode * table;
struct tNode{
    int next;
    int isvip;
    int servcnt;
}table[110];

struct cNode{
    int arrive;
    int play;
    int serv;
    int isvip;
}cus[10010];

int n, k, m;

int cmp1(const void *a, const void *b)
{
    struct cNode x = *(struct cNode*)a;
    struct cNode y = *(struct cNode*)b;
    return x.arrive - y.arrive;
}

int cmp2(const void *a, const void *b)
{
    struct cNode x = *(struct cNode*)a;
    struct cNode y = *(struct cNode*)b;
    // if(x.serv != y.serv) 
    return x.serv - y.serv;
    // else return x.arrive - y.arrive;
}


// int findtable(int *flag, int *vipt, int ci)
// {
//     int mintime, mintable = 101;
//     mintime = 24*3600;
//     *vipt = 0;
//     *flag = 0;
//     for(int i = 1; i <= k; i++) {
//         if(cus[ci].arrive >= table[i].next) {
//             if(mintable > i) {
//                 mintable = i;
//                 *flag = 1;
//             }
//             if(table[i].isvip) *vipt = i;
//         }
//     }
//     if(*flag == 0) {
//         for(int i = 1; i <= k; i++) {
//             if(mintime > table[i].next && flag == 0) {
//                 mintable = i;
//                 mintime = table[i].next;
//                 if(table[i].isvip) *vipt = i;
//                 else *vipt = 0;
//             }
//             if(mintime == table[i].next && table[i].isvip)
//                 if(*vipt==0)
//                     *vipt = i;
//         }
//     }
//     return mintable;
// }

// int findvip(int i, int t)
// {
//     int vip = -1;
//     for(int j = i; j < n; j++) {
//         if(cus[j].isvip&&!cus[j].serv&&cus[j].arrive<=table[t].next)
//             vip = j;
//     }
//     return vip;
// }

void alloctable(int cusid, int tableid)
{
    if(cus[cusid].arrive <= table[tableid].next)
        cus[cusid].serv = table[tableid].next;
    else cus[cusid].serv = cus[cusid].arrive;
    table[tableid].next = cus[cusid].arrive + cus[cusid].play;
    table[tableid].servcnt++;
}

int findnextvip(int vip)
{
    vip++;
    while(vip < n && cus[vip].isvip == 0) vip++;
    return vip;
}

int main()
{
    scanf("%d", &n);
    int cusn = 0;
    for(int i = 0; i < n; i++) {
        int hh, mm, ss, temp, play, isvip;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &play, &isvip);
        temp = hh*3600 + mm*60 + ss;
        if(temp >= 21*3600) continue;
        cus[cusn].isvip = isvip;
        cus[cusn].arrive = temp;
        cus[cusn].serv = 21 * 3600;
        cus[cusn].play = play * 60;
        if(cus[cusn].play > 7200) cus[cusn].play = 7200;
        cusn++;
    }
    n = cusn;
    scanf("%d %d", &k, &m);
    for(int i = 1; i <=k; i++) {
        table[i].next = 8*3600;
    }
    for(int i = 0; i < m; i++) {
        int vip;
        scanf("%d", &vip);
        table[vip].isvip = 1;
    }
    qsort(cus, n, sizeof(struct cNode), cmp1);
    int i = 0, vip = -1;
    vip = findnextvip(vip);
    while(i < n) {
        int index = -1, minextime = 999999999;
        for(int j = 1; j <= k; j++) {
            if(table[j].next < minextime) {
                minextime = table[j].next;
                index = j;
            }
        }
        if(table[index].next >= 21*3600) break;
        if(cus[i].isvip && i < vip) { // 检查vip是否已被处理过
            i++;
            continue;
        }
        if(table[index].isvip) {
            if(cus[i].isvip) {
                alloctable(i, index);
                if(vip == i) vip = findnextvip(vip);
                i++;
            }
            else {
                if(vip < n && cus[vip].arrive <= table[index].next) {
                    alloctable(vip, index);
                    vip = findnextvip(vip);
                }
                else {
                    alloctable(i, index);
                    i++;
                }
            }
        }
        else {
            if(cus[i].isvip==0) {
                alloctable(i, index);
                i++;
            }
            else {
                // if(vip < n && cus[vip].arrive <=table[index].next) {
                //     alloctable(vip, index);
                //     vip = findnextvip(vip);
                // }
                
                int vipindex = -1, minvipnextime = 999999999;
                for(int j = 1; j <= k; j++) {
                    if(table[j].isvip && table[j].next < minvipnextime) {
                        minvipnextime = table[j].next;
                        vipindex = j;
                    }
                }
                if(vipindex != -1 && cus[i].arrive >= table[vipindex].next) {
                    alloctable(i, vipindex);
                    if(vip == i) vip = findnextvip(vip);
                    i++;
                }
                else {
                    alloctable(i, index);
                    if(vip == i) vip = findnextvip(vip);
                    i++;
                }
            }
        }
    }
    // while(cnt < n) {
    //     int t, vipt, vip, flag;
    //     while(cus[i].serv!=0) i++;
    //     t = findtable(&flag, &vipt, i);
    //     if(table[t].next >= 21*3600) break;
    //     if(flag == 1) {
    //         if(cus[i].isvip) {
    //             cus[i].serv = table[vipt].next>cus[i].arrive?table[vipt].next:cus[i].arrive;
    //             table[vipt].next = cus[i].serv + cus[i].play*60;
    //             table[vipt].servcnt++;
    //             cnt++;
    //         }
    //         else {
    //             cus[i].serv = table[t].next>cus[i].arrive?table[t].next:cus[i].arrive;
    //             table[t].next = cus[i].serv + cus[i].play*60;
    //             table[t].servcnt++;
    //             cnt++; i++;
    //         }
    //     }
    //     else{
    //         if(vipt) vip = findvip(i, vipt);
    //         if(vipt && vip!=-1) {
    //             cus[vip].serv = table[vipt].next>cus[vip].arrive?table[vipt].next:cus[vip].arrive;
    //             table[vipt].next = cus[vip].serv + cus[vip].play*60;
    //             table[vipt].servcnt++;
    //             cnt++;
    //         }
    //         else {
    //             cus[i].serv = table[t].next>cus[i].arrive?table[t].next:cus[i].arrive;
    //             table[t].next = cus[i].serv + cus[i].play*60;
    //             table[t].servcnt++;
    //             cnt++; i++;
    //         }
    //     }
    // }
    qsort(cus, n, sizeof(struct cNode), cmp2);
    for(int i = 0; i < n && cus[i].serv < 21*3600; i++) {
        int h0, m0, s0, h1, m1, s1, arrive, serv;
        double wait;
        arrive = cus[i].arrive; serv = cus[i].serv;
        wait = (serv - arrive) / 60.0;
        h0 = arrive/3600; arrive %= 3600;
        m0 = arrive/60; arrive %= 60;
        s0 = arrive;
        h1 = serv/3600; serv %= 3600;
        m1 = serv/60; serv %= 60;
        s1 = serv;
        printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n", 
        h0, m0, s0, h1, m1, s1, wait);
    }
    for(int i = 1; i <= k; i++) {
        if(i!=k) printf("%d ", table[i].servcnt);
        else printf("%d\n", table[i].servcnt);
    }
    return 0;
}