//  贪心算法，注意舍去负值
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int nc, np, temp;
    vector<int> c, p;
    cin >> np;
    for(int i = 0; i < np; i++) {
        cin >> temp;
        p.push_back(temp);
    }
    cin >> nc;
    for(int i = 0; i < nc; i++) {
        cin >> temp;
        c.push_back(temp);
    }
    sort(p.begin(), p.end(), cmp);
    sort(c.begin(), c.end(), cmp);
    int total = 0;
    auto i = p.begin();
    for(auto j = c.begin(); i != p.end() && *i > 0 && *j >0; ++i, ++j)
        total += (*i)*(*j);
    if(i != p.end())
        for(auto i = p.rbegin(), j = c.rbegin(); *i <= 0 && *j <=0; ++i, ++j) // 反向迭代器通过++遍历，不是--
            total += (*i)*(*j);
    cout << total << endl;
    return 0;
}