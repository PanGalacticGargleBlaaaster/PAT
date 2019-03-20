#include <stdio.h>
#include <string.h>

int main()
{
    long int a, b, c;
    scanf("%ld %ld", &a, &b);
    c = a + b;
    char s[8] ="";
    sprintf(s, "%ld", c);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        printf("%c", s[i]);
        if(s[i] == '-') continue;
        if((i+1)%3 == len%3 && i != len-1) printf(",");
    }
     
    return 0;
}    