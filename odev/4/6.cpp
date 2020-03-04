#include <iostream>
using namespace std;
class myClass
{
    int x, y;

public:
    myClass()
    {
        x = 0;
        y = 0;
    }
    myClass(int a, int b)
    {
        x = a;
        y = b;
    }
    void get(int &a, int &b)
    {
        a = x;
        b = y;
    }
    myClass operator-(myClass ob)
    {
        myClass temp;
        temp.x = x - ob.x;
        temp.y = y - ob.y;
        return temp;
    }
    myClass operator-()
    {
        x = -x;
        y = -y;
        return *this;
    }
};
int main()
{
    myClass ob1(3, 5), ob2(2, 1);
    int k, n;
    ob1 = ob1 - ob2;
    ob1.get(k, n);
    cout << k << " " << n << endl;
    ob1 = -ob1;
    ob1.get(k, n);
    cout << k << " " << n << endl;
    return 0;
}