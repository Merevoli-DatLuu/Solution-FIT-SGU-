// Time: O(n)
// Space: O(n)

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>


using namespace std;
typedef long long ll;
ifstream fi("BAI5.INP");
ofstream fo("BAI5.OUT");
int n;
vector <ll> a;
map < ll, vector <int> > b;

void Nhap(){
    fi >> n;
    int ain;
    for (int i=1; i<=n; i++){
        fi >> ain;
        a.push_back(ain);
    }
}

void Xuly(){
    int res = 0;
    
    for (int i=1; i<n; i++){
        a[i] = a[i-1] + a[i];
    }
    
    for (int i=0; i<n; i++){
        b[a[i]].push_back(i);
    }
    
    for (int i=0; i<n; i++){
        int t = b[a[i]].size();
        if (t >= 2){
            if (res < b[a[i]][t-1] - b[a[i]][0]){
                res = b[a[i]][t-1] - b[a[i]][0];
            }    
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