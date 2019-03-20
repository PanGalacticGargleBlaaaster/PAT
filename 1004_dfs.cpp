#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> g[100];
int cnt[100], n, m, maxlevel = -1;

void dfs(int v, int level)
{
	if(g[v].size() == 0) {
		cnt[level]++;
		maxlevel = max(maxlevel, level);
		return;
	}
	for(int w = 0; w < g[v].size(); w++)
		dfs(g[v][w], level+1);
}

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
	dfs(1, 0);
	for(int i = 0; i <= maxlevel; i++) {
		if(i == maxlevel) printf("%d\n", cnt[i]);
		else printf("%d ", cnt[i]);
	}
	return 0;
}