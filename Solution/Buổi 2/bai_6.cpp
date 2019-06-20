// Time: O(log(log10(n))*log10(n)^2)
// Space: O(n)
// p thuộc [2, 132]; log2(10^40) = 132 

#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

bool *Sieve;
vector <int> Primes;

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

void SieveofEratosthenes(int n){
    Sieve = new bool[n+1];
    for (int i=1; i<=n; i++){
        Sieve[i] = true;
    }
    Sieve[0] = false;
    Sieve[1] = false;
    for (int i=2; i*i <= n; i++){
        if (Sieve[i]){
            for (int j= i*i; j<=n; j+=i){
                Sieve[j] = false;
            }
        }
    }
    for (int i=2; i<=n; i++){
        if (Sieve[i]){
            Primes.push_back(i);
        }
    }
}

void less32(){
    for (int i=0; Primes[i] < 32; i++){
        cout << (1 << Primes[i]) - 1 << "\n";
    }
}

string mu2(int n){
    if (n == 0){
        return "1";
    }
    if (n == 1){
        return "2";
    }
    string F2 = mu2(n/2);
    if (n%2 == 0){
        return Mul(F2, F2);
    }
    else{
        return mul_e(Mul(F2, F2),2);
    }
}

void more32(){
    int n = Primes.size()-1;
    // Primes[11] > 32
    for (int i = 11; i <= n; i++){
        cout << Sub(mu2(Primes[i]), "1") << "\n";
    }
}

void solve(){
    SieveofEratosthenes(132);
    less32();
    more32();
}

int main(){
    solve();
}
