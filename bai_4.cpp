// Time: (log(n)*log10(n)^2)
// Space: O(1)

#include <iostream>

using namespace std;
const int maxc = 100007;
typedef long long ll;
int n;
ll D[maxc];
string D2[maxc];

int Compare(string a, string b);
string Sum(string a, string b);
string Sub(string a, string b);
string mul_e(string a, int e);
string Mul(string a, string b);

int Compare(string a, string b){
    while (a.length() < b.length()){
        a = "0" + a;
    }
    while (a.length() > b.length()){
        b = "0" + b;
    }
    if (a > b){
        return 1; 
    }
    else if (a == b){
        return 0;
    }
    else{
        return -1;
    }
}

string Sum(string a, string b){
    while (a.length() < b.length()){
        a = "0" + a;
    }
    while (b.length() < a.length()){
        b = "0" + b;
    }
    string c;
    int ssum;
    int nho = 0;
    for (int i=a.length() - 1; i>=0; i--){
        ssum = (int)a[i] -48 + (int)b[i] - 48 + nho;
        nho = ssum/10;
        c = char(ssum%10 + 48) + c;
    }
    if (nho == 1){
        c = "1" + c;
    }
    return c;
}

string Sub(string a, string b){
    while (a.length() < b.length()){
        a = "0" + a;
    }
    while (b.length() < a.length()){
        b = "0" + b;
    }
    bool dau = true;
    if (a < b){
        swap(a, b);
        dau = false;
    }
    string c;
    int nho = 0;
    int ssub;
    for (int i=a.length()-1; i>=0; i--){
        ssub = (int)a[i] -(int)b[i] - nho;
        if (ssub < 0){
            nho = 1;
            ssub += 10;
        }
        else{
            nho = 0;
        }
        c = char(ssub%10 + 48) + c;
    }
    while (c.length() > 1 && c[0] == '0'){
        c.erase(0,1);
    }
    if (!dau){
        c = "-" + c;
    }
    return c;
}

string mul_e(string a, int e){
    string c;
    int ssum;
    int nho = 0;
    for (int i=a.length() - 1; i>=0; i--){
        ssum = ((int)a[i] -48)*e + nho;
        nho = ssum/10;
        c = char(ssum%10 + 48) + c;
    }
    if (nho > 0){
        c = char(nho + 48) + c;
    }
    return c;
}

string Mul(string a, string b){
    string c;
    string mmul;
    for (int i=b.length()-1; i>=0; i--){
        c = Sum(c, mul_e(a, (int)b[i] - 48) + mmul);
        mmul = mmul + "0";
    }
    return c;
}

// Time: O(log(n))
// F[0] = 0
// F[1] = 1
// F[n] = F[n/2]^2 + F[n/2+1]*2 if n%2 == 1
// F[n] = F[n/2]^2 + 2*F[n/2-1]*F[n/2] if n%2 == 0
// Đệ Quy kết hợp với Bảng Lưu
string Fibo(int n){
    if (D2[n] == ""){
        if (n == 0){
            D2[n] = "0";
        }
        else if (n == 1){
            D2[n] = "1";
        }
        else{
            if (n & 1){
                string Fn = Fibo(n/2);
                string Fn1 = Fibo(n/2 + 1);
                D2[n] = Sum(Mul(Fn, Fn), Mul(Fn1, Fn1));
            }
            else{
                string Fn = Fibo(n/2);
                string Fn1 = Fibo(n/2 - 1);
                D2[n] = Sum(Mul(Fn, Fn), mul_e(Mul(Fn, Fn1), 2));
            }
        }
    }
    return D2[n];
}

int main(){
    string a, b;
    cin >> a >> b;
    int i = 1;
    while (Compare(Fibo(i), a) == -1){
        i++;
    }
    int j = i;
    while (Compare(Fibo(j), b) == -1){
        j++;
    }
    j--;
    cout << j - i + 1;
}
