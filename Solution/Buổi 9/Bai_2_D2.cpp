// Time: O(n*log10(n))
// Space: O(1)

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
ifstream fi("NUMSEQ.INP");
ofstream fo("NUMSEQ.OUT");
int n;
string s;

void Nhap(){
    fi >> n;
}

void solve(){
    s = "0";
    for (int i=1; i<=n; i++){
        bool digit[10];
        memset(digit, true, sizeof(digit)); // Đánh dấu các chữ số của a
        bool found = true; // Kiểm tra a[i-1] có chữ số 9 hay không
        int max_digit = 0; // Chữ số lớn nhất của a[i-1]
        for (int i=0; i<s.length(); i++){
            digit[(int)s[i] - 48] = false;
            if ((int)s[i] - 48 == 9){
                found = false;
            }
            if (max_digit < (int)s[i] - 48){
                max_digit = (int)s[i] - 48;
            }
        }
        if (found){// a[i-1] Không có 9
            int k;
            for (int i=0; i<=9; i++){
                if (digit[i]){
                    k = i;
                    break;
                }
            }
            string new_s;
            new_s += char(max_digit + 49);
            for (int i=1; i<=s.length() - 1; i++){
                new_s = new_s  + char(k + 48);
            }
            s = new_s;
        }
        else{
            int k;
            for (int i=0; i<=9; i++){
                if (digit[i]){
                    k = i;
                    break;
                }
            }
            string new_s;
            if (k == 0){
                int dau = k + 1;
                while (!digit[dau] && dau <= 9){
                    dau++;
                }
                new_s += char(dau + 48);
                for (int i=0; i<s.length(); i++){
                    new_s = new_s + char(k + 48);
                }
            }
            else{
                for (int i=0; i<=s.length(); i++){
                    new_s = new_s + char(k + 48);
                }
            }
            s = new_s;
        }
    }
    fo << s;
}


int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}

