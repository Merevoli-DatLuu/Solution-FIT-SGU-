#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 10007, maxm = 100007;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, s, f;
bool c[maxn][maxn];

void Nhap(){
    cin >> n >> m;
    memset(c, false, sizeof(c));
    int u, v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        c[u][v] = true;
        c[v][u] = true;
    }
}

void Warshall(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (int k=1; k<=n; k++){
                c[i][k] = c[i][k] || (c[i][j] && c[j][k]);
            }
        }
    }
}

void Xuat(){
    bool Free[maxn];
    memset(Free, true, sizeof(Free));
    for (int i=1; i<=n; i++){
        if (Free[i]){
            cout << i << " ";
            Free[i] = false;
            for (int j=1; j<=n; j++){
                if (c[i][j] && i != j){
                    cout << j << " ";
                    Free[j] = false;
                }
            }
            cout << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Nhap();
    Warshall();
    Xuat();
}
