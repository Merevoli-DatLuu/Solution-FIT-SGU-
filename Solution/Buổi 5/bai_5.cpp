// Code tạm
// fail quá:((
// Nếu đề cho đi xuống và phải hoặc lên và trái là được rồi

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int maxc = 1e6, maxcc = 107;
const int inf = 0x3f3f3f3f;
struct T_1{
    int x, y;
}k[5], s, f, X[maxc];
int n, m;
int a[maxcc][maxcc];
bool Free[maxcc][maxcc];
int res = inf;
int T[maxc];

void Nhap(){
    cin >> m >> n >> s.x >> s.y >> f.x >> f.y;
    memset(Free, true, sizeof(Free));
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    X[0].x = s.x;
    X[0].y = s.y;
    T[0] = 0;
    Free[s.y][s.x] = false;
    k[1].x = 1;
    k[2].x = 0;
    k[3].x = -1;
    k[4].x = 0;
    k[1].y = 0;
    k[2].y = 1;
    k[3].y = 0;
    k[4].y = -1;
}

bool Check(int i, int j){
    return (i >= 1 && i <= m && j >= 1 && j <= n);
}

void QuayLui(int i){
    for (int j=1; j<=4; j++){
        if (Free[X[i-1].y + k[j].y][X[i-1].x + k[j].x] && Check(X[i-1].y + k[j].y, X[i-1].x + k[j].x) && T[i-1] < res){
            X[i].y = X[i-1].y + k[j].y;
            X[i].x = X[i-1].x + k[j].x;
            cout << X[i].x << " " << X[i].y << "\n";
            T[i] = max(T[i-1], (int)abs(a[X[i].y][X[i].x] - a[X[i-1].y][X[i-1].x]));
            if (X[i].x == f.x && X[i].y == f.y){
                if (T[i] < res){
                    res = T[i];
                }
            }
            else{
                Free[X[i].y][X[i].x] = false;
                QuayLui(i+1);
                Free[X[i].y][X[i].x] = true;
            }
        }
    }
}

int main(){
    Nhap();
    QuayLui(1);
    cout << res;
}
