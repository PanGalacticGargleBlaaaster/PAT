//  建立结构数组进行多项式计算
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode * Poly;
struct PolyNode{
    int expon;
    float coeff;
};

int poly_plus(Poly a, int k1, Poly b, int k2, Poly c);
int main()
{
    int k1, k2, k3, i;
    Poly a, b, c;
    a = (Poly)malloc(10*sizeof(struct PolyNode));
    b = (Poly)malloc(10*sizeof(struct PolyNode));
    c = (Poly)malloc(10*sizeof(struct PolyNode));
    for(i = 0; i < 10; i++) {
        a[i].coeff = 0; a[i].expon = 0;
        b[i].coeff = 0; b[i].expon = 0;
        c[i].coeff = 0; c[i].expon = 0;
    }
    scanf("%d", &k1);
    for(i = 0; i < k1; i++) {
        scanf("%d %f", &a[i].expon, &a[i].coeff);
    }
    scanf("%d", &k2);
    for(i = 0; i < k2; i++) {
        scanf("%d %f", &b[i].expon, &b[i].coeff);
    }
    k3 = poly_plus(a, k1, b, k2, c);
    
    printf("%d", k3);
    for(i = 0; i < k3; i++) {
       printf(" %d %.1f", c[i].expon, c[i].coeff);
    }
    printf("\n");

    return 0;
}

int poly_plus(Poly a, int k1, Poly b, int k2, Poly c)
{
    int i1 = 0, i2 = 0, i3 = 0;
    while(i1 < k1 && i2 < k1) {
        if(a[i1].expon < b[i2].expon) {
            c[i3].expon = b[i2].expon;
            c[i3].coeff = b[i2].coeff;
            i2++; 
            if(c[i3].coeff != 0) i3++; // 注意舍去系数为0的项
        }
        if(a[i1].expon == b[i2].expon) {
            c[i3].expon = b[i2].expon;
            c[i3].coeff = b[i2].coeff + a[i1].coeff;
            i1++; i2++;
            if(c[i3].coeff != 0) i3++;
        }
        if(a[i1].expon > b[i2].expon) {
            c[i3].expon = a[i1].expon;
            c[i3].coeff = a[i1].coeff;
            i1++; 
            if(c[i3].coeff != 0) i3++;
        }
    }
    while(i1 < k1){
        c[i3].expon = a[i1].expon;
        c[i3].coeff = a[i1].coeff;
        i1++; i3++;
    }
    while(i2 < k2){
        c[i3].expon = b[i2].expon;
        c[i3].coeff = b[i2].coeff;
        i2++; i3++;
    }
    return i3;
}
