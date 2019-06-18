// Time: O(n)

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef long long ll;
ifstream fi("BAI3.INP");
ofstream fo("BAI3.OUT");
int n;
vector <ll> a;

void Nhap(){
    fi >> n;
    int ain;
    for (int i=1; i<=n; i++){
        fi >> ain;
        a.push_back(ain);
    }
}

void Xuly(){
    ll res = 0;
    for (int i=1; i<n; i++){
        a[i] = max(a[i], a[i-1] + a[i]);
        if (res < a[i]){
            res = a[i];
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