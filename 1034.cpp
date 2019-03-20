#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, int> name;    // 用2个map来保存姓名+id
unordered_map<int, string> id;
unordered_map<string, int> ret;   // 用于保存结果
int idnum = 0, k;   // idnum进行id计数
int G[2001][2001], weight[2001];    // G保存边(通话)权重，weight保存个人权重
bool visited[2001];

int findid(const string &s) {   // string->id
    if(name[s] == 0) {  // map查找，如果未找到键值则返回0
        name[s] = ++idnum;
        id[idnum] = s;
        return idnum;
    } else {
        return name[s];
    }
}

void dfs(int v, int& boss, int& membercnt, int& totalweight)    // 主意传入为引用
{   // boss用于记录最大权重的人，membercnt统计成员数量，totalweight统计总权重
    ++membercnt;
    visited[v] = true;
    if(weight[v] > weight[boss])
        boss = v;
    for(int w = 1; w <= idnum; w++) {   // dfs:对v的每个相邻点w，如果w未被访问过，则递归访问
        if(G[v][w] > 0) {
            totalweight += G[v][w]; // 更新总权重
            G[v][w] = G[w][v] = 0;  // 更新后清零边权重防止出现回路
            if(!visited[w]) {
                dfs(w, boss, membercnt, totalweight);
            }
        }
    }
}

void dodfs()    // 统计连通分量
{
    for(int i = 1; i <= idnum; i++) {   // 访问每个节点，若该节点未被访问过，则为新的连通分量
        if(!visited[i]) {   // 遍历每个连通分量
            int totalweight = 0, boss = i, membercnt = 0;
            dfs(i, boss, membercnt, totalweight);
            if(membercnt > 2 && totalweight > k) {
                ret[id[boss]] = membercnt;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string name1, name2;
        int time;
        cin >> name1 >> name2 >> time;
        int id1 = findid(name1);
        int id2 = findid(name2);
        G[id1][id2] += time; 
        G[id2][id1] += time;
        weight[id1] += time;
        weight[id2] += time;
    }
    dodfs();
    cout << ret.size() << endl;
    for(auto it = ret.begin(); it != ret.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}