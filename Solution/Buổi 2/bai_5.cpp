// Time: O(log10(n))
// Space: O(1)

#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;
ll n;

void Nhap(){
    cin >> n;
}

int NumbersofDigits(){
    if (n <= 9){
        return 1;
    }
    ll i = 9;
    int k = 1;
    ll S = i*k;
    while (S < n){
        i *= 10;
        k++;
        S += i*k;
    }
    return k;
}

void solve(){
    int k = NumbersofDigits();
    if (k == 1){
        cout << n;
    }
    else{
        ll i = 9;
        int k = 1;
        ll S = i*k;
        while (S < n){
            i *= 10;
            k++;
            S += i*k;
        }
        S -= (i)*(k);
        // Phần Dư
        ll N = n - S;
        // Số Lượng Số có k chữ số của Phần Dư
        ll a = (N-1)/k; 
        // Vị Trí
        int b = k - (N-1)%k - 1; 
        i += pow(10, k-1);
        // Số chứa Chữ Số n
        a = a + i/10; 
        for (int j=1; j<=b; j++){
            a /= 10;
        }
        cout << a%10;
    }
}

int main(){
    cin >> n;
    solve();
}
