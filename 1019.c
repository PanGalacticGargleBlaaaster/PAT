#include <stdio.h>
#include <string.h>

// char num[10] = {'\0'};
int ret[100];
// int reret[10] = {'\0'};
int num, b;

int radix(int num, int base)
{
    int i = 0, n;
    // char ret[10] = {'\0'};
    
    for(n = num; n != 0; n = n/base)
        ret[i++] = n%base;
    return i;
}

int main()
{
    int m, cnt;
    scanf("%d %d", &num, &b);
    m = radix(num, b);
    cnt = m - 1;
    int flag = 0;
    for(int i = 0; cnt >= 0; i++, cnt--) {
        if(ret[i] == ret[cnt]) continue;
        else {
            flag = 1;
            break;
        }
    }
    if(flag == 0) printf("Yes\n");
    else printf("No\n");
    for(int i = m-1; i >= 0; i--){
        if(i != 0) printf("%d ", ret[i]);
        else printf("%d\n", ret[i]);
    }
    if(m == 0) printf("0\n");
    return 0;
}