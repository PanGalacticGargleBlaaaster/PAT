#include <stdio.h>
#include <stdlib.h>

#define base 39

long long decimal(char n[], long long radix)
{
    long long i, num, ret = 0;
    for(i = 0; n[i]!='\0'; i++) {
        if(n[i]-'0' < 10) num = n[i]-'0';
        else num = n[i] - '0' - base;
        ret = ret * radix + num;
    }
    return ret;
}

long long find_radix(long long N, char n[], long long left, long long right)
{
    if(left > right) return -1;
    else {
        long long mid = (left + right) / 2;
        long long t = decimal(n, mid);
        if(t == N) return mid;
        if(t < 0 || t > N) find_radix(N, n, left, mid-1);
        else find_radix(N, n, mid+1, right);
    }
}

void find_minmax(long long N, char n[], long long *minRadix, long long *maxRadix)
{
    long long min = -1, max = N;
    for(long long i = 0; n[i]!='\0'; i++) {
        if(min < n[i]-'0') min = n[i] - '0';
    }
    if(min > 9) min -= base;
    *minRadix = min + 1;

    *maxRadix = max > min+1 ? max : min+1;
}

long long main()
{
    long long N1, N2, radix, tag, minRadix, maxRadix, ret;
    char n1[11] = {'\0'}, n2[11] = {'\0'};
    scanf("%s %s %lld %lld", &n1, &n2, &tag, &radix);
     
    if(tag == 1) {
        N1 = decimal(n1, radix);
        find_minmax(N1, n2, &minRadix, &maxRadix);
        ret = find_radix(N1, n2, minRadix, maxRadix);
    }

    if(tag == 2) {
        N2 = decimal(n2, radix);
        find_minmax(N2, n1, &minRadix, &maxRadix);
        ret = find_radix(N2, n1, minRadix, maxRadix);
    }

    if(ret == -1) printf("Impossible\n");
    else printf("%lld\n", ret);
   
    return 0;
}