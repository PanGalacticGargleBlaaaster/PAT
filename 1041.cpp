#include <iostream>
using namespace std;
int n[100001], cnt[10001];
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int bet;
        cin >> bet;
        n[i] = bet;
        ++cnt[n[i]];
    }
    for(int i = 0; i < N; i++) {
        if(cnt[n[i]] == 1) {
            cout << n[i] << endl;
            return 0;
        }
    }
    cout << "None\n";
    return 0;
}