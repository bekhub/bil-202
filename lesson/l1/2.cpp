#include <iostream>
using namespace std;

double ayant(double x, double y = 5)
{
    return x * y;
}

double ayant(int x)
{
    return x * x;
}

void f(int x, int y, int z = 0) {
    cout << x << " " << y << " " << z << endl;
}

int main()
{
    // cout << ayant(4.5, 6.3) << endl;
    // cout << ayant(6.8) << endl;
    f(4, 3, 6);
}