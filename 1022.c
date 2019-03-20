#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bnode {
    int id;
    char title[81];
    char author[81];
    char key[61];
    char publisher[81];
    char year[5];
};
struct bnode book[10000];

int n;

int cutchar(char key[], int mark)
{
    int i, j, len, ret;
    len = strlen(book[mark].key);
    ret = 0;
    i = 0; j = 0;
    while(i < len) {
        if(book[mark].key[i]==' ') {
            if(ret == 1) break;
            else {
                i++; j = 0;
            }
        }
        else if(book[mark].key[i] == key[j]) {
            i++; j++;
            ret = 1;
        }
        else if(book[mark].key[i] != key[j]) {
            j = 0; ret = 0;
            while(i < len && book[mark].key[i]!=' ') i++;
        }
    }
    return ret;
}

void Query(int q, char key[])
{
    int flag = 0;
    switch (q)
    {
        case 1:
            for(int i = 0; i < n; i++) {
                if(strcmp(book[i].title, key)==0) {
                    printf("%07d\n", book[i].id);
                    flag = 1;
                }
            }
            break;

        case 2:
            for(int i = 0; i < n; i++) {
                if(strcmp(book[i].author, key)==0) {
                    printf("%07d\n", book[i].id);
                    flag = 1;
                }
            }
            break;
        case 3:
            for(int i = 0; i < n; i++) {
                if(cutchar(key, i)==1) {
                    printf("%07d\n", book[i].id);
                    flag = 1;
                }
            }
            break;
        case 4:
            for(int i = 0; i < n; i++) {
                if(strcmp(book[i].publisher, key)==0) {
                    printf("%07d\n", book[i].id);
                    flag = 1;
                }
            }
            break;
        case 5:
            for(int i = 0; i < n; i++) {
                if(strcmp(book[i].year, key)==0) {
                    printf("%07d\n", book[i].id);
                    flag = 1;
                }
            }
            break;
    }
    if(flag==0) printf("Not Found\n");
}

int cmp(const void *a, const void *b)
{
    struct bnode x = *(struct bnode*)a;
    struct bnode y = *(struct bnode*)b;
    return x.id - y.id;
}

int main()
{
    int m;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d\n", &book[i].id);
        gets(book[i].title);
        gets(book[i].author);
        gets(book[i].key);
        gets(book[i].publisher);
        scanf("%s\n", &book[i].year);
    }
    qsort(book, n, sizeof(struct bnode), cmp);
    scanf("%d\n", &m);
    for(int i = 0; i < m; i++) {
        int query;
        char key[81] = {'\0'};
        scanf("%d: ", &query);
        gets(key);
        printf("%d: %s\n", query, key);
        Query(query, key);
    }
    return 0;
}