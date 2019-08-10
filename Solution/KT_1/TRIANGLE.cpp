// Time: O(n^2)
// Space: O(n^2)

#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 1007;
ifstream fi("TRIANGLE.INP");
ofstream fo("TRIANGLE.OUT");
int n;
int a[maxn][maxn];
int F[maxn][maxn];

void Nhap(){
    fi >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            fi >> a[i][j];
        }
    }
}

void solve(){
    for (int i=1; i<=n; i++){
        F[n][i] = a[n][i];
    }
    for (int i=n-1; i>=1; i--){
        for (int j=1; j<=i; j++){
            F[i][j] = a[i][j] + max(F[i+1][j], F[i+1][j+1]);
        }
    }
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=i; j++){
//            cout << F[i][j] << " ";
//        }
//        cout << "\n";
//    }
    fo << F[1][1];
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
