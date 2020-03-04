#include <iostream>
using namespace std;

void f(int a, int b) {
    cout << a << " " << b << endl;
}

void f(int a, int &b) {
    cout << a << " " << b << endl;
}

int main()
{
    int k = 7;
    void (*fp1)(int, int);
    void (*fp2)(int, int&);
    fp1 = f;
    fp2 = f;
    fp1(5, 6);
    fp2(3, k);
    return 0;
}