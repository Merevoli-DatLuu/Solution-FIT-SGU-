// Time: O(1)
// Space: O(1)

#include <iostream>

using namespace std;

class DIEM{
    public:
        float x, y;
        friend istream& operator >> (istream &in, DIEM &d);
        friend ostream& operator << (ostream &on, DIEM d);
};

class DOANTHANG: public DIEM{
    protected:
        DIEM a, b;
    public:
        friend istream& operator >> (istream &in, DOANTHANG &d);
        friend ostream& operator << (ostream &on, DOANTHANG d);
        bool VTTD(DOANTHANG d);
};

istream& operator >> (istream &in, DIEM &d){
    in >> d.x >> d.y;
    return in;
}

ostream& operator << (ostream &on, DIEM d){
    on << d.x << " " << d.y << "\n";
    return on;
}

istream& operator >> (istream &in, DOANTHANG &d){
    in >> d.a >> d.b;
    return in;
}

ostream& operator << (ostream &on, DOANTHANG d){
    on << d.a << d.b;
    return on;
}

bool DOANTHANG::VTTD(DOANTHANG d){
    float a1 = this->a.y - this->b.y;
    float b1 = this->b.x - this->a.x;
    float x1 = this->a.x;
    float y1 = this->a.y;
    float c1 = a1*(-x1) + b1*(-y1);
    if ((a1*(d.a.x) + b1*(d.a.y) + c1)*(a1*(d.b.x) + b1*(d.b.y) + c1) > 0){
        return false;
    }
    float a2 = d.a.y - d.b.y;
    float b2 = d.b.x - d.a.x;
    float x2 = d.a.x;
    float y2 = d.a.y;
    float c2 = a2*(-x2) + b2*(-y2);
    if ((a2*(this->a.x) + b2*(this->a.y) + c2)*(a2*(this->b.x) + b2*(this->b.y) + c2) > 0){
        return false;
    }
    return true;
}

int main(){
    DOANTHANG d1, d2;
    cin >> d1 >> d2;
    if (d1.VTTD(d2)){
        cout << 1;
    }
    else{
        cout << 0;
    }
}
