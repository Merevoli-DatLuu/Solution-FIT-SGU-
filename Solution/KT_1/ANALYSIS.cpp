#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 37;
ifstream fi("ANALYSIS.INP");
ofstream fo("ANALYSIS.OUT");
int n;
int X[maxn];
int T[maxn];
int res ;

void Nhap();
void QuayLui(int i);
void Xuat(int k);

void Nhap(){
    fi >> n;
    res = 0;
    X[0] = 1;
    T[0] = 0;
}

void QuayLui(int i){
    for (int j = X[i-1]; j<= n - T[i-1]; j++){
        X[i] = j;
        T[i] = T[i-1] + j;
        if (T[i] == n){
            //Xuat(i);
            res++;
        }
        else{
            QuayLui(i + 1);
        }
    }
}

//void Xuat(int k){
//    for (int i=1; i<=k; i++){
//        cout << X[i] << " ";
//    }
//    cout << "\n";
//}

int main(){
    Nhap();
    QuayLui(1);
    fo << res - 1;
    fi.close();
    fo.close();
}
