// Time: O(n)
// Space: O(a^2) 
// 1 <= a <= 100
// Code này chưa clean lắm:))

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
typedef long long ll;
const int maxc = 1e5+1;
const int N = 101;
ifstream fi("CLUB.INP");
ofstream fo("CLUB.OUT");
struct T_1{
    int t1, t2;
}b1[N], b2[N]; //Đếm số lần xuất hiện của phần tử i,
int n;
int c1[N][N], c2[N][N]; // Đếm số lần xuất hiện của cặp i, j
vector <int> b1_t1[N], b1_t2[N], b2_t1[N], b2_t2[N]; // Tập Giá Trị của pt còn lại
bool Free1_t1[N], Free1_t2[N], Free2_t1[N], Free2_t2[N]; 
vector <int> A1[2], A2[2]; // Mảng lưu phần tử phân biệt
// t1, t2: pt1, pt2
// 1, 2: là phân Nam, Nữ

void Nhap(){
    fi >> n;
    memset(Free1_t1, true, sizeof(Free1_t1));
    memset(Free1_t2, true, sizeof(Free1_t2));
    memset(Free2_t1, true, sizeof(Free2_t1));
    memset(Free2_t2, true, sizeof(Free2_t2));
    int a1, a2, a3;
    for (int i=1; i<=n; i++){
        fi >> a1 >> a2 >> a3;
        if (a3 == 1){
            if (Free1_t1[a1]){
                A1[0].push_back(a1);
                Free1_t1[a1] = false;
            }
            if (Free1_t2[a2]){
                A1[1].push_back(a2);
                Free1_t2[a2] = false;
            }
            b1[a1].t1++;
            b1[a2].t2++;
            c1[a1][a2]++;
            if (c1[a1][a2] == 2){
                b1_t1[a1].push_back(a2);
                b1_t2[a2].push_back(a1);
            }
        }
        else{
            if (Free2_t1[a1]){
                A2[0].push_back(a1);
                Free2_t1[a1] = false;
            }
            if (Free2_t2[a2]){
                A2[1].push_back(a2);
                Free2_t2[a2] = false;
            }
            b2[a1].t1++;
            b2[a2].t2++;
            c2[a1][a2]++;
            if (c2[a1][a2] == 2){
                b2_t1[a1].push_back(a2);
                b2_t2[a2].push_back(a1);
            }
        }
    }
}

ll ToHop2(int k){
    return k*(k-1)/2;
}

void solve(){
    int res = 0;
    // Đếm số cặp Nam - Cột 1
    for (size_t i=0; i<A1[0].size(); i++){
        if (b1[ A1[0][i] ].t1 >= 2){
            int T = A1[0][i];
            res += ToHop2(b1[T].t1);
            for (size_t j=0; j<b1_t1[T].size(); j++){
                res -= ToHop2(c1[T][ b1_t1[T][j] ]);
            }
        }
    }
    // Đếm số cặp Nam - Cột 2
    for (size_t i=0; i<A1[1].size(); i++){
        if (b1[A1[1][i]].t2 >= 2){
            int T = A1[1][i];
            res += ToHop2(b1[T].t2);
            for (size_t j=0; j<b1_t2[T].size(); j++){
                res -= ToHop2(c1[b1_t2[T][j]][T]);
            }
        }
    }
    // Đếm số cặp Nữ - Cột 1
    for (size_t i=0; i<A2[0].size(); i++){
        if (b2[A2[0][i]].t1 >= 2){
            int T = A2[0][i];
            res += ToHop2(b2[T].t1);
            for (size_t j=0; j<b2_t1[T].size(); j++){
                res -= ToHop2(c2[T][b2_t1[T][j]]);
            }
        }
    }
    // Đếm số cặp Nữ - cột 2
    for (size_t i=0; i<A2[1].size(); i++){
        if (b2[A2[1][i]].t2 >= 2){
            int T = A2[1][i];
            res += ToHop2(b2[T].t2);
            for (size_t j=0; j<b2_t2[T].size(); j++){
                res -= ToHop2(c2[b2_t2[T][j]][T]);
            }
        }
    }
    fo << res;
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
