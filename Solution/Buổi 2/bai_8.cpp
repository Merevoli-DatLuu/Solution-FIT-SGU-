// Time: O(max(m, n))
// Space: O(max(m, n))

#include <iostream>

using namespace std;
string a, b;

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

int main(){
    cin >> a >> b;
    cout << Sum(a, b);
}
