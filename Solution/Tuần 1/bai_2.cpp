// Time: O(n)
// Space: O(n)

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
const int inf = 0x3f3f3f3f;
ifstream fi("BAI2.INP");
ofstream fo("BAI2.OUT");
int n;
vector <int> a;

void Nhap(){
    fi >> n;
    int ain;
    for (int i=1; i<=n; i++){
        fi >> ain;
        a.push_back(ain);
    }
}

void Xuly(){
    int res = inf;
    sort(a.begin(), a.end(), less<int>());
    for (int i=1; i<a.size(); i++){
        if (a[i] - a[i-1] < res){
            res = a[i] - a[i-1];
        }
    }
    fo << res;
}

int main(){
    Nhap();
    Xuly();
    fi.close();
    fo.close();
}
