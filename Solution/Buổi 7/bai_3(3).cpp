// Time: O(n^3)
// Space: O(n^2)

#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 10007, maxm = 100007;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, s, f;
int c[maxn][maxn];
int Trace[maxn][maxn];

void Nhap(){
    cin >> n >> m >> s >> f;
    int u, v, w;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i == j){
                c[i][j] = 0;
            }
            else{
                c[i][j] = inf;
            }
            Trace[i][j] = j;
        }
    }
    for (int i=1; i<=m; i++){
        cin >> u >> v >> w;
        c[u][v] = w;
        c[v][u] = w;
    }
}

void Floyd(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (int k=1; k<=n; k++){
                if (c[j][k] > c[j][i] + c[i][k]){
                    c[j][k] = c[j][i] + c[i][k];
                    Trace[j][k] = Trace[j][i];
                }
            }
        }
    }
}

void Xuat(){
    if (c[s][f] == inf){
        cout << "khong co duong di";
    }
    else{
        cout << c[s][f] << "\n";
        int S = s;
        while (S != f){
            cout << S << "->";
            S = Trace[S][f];
        }
        cout << f;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Nhap();
    Floyd();
    Xuat();
}
