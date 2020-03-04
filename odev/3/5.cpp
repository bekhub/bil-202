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
    void get(int &i, int &j)
    {
        i = x;
        j = y;
    }
    MyClass operator=(MyClass ob) {
        x = ob.x;
        y = ob.y;
        return *this;
    }
    MyClass operator+(MyClass ob) {
        MyClass temp;
        temp.x = x + ob.x;
        temp.y = y + ob.y;
        return temp;
    }
    MyClass operator-(MyClass ob) {
        MyClass temp;
        temp.x = x - ob.x;
        temp.y = y - ob.y;
        return temp;
    }
    MyClass operator*(MyClass ob) {
        MyClass temp;
        temp.x = x * ob.x;
        temp.y = y * ob.y;
        return temp;
    }
    MyClass operator/(MyClass ob) {
        MyClass temp;
        temp.x = x / ob.x;
        temp.y = y / ob.y;
        return temp;
    }
};
// MyClass MyClass::operator=(MyClass ob) {
//     x = ob.x;
//     y = ob.y;
//     return *this;
// }
int main()
{
    MyClass ob1(10, 24), ob2(5, 8), ob3, ob4;
    int a, b;
    ob3 = ob1;
    ob3.get(a, b);
    cout << a << " " << b << endl;
    ob3 = ob2 + ob1;
    ob3.get(a, b);
    cout << a << " " << b << endl;
    ob3 = ob1 - ob2;
    ob3.get(a, b);
    cout << a << " " << b << endl;
    ob3 = ob1 * ob2;
    ob3.get(a, b);
    cout << a << " " << b << endl;
    ob3 = ob1 / ob2;
    ob3.get(a, b);
    cout << a << " " << b << endl;
    ob4 = ob1 + ob2 + ob3;
    ob4.get(a, b);
    cout << a << " " << b << endl;
    return 0;
}