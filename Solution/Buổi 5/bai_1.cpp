// Time: O(n*log(n))
// Space: O(n)
// Có thể fix lại sort để Time: O(k*log(n))

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
const int maxc = 1e5;
ifstream fi("SEQUENCE.INP");
ofstream fo("SEQUENCE.OUT");
int n, k;
vector <int> a;
bool Free[maxc];

void Nhap(){
    fi >> n >> k;
    memset(Free, true, sizeof(Free));
    int ain;
    for (int i=1; i<=n; i++){
        fi >> ain;
        if (Free[ain]){
            a.push_back(ain);
            Free[ain] = false;
        }
    }
}

void solve(){
    sort(a.begin(), a.end(), greater<int>());
    if (k > a.size()){
        fo << a[a.size()-1];
    }
    else{
        fo << a[k-1];
    }
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
