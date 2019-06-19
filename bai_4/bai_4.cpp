// Time: O(n)
// Space: O(n)

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>


using namespace std;
ifstream fi("BAI4.INP");
ofstream fo("BAI4.OUT");
int n, m;
vector <int> a;
map <int, int> b;

void Nhap(){
    fi >> n >> m;
    int ain;
    for (int i=1; i<=n; i++){
        fi >> ain;
        a.push_back(ain);
        b[ain]++;
    }
}

void Xuly(){
    int Count = 0;
    for (int i=0; i<n; i++){
        if (a[i]*2 == m){
            Count += b[a[i]]-1;
        }
        else{
            Count += b[m - a[i]];
        }
    }
    fo << Count/2;
}

int main(){
    Nhap();
    Xuly();
    fi.close();
    fo.close();
}
