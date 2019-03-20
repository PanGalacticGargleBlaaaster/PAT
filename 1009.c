#include <stdio.h>

int main()
{
    int i, j, k1, k2, n, cnt;
    double coeff, expon[1001] = {0.0}, ans[2001] = {0.0};

    scanf("%d", &k1);
    for(i = 0; i < k1; i++) {
        scanf("%d %lf", &n, &coeff);
        expon[n] = coeff;
    }
    cnt = 0;
    scanf("%d", &k2);
    for(i = 0; i < k2; i++) {
        scanf("%d %lf", &n, &coeff);
        for(j = 0; j < 1001; j++) {
            if(expon[j]!=0.0) {
                if(ans[j+n]==0.0) cnt++;
                ans[j+n] += coeff*expon[j];
                if(ans[j+n]==0.0) cnt--;
            }
        }
    }
    printf("%d", cnt);
    for(i = 2000; i >= 0; i--) {
        if(ans[i]!=0.0) {
            printf(" %d %.1f", i, ans[i]);
            cnt--;
        }
    }
    return 0;
}