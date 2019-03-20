#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char ID[7];
    char Name[9];
    int Score;
} Node;
typedef Node ElementType;

// void Head_Sort(const Node stu[], int Hsort[], int type, int N);
int cmp1(const void * x, const void * y);
int cmp2(const void * x, const void * y);
int cmp3(const void * x, const void * y);
// ElementType Median3( ElementType A[], int Hsort[], int Left, int Right, int(*cmp)(Node, Node));
// void Qsort( ElementType A[], int Left, int Right, int Hsort[], int(*cmp)(Node, Node));
// void QuickSort( ElementType A[], int Hsort[], int N, int(*cmp)(Node, Node));

int main() 
{
    int i, n, type;
    // char id[7] = '0', name[9] = '0';

    scanf("%d %d", &n, &type);
    Node Stu[n];
    int Hsort[n];
    for(i = 0; i < n; i++) {
        scanf("%s %s %d", &Stu[i].ID, &Stu[i].Name, &Stu[i].Score);
        Hsort[i] = i;
    }

    switch (type)
    {
        case 1:
            qsort(Stu, n, sizeof(Node), cmp1);
            break;
        case 2:
            qsort(Stu, n, sizeof(Node), cmp2);
            break;
        case 3:
            qsort(Stu, n, sizeof(Node), cmp3);
            break;
    }

    for(i = 0; i < n; i++) {
        printf("%s %s %d\n", Stu[i].ID, Stu[i].Name, Stu[i].Score);
    }
}

// void Head_Sort(const Node stu[], int Hsort[], int type, int N)
// {
//     int Si, D, P, i;
//     int tmp;

//     int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

//     for(Si = 0; Sedgewick[Si] >= N; Si++)
//         ;   // 初始的增量Sedgewick[Si]不能超过待排序长度

//     if(type == 1) {
//         for(D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
//         for(P = D; P < N; P++) {
//             tmp = Hsort[P];
//             for(i = P; i >= D && cmp1(stu[i-D], stu[P]); i -= D)
//                 Hsort[i] = Hsort[i-D];
//                 // A[i] = A[i-D];
//             Hsort[i] = tmp;
//         }
//     }

//     if (type == 2) {
//         for(D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
//         for(P = D; P < N; P++) {
//             tmp = Hsort[P];
//             for(i = P; i >= D && cmp2(stu[i-D], stu[P]); i -= D)
//                 Hsort[i] = Hsort[i-D];
//                 // A[i] = A[i-D];
//             Hsort[i] = tmp;
//         }
//     }
//     if (type == 3) {
//         for(D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
//         for(P = D; P < N; P++) {
//             tmp = Hsort[P];
//             for(i = P; i >= D && cmp3(stu[i-D], stu[P]); i -= D)
//                 Hsort[i] = Hsort[i-D];
//                 // A[i] = A[i-D];
//             Hsort[i] = tmp;
//         }
//     }
// }

int cmp1(const void * x, const void * y)
{
    Node a = *(Node*)x;
    Node b = *(Node*)y;
    return strcmp(a.ID, b.ID);
}

int cmp2(const void * x, const void * y)
{
    Node a = *(Node*)x;
    Node b = *(Node*)y;
    if(strcmp(a.Name, b.Name)!=0)
        return strcmp(a.Name, b.Name);
    else return cmp1(x, y);
}

int cmp3(const void * x, const void * y)
{
    Node a = *(Node*)x;
    Node b = *(Node*)y;
    if(a.Score != b.Score)
        return a.Score - b.Score;
    else return cmp1(x, y);
}

/* 快速排序 */
 
// ElementType Median3( ElementType A[], int Hsort[], int Left, int Right, int (*cmp)(Node, Node))
// { 
//     int Center = (Left+Right) / 2, tmp;
//     if ( (*cmp)(A[Left], A[Center])) {
//         tmp = Hsort[Left];
//         Hsort[Left] = Hsort[Center];
//         Hsort[Center] = tmp;
//     }
//         // Swap( &A[Left], &A[Center] );
//     // if ( A[Left] > A[Right] )
//     //     Swap( &A[Left], &A[Right] );
//     if ( (*cmp)(A[Left], A[Right])) {
//         tmp = Hsort[Left];
//         Hsort[Left] = Hsort[Right];
//         Hsort[Right] = tmp;
//     }
//     // if ( A[Center] > A[Right] )
//     //     Swap( &A[Center], &A[Right] );
//      if ( (*cmp)(A[Center], A[Right])) {
//         tmp = Hsort[Center];
//         Hsort[Center] = Hsort[Right];
//         Hsort[Right] = tmp;
//     }
//     /* 此时A[Left] <= A[Center] <= A[Right] */
//     // Swap( &A[Center], &A[Right-1] ); /* 将基准Pivot藏到右边*/
//     tmp = Hsort[Center];
//     Hsort[Center] = Hsort[Right-1];
//     Hsort[Right-1] = tmp;
//     /* 只需要考虑A[Left+1] … A[Right-2] */
//     return  A[Right-1];  /* 返回基准Pivot */
// }
 
// void Qsort( ElementType A[], int Left, int Right, int Hsort[], int (*cmp)(Node, Node))
// { /* 核心递归函数 */ 
//     int  Cutoff, Low, High, tmp;
//     ElementType Pivot;
       
//     // if ( Cutoff <= Right-Left ) { /* 如果序列元素充分多，进入快排 */
//         Pivot = Median3( A, Hsort, Left, Right,  (*cmp)); /* 选基准 */ 
//         Low = Left; High = Right-1;
//         while (1) { /*将序列中比基准小的移到基准左边，大的移到右边*/
//             while ((*cmp)(Pivot, A[++Low])); //A[++Low] < Pivot ) ;
//             while ( (*cmp)(A[--High], Pivot));
//             if ( Low < High ) {//Swap( &A[Low], &A[High] );
//                 tmp = Hsort[Low];
//                 Hsort[Low] = Hsort[High];
//                 Hsort[High] = tmp;
//             }   
//             else break;
//         }
//         // Swap( &A[Low], &A[Right-1] );   /* 将基准换到正确的位置 */ 
//         tmp = Hsort[Low];
//         Hsort[Low] = Hsort[Right-1];
//         Hsort[Right-1] = tmp;
//         Qsort( A, Left, Low-1, Hsort, (*cmp) );    /* 递归解决左边 */ 
//         Qsort( A, Low+1, Right, Hsort, (*cmp) );   /* 递归解决右边 */  
//     // }
//     // else InsertionSort( A+Left, Right-Left+1 ); /* 元素太少，用简单排序 */ 
// }
 
// void QuickSort( ElementType A[], int Hsort[], int N, int (*cmp)(Node, Node))
// { /* 统一接口 */
//     Qsort( A, 0, N-1, Hsort, (*cmp));
// }

