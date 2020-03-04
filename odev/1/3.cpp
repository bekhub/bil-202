#include <iostream>
using namespace std;

void f(int k = 5)
{
    for (int i = 0; i < k; i++)
        cout << " ";
}

void f(int k = 7, char ch = 'a')
{
    for (int i = 0; i < k; i++)
        cout << ch;
}

int main()
{
    void (*fp1)(int);
    void (*fp2)(int, char);
    fp1 = f;
    fp2 = f;
    fp1(5);
    fp2(3, 'k');
    return 0;
}