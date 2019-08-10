// Time: O(n^2*log(n))
// Space: O(n)

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
const int maxn = 107;
ifstream fi("MEDIUM.INP");
ofstream fo("MEDIUM.OUT");
int n;
int a[maxn];
int TV[maxn];

void Nhap(){
    fi >> n;
}

void solve(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            fi >> a[j];
        }
        sort(a + 1, a + n + 1, greater<int>());
        TV[i] = a[(n >> 1) + 1];
    }
    sort(TV + 1, TV + n + 1, greater<int>());
    fo << TV[(n >> 1) + 1];
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
