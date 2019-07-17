#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10007, maxm = 10000007;
int n, m;
bool a[maxn][maxn];
int Trace[maxn];
int Number[maxn];
int Low[maxn];
int Count = 0;

void Nhap(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        Trace[i] = 0;
        Number[i] = 0;
    }
    memset(a, false, sizeof(a));
    int u, v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
}

void Visit(int u){
    Count++;
    Number[u] = Count;
    Low[u] = inf;
    for (int v=1; v<=n; v++){
        if (a[u][v]){
            a[v][u] = false;
            if (Trace[v] == 0){
                Trace[v] = u;
                Visit(v);
                Low[u] = min(Low[u], Low[v]);
            }
            else{
                Low[u] = min(Low[u], Number[v]);
            }
        }
    }
}

void CauKhop(){
    for (int i=1; i<=n; i++){
        if (Trace[i] == 0){
            Trace[i] = -1;
            Visit(i);
        }
    }
}

void Xuat(){
    int count_children[maxn];
    for (int i=1; i<=n; i++){
        count_children[i] = 0;
    }
    for (int i=1; i<=n; i++){
        if (Trace[i] != -1){
            count_children[i]++;
        }
    }
    for (int v=1; v<=n; v++){
        int u = Trace[v];
        if (u != -1 && Low[v] >= Number[v]){
            cout << u << " " << v << "\n";
        }
    }
    bool IsCut[maxn];
    memset(IsCut, false, sizeof(IsCut));
    for (int v=1; v<=n; v++){
        int u = Trace[v];
        if (u != -1 && Low[v] >= Number[u]){
            IsCut[u] = IsCut[u] || (Trace[u] != -1) || (count_children[u] >= 2);
        }
    }
    for (int i=1; i<=n; i++){
        if (IsCut[i]){
            cout << i << " ";
        }
    }
}

int main(){
    Nhap();
    CauKhop();
    Xuat();
}
