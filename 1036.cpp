#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string female, male;
    int femalegrade = -1, malegrade = 101;
    for(int i = 0; i < n; i++) {
        string name, gender, id;
        int grade;
        cin >> name >> gender >> id >> grade;
        if(gender == "F") {
            if(femalegrade < grade) {
                femalegrade = grade;
                female = name + " " + id;
            }
        } else if(malegrade > grade) {
                malegrade = grade;
                male = name + " " + id;
            }
    }
    if(femalegrade != -1)
        cout << female << endl;
    else
        cout << "Absent\n";
    if(malegrade != 101)
        cout << male << endl;
    else
        cout << "Absent\n";
    if(femalegrade != -1 && malegrade != 101)
        cout << femalegrade - malegrade << endl;
    else
        cout << "NA" << endl;
    return 0;
}

/*  不用排序
#include <iostream>
#include <algorithm>
using namespace std;
struct stu_node {
    string name, id;
    int gender, grade;
};

bool cmp(stu_node &a, stu_node &b)
{
    if(a.grade != b.grade)
        return a.grade > b.grade;
    else return a.gender < b.gender;
}

int main()
{
    int n;
    cin >> n;
    stu_node stu[n];
    for(int i = 0; i < n; ++i) {
        string name, id, gender;
        int grade;
        cin >> name >> gender >> id >> grade;
        stu[i].name = name;
        stu[i].id = id;
        stu[i].grade = grade;
        if(gender == "F") stu[i].gender = 0;
        else stu[i].gender = 1;
    }
    sort(stu, stu+n, cmp);
    int flag0 = -1, flag1 = -1;
    for(int i = 0; i < n; ++i) {
        if(stu[i].gender == 0) {
            flag0 = i;
            cout << stu[i].name << " " << stu[i].id << endl;
            break;
        }
    }
    if(flag0 == -1) cout << "Absent" << endl;
    for(int i = n-1; i >= 0; --i) {
        if(stu[i].gender == 1) {
            flag1 = i;
            cout << stu[i].name << " " << stu[i].id << endl;
            break;
        }
    }
    if(flag1 == -1) cout << "Absent" << endl;
    if(flag0==-1 || flag1==-1) cout << "NA" << endl;
    else {
        cout << stu[flag0].grade - stu[flag1].grade << endl;
    }
    
    return 0;
}
*/