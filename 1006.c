#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, hh, mm, ss, ftime, ltime, mintime, maxtime;
    char id[16] = "0";
    char fid[16] = "0";
    char lid[16] = "0";
    scanf("%d", &n);

    mintime = 10000000;
    maxtime = -1;
    for(i = 0; i < n; i++) {
        scanf("%s %d:%d:%d", &id, &hh, &mm, &ss);
        ftime = hh*10000+mm*100+ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        ltime = hh*10000+mm*100+ss;
        if(mintime > ftime) {
            strcpy(fid, id);
            mintime = ftime;
        }
        if(maxtime < ltime) {
            strcpy(lid, id);
            maxtime = ltime;
        }
    }
    printf("%s %s\n", fid, lid);
}