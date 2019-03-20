#include <stdio.h>

int main()
{
    int i, n, flag, a[10000] = {0};
    int first, last, max, temp, tfirst, tlast;

    max = -1;
    temp = tfirst = 0;
    scanf("%d", &n);
    // 在线处理
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        temp += a[i];
        if(temp < 0) {
            temp = 0;
            tfirst = i+1;
        }
        else if(max < temp) {
            max = temp;
            first = tfirst;
            last = i;
        }
        else if (max == temp) {
            if(last+first > tfirst+i){
                first = tfirst;
                last = i;
            }
        }
    }
    if(max < 0) printf("0 %d %d\n", a[0], a[n-1]);
    else printf("%d %d %d\n", max, a[first], a[last]);
    return 0;
}