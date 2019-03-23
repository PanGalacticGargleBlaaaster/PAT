// 动态规划
#include <iostream>
using namespace std;
int d[1001][1001];
int main()
{
    string s;
    getline(cin, s);
    int len = s.length(), ret = 1;
    for(int i = 0; i < len; i++) { // 先处理长度为1和2的情况
        d[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1])
            d[i][i+1] = 1;
    }
    for(int l = 3; l <= len; l++) { // 从长度为3开始，动态规划
        for(int i = 0; i < len - l + 1; i++) {
            int j = i + l - 1;
            if(s[i] == s[j] && d[i+1][j-1] == 1) {
                d[i][j] = 1;
                ret = l;
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}