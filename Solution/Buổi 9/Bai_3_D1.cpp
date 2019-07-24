// Time: O(1)
// Space: O(1)

#include <iostream>
#include <fstream>

using namespace std;
ifstream fi("TETRAGON.INP");
ofstream fo("TETRAGON.OUT");
struct ToaDo{
    int x, y;
}A, B, C, D;

void Nhap(){
    fi >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
}

void solve(){
    int res = 0;
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
