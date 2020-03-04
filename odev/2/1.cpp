#include <iostream>
using namespace std;

int add(int, int);
int sub(int, int);
int mul(int, int);
float _div(int, int);

int main()
{
    int a = 5, b = 3, c;
    int (*amal)(int, int);
    float (*famal)(int, int);
    amal = add;
    c = amal(a, b);
    // c=(*amal)(a,b);
    cout << "c=" << c;
    amal = sub;
    c = amal(a, b);
    cout << "\nc=" << c;
    amal = mul;
    c = amal(a, b);
    cout << "\nc=" << c;
    famal = _div;
    cout << "\nc=" << famal(a, b) << endl;
    return 0;
}

int mul(int a, int b) {
    return a*b;
}

float _div(int a, int b) {
    return (float)a/b;
}

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}