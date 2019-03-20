#include <stdio.h>
#include <string.h>

#define Max 100
char num[Max];
int k;

void reserve(char str[], char ret[])
{
    int len, j; 
    len = strlen(str);
    j = 0;
    for(int i = len - 1; i >= 0; i--) {
        ret[j++] = str[i];
    }
}

void add(char num[], char numr[])
{
    int len = strlen(num);
    int i, temp, flag = 0;
    for(i = 0; i < len; i++) {
        if(flag) temp = (num[i]-'0') + (numr[i] - '0') + 1;
        else temp = (num[i]-'0') + (numr[i] - '0');
        if(temp > 9) {
            flag =  1;
            numr[i] = (temp-10) + '0';
        }
        else {
            flag = 0;
            numr[i] = temp + '0';
        }
    }
    if(flag) numr[i] = '1';

    reserve(numr, num);
}

int check(char num[])
{
    int ret =  0;
    char r[Max] = {'\0'};
    reserve(num, r);
    if(strcmp(num, r) == 0) ret = 1;
    return ret;
}

int main()
{
    scanf("%s %d", &num, &k);
    int i, ret = 0;
    for(i = 0; i < k; i++) {
        if(check(num)) {
            ret = 1;
            break;
        }
        char numr[Max] = {'\0'};
        reserve(num, numr);
        add(num, numr);
    }
    printf("%s\n", num);
    printf("%d\n", i);
    return 0;
}