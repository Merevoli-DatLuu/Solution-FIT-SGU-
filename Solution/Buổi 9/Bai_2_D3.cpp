// Time: O(n^2*m^2)
// Space: O(n^2)

#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 100;
ifstream fi("MUSHROOM.INP");
ofstream fo("MUSHROOM.OUT");
struct TD{
    int x, y;
}k[3];
int n, m;
int a[maxn][maxn];
int Trace[maxn][maxn];
int res;

void Nhap(){
    fi >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            fi >> a[i][j];
        }
    }
    k[1].x = 1;
    k[2].x = 0;
    k[1].y = 0;
    k[2].y = 1;
}

void DFS(TD u){
    for (int i=1; i<=2; i++){
        if (u.y + k[i].y >= 1 && u.y + k[i].y <= n && u.x + k[i].x >= 1 && u.x + k[i].x <= m){
            if (a[u.y + k[i].y][u.x + k[i].x] == 0){
                TD f = u;
                while (f.x != 1 || f.y != 1){
                    int ii = Trace[f.y][f.x];
                    if (a[f.y][f.x] != a[f.y - k[ii].y][f.x - k[ii].x] && a[f.y - k[ii].y][f.x - k[ii].x] != 0 && a[f.y][f.x] != 0){
                        res++;
                        break;
                    }
                    f.y = f.y - k[ii].y;
                    f.x = f.x - k[ii].x;
                }
            }
            else if (a[u.y + k[i].y][u.x + k[i].x] != -1){
                Trace[u.y + k[i].y][u.x + k[i].x] = i;
                TD v;
                v.y = u.y + k[i].y;
                v.x = u.x + k[i].x;
                DFS(v);
            }
        }
    }
}

int main(){
    Nhap();
    res = 0;
    TD u;
    u.x = 1;
    u.y = 1;
    DFS(u);
    if (res != 0){
        fo << res;
    }
    else{
        fo << -1;
    }
}
