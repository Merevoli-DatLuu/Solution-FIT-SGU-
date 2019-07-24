// Time: O(t*n*|s|^2)
// Space: (n*|s|)

#include <iostream>
#include <cstring>

using namespace std;
int t, n;
string s[8];

void Nhap(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> s[i];
    }
}

int solve(){
    int u = 0;
    int min_str = 0x3f3f3f3f;
    for (int i=1; i<=n; i++){
        if (s[i].length() < min_str){
            min_str = s[i].length();
            u = i;
        }
    }
    swap(s[1], s[u]);
    for (int i=s[1].length(); i>=1; i--){
        for (int j=0; j<=s[1].length()-i; j++){
            bool found = true;
            for (int l=2; l<=n; l++){
                if (s[l].find(s[1].substr(j, i)) == string::npos){
                    found = false;
                    break;
                }
            }
            if (found){
                return i;
            }
        }
    }
}

int main(){
    cin >> t;
    for (int i=1; i<=t; i++){
        Nhap();
        cout << solve() << "\n";
    }
}
