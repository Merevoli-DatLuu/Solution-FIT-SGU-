#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
const int maxn = 10007, maxm = 10000007;
int n, m;
stack <int> Stack;
bool a[maxn][maxn];
bool Free[maxn];
int Low[maxn];
int Number[maxn];
int Count = 0;
int found = 0;

void Nhap(){
    cin >> n >> m;
    memset(Free, true, sizeof(Free));
    memset(a, false, sizeof(a));
    for (int i=1; i<=n; i++){
        Low[i] = 0;
        Number[i] = 0;
    }
    int u, v;
    for (int i=1; i<=m; i++){
        cin >> u >> v;
        a[u][v] = true;
    }
}

void Visit(int u){
    Count++;
    Number[u] = Count;
    Low[u] = Count;
    Stack.push(u);
    for (int v=1; v<=n; v++){
        if (a[u][v] && Free[v]){
            if (Number[v] == 0){
                Visit(v);
                Low[u] = min(Low[u], Low[v]);
            }
            else{
                Low[u] = min(Low[u], Number[v]);
            }
        }
    }
    if (Number[u] == Low[u]){
        int v;
        do{
            v = Stack.top();
            Stack.pop();
            Free[v] = false;
            cout << v << " ";
        }
        while (u != v);
        found++;
        cout << "\n";
    }
}

void Tarjan(){
    for (int i=1; i<=n; i++){
        if (Number[i] == 0){
            Visit(i);
        }
    }
    if (found == 1){
      cout << "YES";
    }
    else{
      cout << "NO";
    }
}

int main(){
    Nhap();
    Tarjan();
}
