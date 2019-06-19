// Time: O(n*log(n)) (Worst)
// Space: O(1);

#include <iostream>
#include <algorithm>

using namespace std;

bool Compare (char a, char b){
    return a < b;
}

int main(){
    string n;
    cin >> n;
    int i = n.length()-2;
    while (n[i] >= n[i+1]){
        i--;
    }
    if (i >= 0){
        char minnum = '9';
        int u = 0;
        for (int j=i+1; j<=n.length()-1; j++){
            if (minnum >= n[j] && n[j] > n[i]){
                minnum = n[j];
                u = j;
            }
        }
        if (u != 0){
            swap(n[i], n[u]);
            sort(n.begin() + i + 1, n.end(), Compare);
        }
    }
    cout << n;
}
