#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 1007;
ifstream fi("TICKET.INP");
ofstream fo("TICKET.OUT");
struct TD_1{
    int a, b;
}X[maxn];
int n, k;

void Nhap(){
    fi >> n >> k;
    for (int i=1; i<=n; i++){
        fi >> X[i].a >> X[i].b;
    }
}

void solve(){
    int t1, t2, res_min, res_max;
    t1 = 0;
    t2 = 0;
    res_min = 0;
    res_max = 0;
    // Tim res_max
    for (int i=1; i<=n; i++){
        t2 += X[i].a;
        if (t2 < X[i].b){
            res_max += t2;
            t1 -= -t2;
            t2 = 0;
        }
        else{
            res_max = X[i].b;
        }
        if (i%k == 1){
            t1 += t2;
            t2 = 0;
        }
    }
    // Tim res_min
    t1 = 0;
    t2 = 0;
    for (int i=1; i<=n; i++){
        t2 += X[i].a;
        if (t1 > X[i].b){
            res_min += 0;
            t1 = t1 - X[i].b;
        }
        else{
            res_min += X[i].b - t1;
            t2 -= (X[i].b - t1);
            t1 = 0;
        }
        if (i%k == 1){
            t1 += t2;
            t2 = 0;
        }
    }
    fo << res_min << " " << res_max;
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
