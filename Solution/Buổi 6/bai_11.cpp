#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 10007, maxm = 100000007;
int n, m;
int a[maxn][maxn];

void Nhap(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            a[i][j] = 0;
        }
    }
    int u, v, c;
    for (int i=1; i<=m; i++){
        cin >> u >> v >> c;
        a[u][v] = c;
        a[v][u] = c;
    }
}

void EulerCircuit(){
    stack <int> Stack;
    Stack.push(1);
    while (!Stack.empty()){
        int u = Stack.top();
        for (int v=1; v<=n; v++){
            if (a[u][v] > 0){
                a[u][v]--;
                a[v][u]--;
                Stack.push(v);
                break;
            }
        }
        if (u == Stack.top()){
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
}

int main(){
    Nhap();
    EulerCircuit();
}
