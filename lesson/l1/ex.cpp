#include <iostream>
using namespace std;

int f(int x, int y)
{
    return x + y;
}

int f(int x, int &y)
{
    return x - y;
}

int main()
{
    int x = 3, y = 2;
    cout << f(3, y); //kop maaniluulukko ee bolobuz
    return 0;
}