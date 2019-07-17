#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10007, maxm = 100000007;
int n, m;
bool a[maxn][maxn];
bool Free[maxn];
int X[maxn];

void Nhap();
void QuayLui(int i);
void Xuat();

void Nhap(){
    cin >> n >> m;
    memset(a, false, sizeof(a));
    memset(Free, true, sizeof(Free));
    int u, v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
    X[0] = 1;
    Free[1] = false;
}

void QuayLui(int i){
    for (int j=1; j<=n; j++){
        if (a[X[i-1]][j] && Free[j]){
            X[i] = j;
            if (i == n-1){
                if (a[X[i]][1]){
                    Xuat();
                }
            }
            else{
                Free[j] = false;
                QuayLui(i+1);
                Free[j] = true;
            }
        }
    }
}

void Xuat(){
    for (int i=1; i<=n; i++){
        cout << X[i-1] << " ";
    }
    cout << 1 << "\n";
}

int main(){
    Nhap();
    QuayLui(1);
}
