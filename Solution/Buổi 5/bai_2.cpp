// Time: O(n^3)
// Space: O(n^2)

#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;
const int maxcc = 107;
const int inf = 0x3f3f3f3f;
ifstream fi("TABLE.INP");
ofstream fo("TABLE.OUT");
int n;
ll a[maxcc][maxcc];

void Nhap(){
    fi >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            fi >> a[j][i];
            if (a[j][i] == 0){
                a[j][i] = -inf;
            }
        }
    }
}

void solve(){
    ll res = 0;
    for (int i=0; i<=n; i++){
        a[0][i] = 0;
        a[i][0] = 0;
    }
    
    for (int i=1; i<=n; i++){
        for (int j=2; j<=n; j++){
            a[j][i] = a[j][i] + a[j-1][i];
        }
    }
    
    for (int i=1; i<=n; i++){
        for (int j=2; j<=n; j++){
            a[i][j] = a[i][j] + a[i][j-1];
        }
    }
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << a[j][i] << " ";
        }
        cout << "\n";
    }
    
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n-k+1; i++){
            for (int j=1; j<=n-k+1; j++){
                ll T = a[i+k-1][j+k-1] - a[i+k-1][j-1] - a[i-1][j+k-1] + a[i-1][j-1];
                if (T > res){
                    res = T;
                } 
            }
        }
    }
    fo << res;
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
