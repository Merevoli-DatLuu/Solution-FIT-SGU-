// Time: O(b*log(log(b)))
// Space: O(b)

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 100007;
struct TD{
    int a, b, k, s;
}X[21];
int t;
int max_b;
bool *Sieve;
vector <int> Primes;

void Nhap(){
    cin >> t;
    max_b = 0;
    for (int i=1; i<=t; i++){
        cin >> X[i].a >>X[i]. b >> X[i].k >> X[i].s;
        if (max_b < X[i].b){
            max_b = X[i].b;
        }
    }
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

bool Check_Primes(int ab){
    return Sieve[ab];
}

bool Check_Tuple(int begi, int cont, int dist){
    if (Check_Primes(begi) && Check_Primes(begi+dist)){
        int ct = 2;
        for (int i=begi+1; i<begi + dist; i++){
            if (Check_Primes(i)){
                ct++;
            }
        }
        if (ct == cont){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int solve(int a, int b, int k, int s){
    int res = 0;
    if (s%2 == 1){
        if (a > 2){
            return 0;
        }
        else if (Check_Tuple(a, k, s)){
            return 1;
        }
    }
    else{
        if (a%2 == 0){
            a++;
        }
        for (int i=0; i<s; i+=2){
            for (int j=a+i; j <= b; j+=2*s){
                if (Check_Primes(j)){
                    if (Check_Primes(j - s) && j - s >= a){
                        if (Check_Tuple(j - s, k, s)){
                            res++;
                        }
                    }
                    if (Check_Primes(j + s)){
                        if (Check_Tuple(j, k ,s)){
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
}

int main(){
    Nhap();
    SieveofEratosthenes(max_b);
    for (int i=1; i<=t; i++){
        cout << solve(X[i].a, X[i].b, X[i].k, X[i].s) << "\n";
    }
}
