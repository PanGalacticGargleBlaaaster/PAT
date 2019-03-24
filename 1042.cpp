#include <iostream>
using namespace std;
int main()
{
    int temp[54], ret[54], order[54], n;
    scanf("%d\n", &n);
    for(int i = 0; i < 54; ++i) {
        scanf("%d", &order[i]);
        --order[i];
        ret[i] = i;
        }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 54; ++j)
            temp[j] = ret[j];
        for(int k = 0; k < 54; ++k)
            ret[order[k]] = temp[k];
    }
    char card[6] = {"SHCDJ"};
    for(int i = 0; i < 54; ++i) {
        printf("%c%d", card[ret[i]/13], ret[i]%13+1);
        if(i != 53) printf(" ");
    }
    return 0;
}