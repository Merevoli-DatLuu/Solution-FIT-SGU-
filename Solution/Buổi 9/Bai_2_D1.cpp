// Time: O(|Q|)
// Space: O(1)

#include <iostream>
#include <fstream>

using namespace std;
ifstream fi("LETTER.INP");
ofstream fo("LETTER.OUT");
string Q;
int k;
string res;

void Nhap(){
    fi >> Q >> k;
}

void solve(){
    for (int i=0; i<=k-1; i++){
        res = Q[i] + res;
    }
    for (int i=Q.length()-1; i >= k; i--){
        res = res + Q[i];
    }
    fo << res;
}

int main(){
    Nhap();
    solve();
}
