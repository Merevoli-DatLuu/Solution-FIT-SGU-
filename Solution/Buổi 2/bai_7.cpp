// Time: O(|s|)
// Space: O(|s|)
// Code này không clean cho lắm
// Về sau sửa lại

#include <iostream>

using namespace std;
string s;
int a, b;

int Compare(string a, string b);
string Sum(string a, string b);
string Sub(string a, string b);
string mul_e(string a, int e);
string Mul(string a, string b);
string div_e(string a, int e);
string mod_e(string a, int e);

int Compare(string a, string b){
    while (a.length() < b.length()){
        a = "0" + a;
    }
    while (a.length() > b.length()){
        b = "0" + b;
    }
    
    if (a < b){
        return -1;
    }
    else if (a == b){
        return 0;
    }
    else{
        return 1;
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

string div_e(string a, int e){
    string c;
    int thuong = 0;
    int du = 0;
    for (int i=0; i<=a.length()-1; i++){
        du = du*10 + (int)a[i] - 48;
        thuong = du/e;
        du = du%e;
        c = c + char(thuong + 48);
    }
    while (c.length() > 1 && c[0] == '0')
        c.erase(0,1);
    return c;
}

string mod_e(string a, int e){
    return Sub(a, mul_e(div_e(a, e), e));
}

string operator * (string a, int e){
    return mul_e(a, e);
}

string operator / (string a, int e){
    return div_e(a, e);
}

string operator % (string a, int e){
    return mod_e(a, e);
}


void Nhap(){
    cin >> s;
    cin >> a >> b;
}

string Todecimal(string s, int a){
    string res_Todecimal;
    string t_a = "1";
    for (int i=s.length()-1; i>=0; i--){
        if (s[i] <= '9'){
            res_Todecimal = Sum(res_Todecimal, (t_a*((int)s[i] - 48 )));
        }
        else{
            if (s[i] == 'A'){
                res_Todecimal = Sum(res_Todecimal, (t_a*10));
            }
            else if (s[i] == 'B'){
                res_Todecimal = Sum(res_Todecimal, (t_a*11));
            }
            else if (s[i] == 'C'){
                res_Todecimal = Sum(res_Todecimal, (t_a*12));
            }
            else if (s[i] == 'D'){
                res_Todecimal = Sum(res_Todecimal, (t_a*13));
            }
            else if (s[i] == 'E'){
                res_Todecimal = Sum(res_Todecimal, (t_a*14));
            }
            else{
                res_Todecimal = Sum(res_Todecimal, (t_a*15));
            }
        }
        t_a = t_a*a;
    }
    return res_Todecimal;
}

string Tob(string s, int b){
    string res_Tob;
    while (s != "0"){
        if (Compare(s%b, "9") <= 0){
            res_Tob = s%b + res_Tob;
        }
        else{
            if (s%b == "10"){
                res_Tob = "A" + res_Tob;
            }
            else if (s%b == "11"){
                res_Tob = "B" + res_Tob;
            }
            else if (s%b == "12"){
                res_Tob = "C" + res_Tob;
            }
            else if (s%b == "13"){
                res_Tob = "D" + res_Tob;
            }
            else if (s%b == "14"){
                res_Tob = "E" + res_Tob;
            }
            else if (s%b == "15"){
                res_Tob = "F" + res_Tob;
            }
        }
        s = s/b;
    }
    return res_Tob;
}

int main(){
    Nhap();
    cout << Tob(Todecimal(s, a), b);
}
