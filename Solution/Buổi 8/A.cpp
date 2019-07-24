// Time: O(n*log(n))
// Space: O(1)

#include <iostream>

using namespace std;
int n;
int d[10];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int j = i;
        while (j != 0){
            d[j%10]++;
            j = j/10;
        }
    }
    for (int i=0; i<=9; i++){
        cout << d[i] << " ";
    }
}
