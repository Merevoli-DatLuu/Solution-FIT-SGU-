// Time: O(n^2)
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
int d[maxn];
bool Free[maxn];
int Trace[maxn];

void Nhap(){
    cin >> n >> m >> s >> f;
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
    }
    Trace[s] = -1; // Gốc ở 1;
    d[s] = 0;
}

void Dijkstra(){
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
            if (d[v] > d[u] + c[u][v] && Free[v]){
                d[v] = d[u] + c[u][v];
                Trace[v] = u;
            }
        }
    }
}

void Xuat(){
    if (d[f] == inf){
        cout << "Khong co duong di";
    }
    else{
        cout << d[f] << "\n";
        int F = f;
        while (s != F){
            cout << F << "<-";
            F = Trace[F];
        }
        cout << s;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Nhap();
    Dijkstra();
    Xuat();
}
