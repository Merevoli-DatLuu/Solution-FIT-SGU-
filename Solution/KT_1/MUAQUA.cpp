#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 10007;
ifstream fi("MUAQUA.INP");
ofstream fo("MUAQUA.OUT");
int n;
int a[maxn];
ll F[maxn];

void Nhap(){
    fi >> n;
    for (int i=1; i<=n; i++){
        fi >> a[i];
    }
}

int FF(int i){
    if (F[i] == 0){
        if (i == 0){
            return 0;
        }
        else if (i <= 1){
            return a[1];
        }
        else if (i <= 2){
            return a[1] + a[2];
        }
        else{
            int F_3 = a[i] + a[i-1];
            if (i >= 4){
                int F_4 = F_3 + a[i-2];
                F[i] = min(F_3 + FF(i-3), F_4 + FF(i - 4));
            }
            else{
                F[i] = F_3 + FF(i - 3);
            }
        }
    }
    return F[i];
}

void solve(){
    sort(a + 1, a + n + 1, less<int>());
    fo << FF(n);
}


int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
