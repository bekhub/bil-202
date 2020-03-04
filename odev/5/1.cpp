#include <iostream>
using namespace std;

class arrayType
{
    int a[3];

public:
    arrayType(int i, int j, int k)
    {
        a[0] = i;
        a[1] = j;
        a[2] = k;
    }
    int &operator[](int i)
    {
        return a[i];
    }
};
int main()
{
    arrayType ob(1, 2, 3);
    cout << ob[1];
    ob[2] = 8;
    cout << ob[2];
    return 0;
}