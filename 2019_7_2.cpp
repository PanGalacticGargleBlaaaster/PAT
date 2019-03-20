#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> id;
int n, m;

bool cmp(string a, string b) {
	if (a.substr(6, 8) <b.substr(6, 8))
		return 1;
	else return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		id.push_back(temp);
	}
	//sort(id.begin(), id.end(), cmp);
	cin >> m;
	int cnt = 0;
	string ret = "999999999999999999", old = "999999999999999999";
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if (cmp(temp, old))
			old = temp;
		for (int j = 0; j < n; j++) {
			if (temp == id[j]) {
				cnt++;
				//ret = temp;
				if (cmp(temp, ret)){
					ret = temp;
				}
			}
		}
	}
	if (cnt == 0){

		cout << old;
	}
	else
	{
		printf("%d\n", cnt);
		cout << ret;
	}
	return 0;
}


