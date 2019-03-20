#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    vector<string> ret;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string id, pass;
        cin >> id >> pass;
        bool isR = false;
        for(auto j = pass.begin(); j != pass.end(); j++) {
            switch (*j) {
                case '1': *j = '@'; isR = true; break;
                case '0': *j = '%'; isR = true; break;
                case 'l': *j = 'L'; isR = true; break;
                case 'O': *j = 'o'; isR = true; break;
            }
        }
        if(isR) {
            string temp = id + " " + pass;
            ret.push_back(temp);
        }
    }
    if(ret.size()) {
        cout << ret.size() << endl;
        for(auto i = ret.begin(); i != ret.end(); i++) 
            cout << *i << endl;
    } else {
        if(n == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << n <<" accounts and no account is modified" << endl;
    }
    return 0;
}
