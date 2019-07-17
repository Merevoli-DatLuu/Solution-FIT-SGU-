#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10007, maxm = 100000007;
int n, m;
bool a[maxn][maxn];
int X[maxn];
int Y[maxn];
int max_edge = 0;

void Nhap();
void QuayLui(int i);
void Xuat();

void Nhap(){
    cin >> n >> m;
    memset(a, false, sizeof(a));
    int u, v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
    X[0] = 1;
}

void QuayLui(int i){
    for (int j=1; j<=n; j++){
        if (a[X[i-1]][j]){
            X[i] = j;
            a[X[i-1]][j] = false;
            a[j][X[i-1]] = false;
            if (a[X[i]][1]){
                if (i > max_edge){
                    max_edge = i;
                    for (int p=0; p<=i; p++){
                        Y[p] = X[p];
                    }
                }
            }
            QuayLui(i+1);
            a[X[i-1]][j] = true;
            a[j][X[i-1]] = true;
        }
    }
}

void Xuat(){
    for (int i=1; i<=max_edge+1; i++){
        cout << Y[i-1] << " ";
    }
    cout << 1 << "\n";
}

void solve(){
    bool Free[maxn];
    memset(Free, true, sizeof(Free));
    for (int i=1; i<=n; i++){
        if (Free[i]){
            QuayLui(1);
            Xuat();
            for (int j=1; j<=max_edge+1; j++){
                Free[j] = false;
            }
        }
    }
    cout << max_edge;
}

int main(){
    Nhap();
    solve();
}
