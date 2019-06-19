// Time: O(n)
// Space: O(n)

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>


using namespace std;
const int maxc = 1e6;
ifstream fi("BAI6.INP");
ofstream fo("BAI6.OUT");
int n;
vector <int> a;
bool Free[maxc];

int main(){
    fi >> n;
    memset(Free, true, sizeof(Free));
    int ain;
    for (int i=1; i<=n; i++){
        fi >> ain;
        if (Free[ain]){
            a.push_back(ain);
            Free[ain] = false;
        }
    }
    fo << a.size();
    fi.close();
    fo.close();
}