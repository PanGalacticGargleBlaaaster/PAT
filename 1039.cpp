#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int getid(char *name) {
    int id = 0;
    for(int i = 0; i < 3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];
 
int main() {
    int n, k, no, num, id = 0;
    char name[5];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &no, &num);
        for(int j = 0; j < num; j++) {
            scanf("%s", name);
            id = getid(name);
            v[id].push_back(no);
        }
    }
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        id = getid(name);
        sort(v[id].begin(), v[id].end());
        printf("%s %lu", name, v[id].size());
        for(int j = 0; j < v[id].size(); j++)
            printf(" %d", v[id][j]);
        printf("\n");
    }
    return 0;
}

/*  超时

#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    unordered_map<string, set<int>> stu;
    for(int i = 0; i < k; i++) {
        int course, num;
        cin >> course >> num;
        for(int j = 0; j < num; j++) {
            string name;
            cin >> name;
            if(stu.find(name) == stu.end())
                stu.insert(pair<string,set<int> >(name, set<int>()));
            stu[name].insert(course);
        }
    }
    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;
        cout << name << " " << stu[name].size();
        for(auto j = stu[name].begin(); j != stu[name].end(); j++) {
            cout << " " << *j;
        }
        cout << endl;
    }
    return 0;
}

*/