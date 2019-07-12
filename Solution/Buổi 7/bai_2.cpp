// Time: O(n^2)
// Space: O(n^2)

#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 10007, maxm = 100007;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
int c[maxn][maxn]; // Ma Trận Kề
int d[maxn]; // Trọng số đường đi
bool Free[maxn]; // Đánh Dấu
int Trace[maxn]; // Truy Vết
int MST_Weight;

// Nhập Input
void Nhap(){
    cin >> n >> m;
    int u, v, w;
    memset(Free, true, sizeof(Free));
    for (int i=1; i<=n; i++){
        Trace[i] = 0;
        d[i] = inf;
        for (int j=1; j<=n; j++){
            c[i][j] = inf;
        }
    }
    for (int i=1; i<=m; i++){
        cin >> u >> v >> w;
        c[u][v] = w;
        c[v][u] = w;
    }
    Trace[1] = -1; // Gốc ở 1;
    d[1] = 0;
}

// Thuật Toán Prim
void Prim(){
    for (int k=1; k<=n; k++){
        int u = 0;
        int maxc = inf;
        for (int i=1; i<=n; i++){
            if (maxc > d[i] && Free[i]){
                maxc = d[i];
                u = i;
            }
        }
        if (u == 0 || maxc == inf){
            break;
        }
        Free[u] = false;
        for (int v=1; v<=n; v++){
            if (d[v] > c[u][v] && Free[v]){
                d[v] = c[u][v];
                Trace[v] = u;
            }
        }
    }
}

// Xuất Output
void Xuat(){
    MST_Weight = 0;
    for (int i=2; i<=n; i++){
        MST_Weight += c[i][Trace[i]];
    }
    cout << MST_Weight << "\n";
    for (int i=2; i<=n; i++){
        cout << i << " " << Trace[i] << " " << c[i][Trace[i]] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Nhap();
    Prim();
    Xuat();
}
