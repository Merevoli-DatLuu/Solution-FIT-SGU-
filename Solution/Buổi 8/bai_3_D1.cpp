// Time: O(|s|)
// Space: O(|s|)

#include <iostream>
#include <fstream>

using namespace std;
ifstream fi("TRACE.INP");
ofstream fo("TRACE.OUT");
struct ToaDo{
    int x, y;
}s, f, k[5];
string T;

void Nhap(){
    fi >> s.x >> s.y >> f.x >> f.y;
    fi >> T;
    k[1].x = 1; // E
    k[2].x = 0; // N
    k[3].x = -1; // W
    k[4].x = 0; // S
    k[1].y = 0;
    k[2].y = 1;
    k[3].y = 0;
    k[4].y = -1;
}

void solve(){
    int sx = s.x;
    int sy = s.y;
    int t;
    for (int i=0; i<T.length(); i++){
        if (T[i] == 'E'){
            sx += k[1].x;
            sy += k[1].y;
        }
        else if (T[i] == 'N'){
            sx += k[2].x;
            sy += k[2].y;
        }
        else if (T[i] == 'W'){
            sx += k[3].x;
            sy += k[3].y;
        }
        else if (T[i] == 'S'){
            sx += k[4].x;
            sy += k[4].y;
        }
        else{
            t = i;
        }
    }
    if (sx == f.x && sy == f.y){
        T[t-1] = 'E';
        T[t] = 'W';
    }
    else if (sx + 2 == f.x && sy == f.y){
        T[t-1] = 'E';
        T[t] = 'E';
    }
    else if (sx - 2== f.x && sy == f.y){
        T[t-1] = 'W';
        T[t] = 'W';
    }
    else if (sx == f.x && sy + 2 == f.y){
        T[t-1] = 'N';
        T[t] = 'N';
    }
    else if (sx == f.x && sy - 2 == f.y){
        T[t-1] = 'S';
        T[t] = 'S';
    }
    else if (sx + 1 == f.x && sy + 1 == f.y){
        T[t-1] = 'E';
        T[t] = 'N';
    }
    else if (sx + 1 == f.x && sy - 1 == f.y){
        T[t-1] = 'E';
        T[t] = 'S';
    }
    else if (sx - 1 == f.x && sy + 1 == f.y){
        T[t-1] = 'N';
        T[t] = 'W';
    }
    else if (sx - 1 == f.x && sy - 1 == f.y){
        T[t-1] = 'S';
        T[t] = 'W';
    }
    fo << T;
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
