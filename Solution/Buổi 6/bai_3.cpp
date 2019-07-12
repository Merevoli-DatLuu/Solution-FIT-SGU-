#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 10007, maxm = 100007;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, s, f;
bool c[maxn][maxn];
int Trace[maxn];

void Nhap(){
    cin >> n >> m >> s >> f;
    memset(c, false, sizeof(c));
    for (int i=1; i<=n; i++){
        Trace[i] = 0;
    }
    int u, v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        c[u][v] = true;
        c[v][u] = true;
    }
    Trace[s] = -1;
}

void DFS(int u){
    for (int v=1; v<=n; v++){
        if (c[u][v] && Trace[v] == 0){
            Trace[v] = u;
            if (v == f){
                return;
            }
            DFS(v);
        }
    }
}

void Xuat(){
    int F = f;
    while (s != F){
        cout << F << "<-";
        F = Trace[F];
    }
    cout << s;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Nhap();
    DFS(s);
    Xuat();
}
