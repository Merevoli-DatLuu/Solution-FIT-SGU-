// Time: O(1)
// Space: O(1)

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream fi("TETRAGON.INP");
ofstream fo("TETRAGON.OUT");
struct ToaDo{
    int x, y;
}A, B, C, D;
ToaDo X[5];

void Nhap(){
    fi >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    X[1] = A;
    X[2] = B;
    X[3] = C;
    X[4] = D;
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
    int c = CCW(X[0], p1, p2);
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

void solve(){
    int res = 0;
    sort(X, X + 5, Lower);
    A = X[1];
    B = X[2];
    C = X[3];
    D = X[4];
    if ((A.x - B.x)*(C.y - D.y) == (A.y - B.y)*(C.x - D.x) && (A.x - D.x)*(B.y - C.y) == (A.y - D.y)*(B.x - C.x)){ // AB // CD && AD // BC
        if ((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y) == (C.x - D.x)*(C.x - D.x) + (C.y - D.y)*(C.y - D.y) && (A.x - D.x)*(A.x - D.x) + (A.y - D.y)*(A.y - D.y) == (C.x - D.x)*(C.x - D.x) + (C.y - D.y)*(C.y - D.y)){ // AB = CD = AD
            if ((A.x - B.x)*(B.x - C.x) + (A.y - B.y)*(B.y - C.y) == 0){ // AB vuong goc CD
                res = 1;
            }
            else{
                res = 3;
            }
        }
        else{
            if ((A.x - B.x)*(B.x - C.x) + (A.y - B.y)*(B.y - C.y) == 0){ // AB vuong goc CD
                res = 2;
            }
            else{
                res = 4;
            }
        }
    }
    else{
        res = 5;
    }
    fo << res;
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
