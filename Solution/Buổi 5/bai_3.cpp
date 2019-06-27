// Time: O(n^3)
// Space: O(n^2)

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
const int maxcc = 107;
ifstream fi("MOVE.INP");
ofstream fo("MOVE.OUT");
int n, m, t;
int a[maxcc][maxcc];
bool Free[maxcc][maxcc];

void Nhap(){
    fi >> m >> n >> t;
    memset(Free, true, sizeof(Free));
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            fi >> a[j][i];
            if (a[j][i] == 0){
                Free[j][i] = false;
            }
        }
    }
}

void DuyetDoc(int ux, int uy){
    int i = uy;
    int j = uy;
    while (a[ux][i] == a[ux][uy] && i >= 1){
        i--;
    }
    i++;
    while (a[ux][j] == a[ux][uy] && j <= m){
        j++;
    }
    j--;
    if (j - i + 1 >= t){
        for (int ii=i; ii<=j; ii++){
            Free[ux][ii] = false;
        }
    }
}

void DuyetNgang(int ux, int uy){
    int i = ux;
    int j = ux;
    while (a[i][uy] == a[ux][uy] && i >= 1){
        i--;
    }
    i++;
    while (a[j][uy] == a[ux][uy] && j <= n){
        j++;
    }
    j--;
    if (j - i + 1 >= t){
        for (int ii=i; ii<=j; ii++){
            Free[ii][uy] = false;
        }
    }
}

void solve(){
    int res = 0;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (Free[j][i]){
                DuyetNgang(j, i);
                DuyetDoc(j, i);
            }
        }
    }
    
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (Free[j][i]){
                res++;
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
