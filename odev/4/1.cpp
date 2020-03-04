#include <iostream>
using namespace std;
class MyClass
{
    int x, y;

public:
    MyClass()
    {
        x = 0;
        y = 0;
    }
    MyClass(int a, int b)
    {
        x = a;
        y = b;
    }
    void get(int &a, int &b)
    {
        a = x;
        b = y;
    }
    MyClass operator+(MyClass ob); //ob+ob
    MyClass operator+(int i);      //ob+int
    friend MyClass operator+(int i, MyClass ob);
};
MyClass MyClass::operator+(MyClass ob)
{
    MyClass temp;
    temp.x = x + ob.x;
    temp.y = y + ob.y;
    return temp;
}
MyClass MyClass::operator+(int i)
{
    MyClass temp;
    temp.x = x + i;
    temp.y = y + i;
    return temp;
}
MyClass operator+(int i, MyClass ob) {
    MyClass temp;
    temp.x = i + ob.x;
    temp.y = i + ob.y;
    return temp;
}

int main()
{
    MyClass ob1(4, 3), ob2(3, 6), ob3;
    int k, n;
    ob3 = ob1 + ob2;
    ob3.get(k, n);
    cout << k << " " << n << endl;
    ob3 = ob3 + 10;
    ob3.get(k, n);
    cout << k << " " << n << endl;
    ob3 = 10 + ob3;
    ob3.get(k, n);
    cout << k << " " << n << endl;
    return 0;
}