// Time: O(n)
// Space: O(n)
// Sàng Nguyên Tố Atkin
// Chạy Tốt Với n = 10^7

#include <iostream>
#include <vector>

using namespace std; 
typedef long long ll;
ll n;
vector <int> Primes;

void Nhap(){
    cin >> n;
}

// Time: O(n)
void SieveOfAtkin(){ 
    Primes.push_back(2);
    Primes.push_back(3);
    bool* sieve; 
    sieve = new bool[n+1];
    for (ll i = 0; i <= n; i++) 
        sieve[i] = false; 
  
    for (ll x = 1; x * x <= n; x++) { 
        for (ll y = 1; y * y <= n; y++) { 
              
            // Main part of Sieve of Atkin 
            ll a = (4 * x * x) + (y * y); 
            if (a <= n && (a % 12 == 1 || a % 12 == 5)) 
                sieve[a] ^= true; 
  
            a = (3 * x * x) + (y * y); 
            if (a <= n && a % 12 == 7) 
                sieve[a] ^= true; 
  
            a = (3 * x * x) - (y * y); 
            if (x > y && a <= n && a % 12 == 11) 
                sieve[a] ^= true; 
        } 
    } 
  
    for (ll r = 5; r * r <= n; r++) { 
        if (sieve[r]) { 
            for (ll i = r * r; i <= n; i += r * r) 
                sieve[i] = false; 
        } 
    } 
    for (ll a = 5; a <= n; a++){
        if (sieve[a]){
            Primes.push_back(a);
        }
    }
    cout << Primes.size();
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
    SieveOfAtkin(); 
} 
