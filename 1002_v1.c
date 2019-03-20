// 以expon为下标建立数组， 直接进行计算
#include <stdio.h>

int main()
{
    int k, i, cnt, expon;
    float coeff, A[1001] = {0};

    cnt = 0;
    scanf("%d", &k);
    for(i = 0; i < k; i++) {
        scanf("%d %f", &expon, &coeff);
        A[expon] = coeff;
        cnt++;
    }
    scanf("%d", &k);
    for(i = 0; i < k; i++) {
        scanf("%d %f", &expon, &coeff);
        if(A[expon]) {
            A[expon] += coeff;
            if(A[expon]==0) cnt--; // 系数为0时不计数
        }
        else {
            A[expon] = coeff;
            cnt++;
        }
    }

    printf("%d", cnt);
    for(i = 1000; i >=0 || cnt >0;i--) {
        if(A[i]) {
           printf(" %d %.1f", i, A[i]);
           cnt--;
        }
    }
    printf("\n");

}