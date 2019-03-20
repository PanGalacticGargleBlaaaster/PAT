#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if(n <= 1) return false;
    int sqr = (int)(sqrt(n*1.0));
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int i, n, d;
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        else {
            scanf("%d", &d);
            if(!isPrime(n)) {
                printf("No\n");
                continue;
            }
            int len = 0, arr[100];
            do{
                arr[len++] = n % d;
                n /= d;
            } while(n!=0);
            for(i = 0; i < len; i++)
                n = n * d + arr[i];
            printf("%s", isPrime(n) ? "Yes\n" : "No\n");
        }
        
    }
    return 0;
}