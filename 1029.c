#include <stdio.h>

// int main()
// {
//     int n1, n2;
//     scanf("%d", &n1);
//     int s1[n1];
//     for(int i = 0; i < n1; i++) {
//         scanf("%d", &s1[i]);
//     }
//     scanf("%d", &n2);
//     int s2[n2];
//     for(int i = 0; i < n2; i++) {
//         scanf("%d", &s2[i]);
//     }
//     int mid = (n1+n2-1)/2;
//     int s[mid];
//     int i, j = 0, k = 0;
//     for(i = 0; i < n1+n2 && j < n1 && k < n2; i++) {
//         if(i > mid) break;
//         if(s1[j] > s2[k]) s[i] = s2[k++];
//         else s[i] = s1[j++];
//     }
//     while(j < n1) {
//         if(i > mid) break;
//         s[i++] = s1[j++];
//     }
//     while(k < n2) {
//         if(i > mid) break;
//         s[i++] = s2[k++];
//     }
//     printf("%d\n", s[mid]);
//     return 0;
// }

int main()
{
    int n1, n2, temp, count = 0;
    scanf("%d", &n1);
    int s[200005];
    for(int i = 1; i <= n1; i++) {
        scanf("%d", &s[i]);
    }
    s[n1 + 1] = 0x7fffffff;
    scanf("%d", &n2);
    int i = 1, mid = (n1+n2+1)/2;
    for(int j = 1; j <= n2; j++) {
        scanf("%d", &temp);
        while(s[i] < temp) {
            count++;
            if(count == mid) printf("%d\n", s[i]);
            i++;
        }
        count++;
        if(count == mid) printf("%d\n", temp);
    }
    while(i < n1){
        count++;
        if(count == mid) printf("%d\n", s[i]);
        i++;
    }
    return 0;
}