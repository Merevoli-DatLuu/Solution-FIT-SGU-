// Time: O(log5(n))
// Space: O(1)

#include <iostream>

using namespace std;
unsigned int n;
int D[10];

// Số chữ số 0 của n! = min([2], [5]) = [5];
// [5] = n/5 + n/5^2 + ... + n/5^k (while n/5^k = 0)
unsigned int D5(unsigned int n){
    unsigned int U = 0, t = 5;
    while (n/t != 0){
        U += n/t;
        t *= 5;
    }
    return U;
}


// Chữ Số tận cùng khác 0 của n!
// D(N)=4D(⌊N/5⌋)⋅D(Units digit of N)(If tens digit of N is odd)
// D(N)=6D(⌊N/5⌋)⋅D(Units digit of N)(If tens digit of N is even)
void init(){
    D[0] = 1;
    D[1] = 1;
    D[2] = 2;
    D[3] = 6;
    D[4] = 4;
    D[5] = 2;
    D[6] = 2;
    D[7] = 4;
    D[8] = 2;
    D[9] = 8;
}


unsigned int DD(unsigned int n){
    if (n <= 9){
        return D[n];
    }
    else{
        if ((n/10) & 1){
            return 4*DD(n/5)*D[n%10]%10;
        }
        else{
            return 6*DD(n/5)*D[n%10]%10;
        }
    }
}

int main(){
    cin >> n;
    cout << D5(n) << "\n";
    init();
    cout << DD(n);
}

