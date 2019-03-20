#include <stdio.h>

int main()
{
    char c[4] = {"WTL\0"};
    double maxvalve, temp, ans = 1.0;
    int i, j, maxchar;
    for(i = 0; i < 3; i++) {
        maxvalve = 0.0;
        maxchar = 0;
        for(j = 0; j < 3; j++) {
            scanf("%lf", &temp);
            if(maxvalve <= temp) {
                maxvalve = temp;
                maxchar = j;
            }
        }
        ans *= maxvalve;
        printf("%c ", c[maxchar]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}