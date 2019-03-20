#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; 

typedef int Position;
struct QNode {
    ElementType *Data;     /* 存储元素的数组 */
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

typedef struct cusNode customer;
struct cusNode {
    int start;
    int ptime;
};

typedef struct winNode windows;
struct winNode {
    int next; 
    Queue Q;
};
windows win[20];

Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
 
void AddQ( Queue Q, ElementType X )
{
   
    Q->Rear = (Q->Rear+1)%Q->MaxSize;
    Q->Data[Q->Rear] = X;
    return;
}

int IsFull( Queue Q )
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}

int IsEmpty( Queue Q )
{
    return (Q->Front == Q->Rear);
}
 
ElementType DeleteQ( Queue Q )
{
    Q->Front =(Q->Front+1)%Q->MaxSize;
    return  Q->Data[Q->Front];
}
ElementType TopQ( Queue Q )
{
    return  Q->Data[(Q->Front+1)%Q->MaxSize];
}

int findwin(int n, int m)
{
    int i, minwin, minline = m;
    int mintime = 65535;
    for(i = 0; i < n; i++) {
        if(mintime > TopQ(win[i].Q)) {
            minwin = i;
            mintime = TopQ(win[i].Q);
        }
    }
    DeleteQ(win[minwin].Q);
    return minwin;
}

int main() 
{
    int i, n, m, k, q, query, w;

    scanf("%d %d %d %d", &n, &m, &k, &q);
    customer cus[k];
    
    for(i = 0; i < n; i++) {
        win[i].next = 0;
        win[i].Q = CreateQueue(m);
    }
    for(i = 0; i < k; i++) {
        scanf("%d", &cus[i].ptime);
        if(i < n * m) w = i % n;
        else w = findwin(n, m);
        
        if(win[w].next >= 540) cus[i].start = -1;
        else {
            win[w].next += cus[i].ptime; 
            cus[i].start = win[w].next;
            AddQ(win[w].Q, cus[i].start);
        } 
    }
    for(i = 0; i < q; i++) {
        scanf("%d", &query);
        if(cus[query-1].start == -1) printf("Sorry\n");
        else printf("%02d:%02d\n", (cus[query-1].start+480)/60, cus[query-1].start%60);
    }
    return 0;
}