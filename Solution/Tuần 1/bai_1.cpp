// Time: O(n)

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
ifstream fi("BAI1.INP");
ofstream fo("BAI1.OUT");
int n;
vector <int> a;

void Nhap(){
    fi >> n;
    int ain;
    for (int i=1; i<=n; i++){
        fi >> ain;
        a.push_back(ain);
    }
}

void Xuly(){
    int res = 1;
    int t = 1;
    for (int i=1; i<a.size(); i++){
        if (a[i] >= a[i-1]){
            t++;
            if (t > res){
                res = t;
            }
        }
        else{
            t = 1;
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
