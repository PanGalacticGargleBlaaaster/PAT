#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct recordNode record;
struct recordNode {
    char Name[21];
    int mth, dd, hh, mm, total;
    int status;
};
record r[1000];

// typedef struct cusNode custom;
// struct custom {
//     char Name[21];
//     int mth0, dd0, hh0, mm0;
//     int time, cost;
// };

int rate[24];
// char on[] = 

int cmp_name(const void*a, const void*b)
{
    record x = *(record*)a;
    record y = *(record*)b;
    int ret = strcmp(x.Name, y.Name);
    if(ret == 0) ret = x.total- y.total;
    return ret;
    
}

// int costbytime(int time)
// {
//     int hh = time%(60*24)/60;
//     int mm = time%(60*24)%60;
//     int i, cost = 0;
//     for(i = 0; i < hh; i++)
//         cost += rate[i%24]*60;
//     cost += rate[i%24]*mm;
//     return cost;
// }

double countcost(int start, int end)
{
    int hh = start%(60*24)/60;
    int mm = start%(60*24)%60;
    int time = end - start;
    double cost;
    if(time + mm >= 60) {
        cost = (60 - mm)*rate[hh++];
        for(time = time - (60-mm); time > 60; time -= 60) {
            cost += rate[hh%24]*60;
            hh++;
        }
        cost += rate[hh%24]*time;
    }
    else cost = time*rate[hh];
    return cost /= 100.0;
    // return (double)(costbytime(end) - costbytime(start))/100;
}

int main()
{
    int i, n;
    char status[10] = {'\0'}, name[21] = {'\0'};
    for(i = 0; i < 24; i++)
        scanf("%d", &rate[i]);

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%s %d:%d:%d:%d %s", &r[i].Name, &r[i].mth, &r[i].dd, &r[i].hh, &r[i].mm, &status);
        r[i].total = r[i].mm + r[i].hh*60 + r[i].dd*60*24;
        if(strcmp(status, "on-line")==0) r[i].status = 1;
        else r[i].status = -1;
    }
    
    qsort(r, n, sizeof(record), cmp_name);
   

    int time;
    double amount = 0, cost;
    // strcpy(name, r[0].Name);
    for(i = 0; i <= n; i++) {
        // if(amount&&i&&(strcmp(name, r[i].Name)||i==n-1)) printf("Total amount: $%.2f\n", amount);
        if(strcmp(name, r[i].Name)) {
            strcpy(name, r[i].Name);
            if(amount) printf("Total amount: $%.2f\n", amount);
            amount = 0;

        }
        // else {
        //     if(r[i].status == 1) {
        //         laststatus = 1;
        //         lastotal = r[i].total;
        //     }
        else if(r[i].status == -1 && r[i-1].status == 1) {
            if(!amount) printf("%s %02d\n", r[i].Name, r[i].mth);
            time = r[i].total - r[i-1].total;
            cost = countcost(r[i-1].total, r[i].total);
            amount = amount + cost;
            
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", 
            r[i-1].dd, r[i-1].hh, r[i-1].mm, r[i].dd, r[i].hh, r[i].mm, time, cost);
            // if(strcmp(r[i+1].Name, r[i].Name) != 0) 
        }
        // }
    }
    return 0;
}