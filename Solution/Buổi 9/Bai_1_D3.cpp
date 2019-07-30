// Time: O(n)
// Space: O(n)

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;
const int maxn = 107;
const float e = 1e-4;
ifstream fi("HEXAGONS.INP");
ofstream fo("HEXAGONS.OUT");
struct ToaDo{
    float x, y;
};
struct LucGiac{
    ToaDo A, B, C, D, E, F;
}X[maxn];
int n;
ToaDo D[6];
LucGiac DX;

istream& operator >> (istream &in, ToaDo &a){
    in >> a.x >> a.y;
    return in;
}

ostream& operator << (ostream &on, ToaDo b){
    on << b.x << " " << b.y;
    return on;
}

istream& operator >> (istream &in, LucGiac &a){
    in >> a.A >> a.B >> a.C >> a.D >> a.E >> a.F;
    return in;
}

ostream& operator << (ostream &on, LucGiac b){
    on << b.A << "-" << b.B << "-" << b.C << "-" << b.D << "-" << b.E << "-" << b.F << "\n";
    return on;
}

void Nhap(){
    fi >> n;
    for (int i=1; i<=n; i++){
        fi >> X[i];
    }
}

int CCW(ToaDo p1, ToaDo p2, ToaDo p3){
    int a1 = p2.x - p1.x;
    int b1 = p2.y - p1.y;
    int a2 = p3.x - p2.x;
    int b2 = p3.y - p2.y;
    int t  = a1*b2 - a2*b1;
    if (t == 0){
        return 0;
    }
    else if (t < 0){
        return -1;
    }
    else{
        return 1;
    }
}

bool Lower(ToaDo p1, ToaDo p2){
    int c = CCW(D[0], p1, p2);
    if (c > 0){
        return true;
    }
    else if (c == 0 && (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y))){
        return true;
    }
    else{
        return false;
    }
}

float DoDai(ToaDo a, ToaDo b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool Check_LucGiac(LucGiac a){
    float AB = DoDai(a.A, a.B);
    float BC = DoDai(a.B, a.C);
    float CD = DoDai(a.C, a.D);
    float DE = DoDai(a.D, a.E);
    float EF = DoDai(a.E, a.F);
    float AD = DoDai(a.A, a.D);
    float BE = DoDai(a.B, a.E);
    float CF = DoDai(a.C, a.F);
    bool f1 = false, f2 = false;
    if (fabs(AB - BC) <= e && fabs(BC - CD) <= e && fabs(CD - DE) <= e && fabs(DE - EF) <= e){
        f1 = true;
    }
    if (fabs(AD - BE) <= e && fabs(BE - CF) <= e){
        f2 = true;
    }
    if (f1 && f2){
        return true;
    }
    else{
        return false;
    }
}

void solve(){
    for (int i=1; i<=n; i++){
        D[0] = X[i].A;
        D[1] = X[i].B;
        D[2] = X[i].C;
        D[3] = X[i].D;
        D[4] = X[i].E;
        D[5] = X[i].F;
        sort(D, D + 6, Lower);
        DX.A = D[0];
        DX.B = D[1];
        DX.C = D[2];
        DX.D = D[3];
        DX.E = D[4];
        DX.F = D[5];
        if (Check_LucGiac(DX)){
            fo << "Y";
        }
        else{
            fo << "N";
        }
    }
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
