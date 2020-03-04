#include <iostream>
using namespace std;

void f(int x = 0, int y = 3);

int main()
{
    f(4, 5);
    f(6);
    f();
    return 0;
}

void f(int x, int y)
{
    cout << x << " " << y << endl;
}
