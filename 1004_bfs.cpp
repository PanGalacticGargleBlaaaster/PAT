#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[100];
int cnt[100], level[100], n, m, maxlevel = -1;
bool visited[100];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int k, id1, id2;
		scanf("%d %d", &id1, &k);
		for(int j = 0; j < k; j++) {
			scanf("%d", &id2);
			g[id1].push_back(id2);
		}
	}
	queue<int> q;
	visited[1] = true;
	q.push(1);
	level[1] = 0;
	while(!q.empty()) {
		int w = q.front(); 
		q.pop();
		maxlevel = max(maxlevel, level[w]);
		if(g[w].size() == 0) {
			cnt[level[w]]++;
			continue;
		}
		for(int i = 0; i < g[w].size(); i++) {
			if(visited[g[w][i]] == false) {
				visited[g[w][i]] = true;
				q.push(g[w][i]);
				level[g[w][i]] = level[w] + 1; 
			}
		}
	}
	for(int i = 0; i <= maxlevel; i++) {
		if(i == maxlevel) printf("%d\n", cnt[i]);
		else printf("%d ", cnt[i]);
	}
	return 0;
}