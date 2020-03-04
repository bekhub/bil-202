#include <iostream>
using namespace std;

int add(int, int);
int sub(int, int);

int main()
{
    int a = 5, b = 3, c;
    int (*amal)(int, int);
    amal = add;
    c = amal(a, b);
    // c=(*amal)(a,b);
    cout << "c=" << c;
    amal = sub;
    c = amal(a, b);
    cout << "\nc=" << c << endl;
    return 0;
}

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}