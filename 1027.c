#include <stdio.h>

int main()
{
    int rgb;
    char r13[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0, j = 0; i < 3; i++) {
        scanf("%d", &rgb);
        printf("%c%c", r13[rgb/13], r13[rgb%13]);
    }
    return 0;
}