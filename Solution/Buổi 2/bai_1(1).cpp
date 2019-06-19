// Time: O(n*loglog(n))
// Space: O(n)
// Sàng Nguyên tố Eratosthenes
// Chạy Tốt Với n = 10^7

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int n;
bool *Sieve;
vector <int> Primes;

void Nhap(){
    cin >> n;
}

// Time: O(n*loglog(n))
void SieveofEratosthenes(){
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
    cout << Primes.size() << "\n";
}

//Time: O(n)
void SymmetricPrimes(){
    int res_1 = Primes.size();
    int res_2 = 0;
    for (int i=1; i<res_1-1; i++){
        if (Primes[i]*2 == Primes[i-1] + Primes[i+1]){
            res_2++;
        }
    }
    cout << res_2;
}

int main(){
    Nhap();
    SieveofEratosthenes();
    SymmetricPrimes();
}
