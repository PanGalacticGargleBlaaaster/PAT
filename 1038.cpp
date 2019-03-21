#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a, string b)
{   // 保证两个字符串构成的数字是最小的
    return a+b < b+a;  
}
int main()
{
    int n;
    cin >> n;
    string num[n];
    for(int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num+n, cmp);
    string ret;
    for(int i = 0; i < n; i++) {
        ret += num[i];
    }
    while(ret.length()!=0 && ret[0] == '0')
        ret.erase(ret.begin());
    if(ret.length() == 0) cout << 0 << endl;
    else cout << ret << endl;
    return 0;
}