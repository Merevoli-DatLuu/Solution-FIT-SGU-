#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;
ifstream fi("bai1.INP");
ofstream fo("bai1.OUT");
vector <string> a;
int n;

void Nhap(){
    n = 0;
    string ain;
    while (!fi.eof()){
        getline(fi, ain);
        a.push_back(ain);
        n++;
    }
    n--;
}

void Cau_1(){
    fo << n << " ";
    int res_1 = 0;
    string fstr = "information technology";
    for (int i=0; i<=n-1; i++){
        for (int j=0; j<a[i].size(); j++){
            int k = 0;
            int ii = j;
            while (a[i][ii] == fstr[k] && k < fstr.length()){
                ii++;
                k++;
            }
            if (k == fstr.length()){
                res_1++;
                k = 0;
            }
        }
    }
    fo << res_1 << "\n";
}

void Cau_2(){
    int res_2a = 0;
    int res_2b = 0;
    int t = 0;
    for (int i=0; i<=n-1; i++){
        for (int j=0; j<a[i].size(); j++){
            if (a[i][j] == ' '){
                res_2a++;
                t = 0;
            }
            else{
                t++;
                if (res_2b < t){
                    res_2b = t;
                }
            }
        }
        t = 0;
        res_2a++;
    }
    fo << res_2a << " ";
    fo << res_2b << "\n";
}

void Cau_3(){
    int res_3a = 0;
    int res_3b = 0;
    int t = 0;
    for (int i=0; i <= n-1; i++){
        a[i] = a[i] + " ";
    }
    for (int i=0; i<=n-1; i++){
        for (int j=0; j<a[i].size(); j++){
            if (a[i][j] == 'a' || a[i][j] == 'e' || a[i][j] == 'i' || a[i][j] == 'u' || a[i][j] == 'o'){
                res_3a++;
                t++;;
            }
            else if (a[i][j] == ' '){
                if (t >= 0){
                    res_3b++;
                }
                t = 0;
            }
        }
        t = 0;
    }
    for (int i=0; i <= n-1; i++){
        a[i].erase(a[i].length()-1, 1);
    }
    fo << res_3a << " ";
    fo << res_3b << "\n";
}

void Cau_4(){
    int res_4a = 0;
    int res_4b = 0;
    string str;
    for (int i=0; i <= n-1; i++){
        a[i] = a[i] + " ";
    }
    for (int i=0; i <= n-1; i++){
        for (int j=0; j<a[i].size(); j++){
            if (a[i][j] != ' '){
                str = str + a[i][j];
            }
            else {
                if (res_4a < str.length()){
                    res_4a = str.length();
                }
                str = "";
                j = a[i].size();
            }
        }
    }
    fo << res_4a << " ";
    for (int i=0; i <= n-1; i++){
        int t = 0;
        for (int j=0; j<a[i].size(); j++){
            if (t == 0){
                if (a[i][j] == ' '){
                    t++;
                }
            }
            else if (t == 1){
                if (a[i][j] != ' '){
                    str = str + a[i][j];
                }
                else {
                    if (res_4b < str.length()){
                        res_4b = str.length();
                    }
                    str = "";
                    j = a[i].size();
                }
            }
        }
    }
    for (int i=0; i <= n-1; i++){
        a[i].erase(a[i].length()-1, 1);
    }
    fo << res_4b << "\n";
}

int H[1000007];

void Cau_5(){
    int res_5a = 0;
    int res_5b = 0;
    string str;
    for (int i=0; i <= n-1; i++){
        a[i] = a[i] + " ";
    }
    for (int i=0; i <= n-1; i++){
        for (int j=0; j<a[i].size(); j++){
            if (a[i][j] != ' '){
                str = str + a[i][j];
            }
            else {
                H[str.length()]++;
                if (res_5b < H[str.length()]){
                    res_5a = str.length();
                    res_5b = H[str.length()];
                }
                str = "";
            }
        }
    }
    for (int i=0; i <= n-1; i++){
        a[i].erase(a[i].length()-1, 1);
    }
    fo << res_5a << " ";
    fo << res_5b << "\n";
}

int main(){
    Nhap();
    Cau_1();
    Cau_2();
    Cau_3();
    Cau_4();
    Cau_5();
}
