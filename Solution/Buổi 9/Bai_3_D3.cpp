// Time: O(len(s))
// Space: O(len(s))

/* Công Thức:
 ((q_1 + 1)*(q_2 + 1)*...*2^k)/((2^q_1)*(2^q_2)*...) - 2
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;
const int maxc = 2007;
const int mod = 1e7;
ifstream fi("GENE.INP");
ofstream fo("GENE.OUT");
string s, t;
int D[maxc];
vector <int> Q;
int K;

void Nhap(){
    fi >> s >> t;
    K = s.length() - t.length();
}

int Pow_2(int m){
    if (m == 0){
        return 1;
    }
    else if (m == 1){
        return 2;
    }
    else{
        ll m_2 = Pow_2(m/2);
        if (m & 1){
            return m_2*m_2*2%mod;
        }
        else{
            return m_2*m_2%mod;
        }
    }
}

void solve(){
    D[0] = -1;
    int k = 1;
    int j = 0;
    for (int i=0; i<s.length(); i++){
        if (s[i] == t[j]){
            j++;
            D[k] = i;
            k++;
        }
        if (j == t.length()){
            break;
        }
    }
    D[k] = s.length();
    for (int i=1; i <= k; i++){
        int count_d = 1;
        for (int j=D[i-1]+1; j<=D[i]-1; j++){
            if (s[j] == s[j+1]){
                count_d++;
            }
            else{
                Q.push_back(count_d);
                count_d = 1;
            }
        }
    }
    int sumofQ = 0;
    for (int i=0; i<Q.size(); i++){
        sumofQ += Q[i];
    }
    K = K - sumofQ;
    int res;
    res = Pow_2(K);
    for (int i=0; i<Q.size(); i++){
        res *= (Q[i] + 1);
    }
    res -= 2;
    fo << res;
}

int main(){
    Nhap();
    solve();
    fi.close();
    fo.close();
}
