// Time: O(|s|)
// Space: O(|s|)

#include <iostream>
#include <fstream>
#include <vector>

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

int GiaiThua(int c){
    return (c == 0 || c == 1)?1:c*GiaiThua(c-1);
}

void solve(){
    int sx = s.x;
    int sy = s.y;
    vector <int> loc;
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
            loc.push_back(i);
        }
    }
    int Es = max(f.x - sx, 0);
    int Ws = max(sx - f.x, 0);
    int Ns = max(f.y - sy, 0);
    int Ss = max(sy - f.y, 0);
    int t = Es + Ws + Ss + Ns;
    t = loc.size() - t;
    t = t/2;
    Es += t;
    Ws += t;
    for (int i=0; i<loc.size(); i++){
        if (Es > 0){
            T[loc[i]] = 'E';
            Es--;
        }
        else{
            if (Ws > 0){
                T[loc[i]] = 'W';
                Ws--;
            }
            else{
                if (Ss > 0){
                    T[loc[i]] = 'S';
                    Ss--;
                }
                else {
                    T[loc[i]] = 'N';
                    Ns--;
                }
            }
        }
    }
    int res = 0;
    Es = max(f.x - sx, 0);
    Ws = max(sx - f.x, 0);
    Ns = max(f.y - sy, 0);
    Ss = max(sy - f.y, 0);
    Es += t;
    Ws += t;
    res += GiaiThua(Es + Ws + Ns + Ss)/(GiaiThua(Es)*GiaiThua(Ws)*GiaiThua(Ns)*GiaiThua(Ss));
    for (int i=2; i<=t; i++){
        Es--;
        Ws--;
        Ns++;
        Ss++;
        res += GiaiThua(Es + Ws + Ns + Ss)/(GiaiThua(Es)*GiaiThua(Ws)*GiaiThua(Ns)*GiaiThua(Ss));
    }
    fo << res << "\n";
    fo << T;
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
