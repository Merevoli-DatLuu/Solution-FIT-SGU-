// Time: O(n*|s|)
// Space: O(|s|)

#include <iostream>
#include <fstream>

using namespace std;
const int maxn = 10007;
ifstream fi("WLOOP.INP");
ofstream fo("WLOOP.OUT");
int n;
string s;

bool Check_str(string a){
    string b;
    b = a[0];
    for (int i=1; i<a.length(); i++){
        if (b[0] != a[i] || a.length()%b.length() != 0){
            b = b + a[i];
        }
        else{
            string tmp_b;
            int j = i;
            bool found = true;
            while (found && j < a.length()){
                if (a[j] == b[j%b.length()]){
                    tmp_b = tmp_b + a[j];
                    j++;
                }
                else{
                    found = false;
                }
            }
            if (found){
                return true;
            }
            else{
                i = j-1;
                b = b + tmp_b;
            }
        }
    }
    return false;
}

void solve(){
    fi >> n;
    int res = 0;
    for (int i=1; i<=n; i++){
        fi >> s;
        if (Check_str(s)){
            res++; 
        }
    }
    fo << res;
}

int main(){
    solve();
    fi.close();
    fo.close();
}
