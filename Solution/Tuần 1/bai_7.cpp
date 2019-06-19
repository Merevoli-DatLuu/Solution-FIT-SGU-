// Time: O(n*sqrt(n))
// Space: O(1)

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;
ifstream fi("BAI7.INP");
ofstream fo("BAI7.OUT");
int n;

void Nhap(){
    fi >> n;
}

int TongUoc(int a){
    int T = 1;
    int t = sqrt(a);
    for (int i = 2; i <= t; i++){
        if (a%i == 0){
            T += i + a/i;
        }
    }
    if (t*t == a){
        T -= t;
    }
    return T;
}

void Xuly(){
    int res = 0;
    for (int i=1; i<=n; i++){
        int t = TongUoc(i);
        if (t > i && TongUoc(t) == i){
            res++;
        }
    }
    fo << res;
}

int main(){
    Nhap();
    Xuly();
    fi.close();
    fo.close();
}