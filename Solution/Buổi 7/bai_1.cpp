// Time: O(m*log(m))
// Space: O(max(m, n))

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 10007, maxm = 1000007; // maxn: Số Đỉnh Tối Đa, maxm: Số Cạch Tối Đa
struct Edge{
    int u, v, w;
};
int n, m; // n: Số Đỉnh, m: Số Đỉnh
vector <Edge> E; // Danh Sách Cạnh
vector <Edge> MST; // Danh Sách Cạnh của Cây Khung Nhỏ Nhất
int Bac[maxn], Root[maxn]; // Số Bậc và Nút Gốc
int MST_Weight;

// Nhập Input
void Nhap(){
    cin >> n >> m;
    Edge E_in;
    for (int i=1; i<=m; i++){
        cin >> E_in.u >> E_in.v >> E_in.w;
        E.push_back(E_in);
    }
}

// Khởi Tạo Bậc và Root
void init(){
    for (int i=1; i<=n; i++){
        Bac[i] = 0;
        Root[i] = i;
    }
}

// Tìm Root của u
int Find(int u){
    if (Root[u] != u)
        Root[u] = Find(Root[u]);
    return Root[u]; 
}

// Kiểm Tra xem có Join được không
bool Join(int u, int v){
    u = Find(u);
    v = Find(v);
    if (u == v){ // Gốc của u, v chung 1 cây
        return false;
    }
    if (Bac[u] == Bac[v]){
        Bac[u]++;
    }
    if (Bac[u] < Bac[v]){
        Root[u] = v;
    }
    else{
        Root[v] = u;
    }
    return true;
}

// Điều Kiện để sort
bool Compare(Edge m_1, Edge m_2){
    return m_1.w < m_2.w;
}

void KrusKal(){
    MST_Weight = 0;
    sort(E.begin(), E.end(), Compare);
    for (int i=0; i<E.size(); i++){
        if (Join(E[i].u, E[i].v)){
            MST_Weight += E[i].w;
            MST.push_back(E[i]);
        }
    }
}

// Xuất Output
void Xuat(){
    cout << MST_Weight;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); // Off Đồng bộ stdin và stdout
    Nhap();
    init();
    KrusKal();
    Xuat();
}

