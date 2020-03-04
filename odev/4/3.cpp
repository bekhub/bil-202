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
    myClass operator++();
    myClass operator++(int);
    friend myClass operator-(myClass ob1, myClass ob2);
    friend ostream &operator<<(ostream &out, myClass ob);
};
myClass myClass::operator++()
{
    x++;
    y++;
    return *this;
}
myClass myClass::operator++(int)
{
    x++;
    y++;
    return *this;
}
myClass operator-(myClass ob1, myClass ob2)
{
    myClass temp;
    temp.x = ob1.x - ob2.x;
    temp.y = ob1.y - ob2.y;
    return temp;
}
ostream &operator<<(ostream &out, myClass ob)
{
    out << ob.x << " " << ob.y;
    return out;
}

int main()
{
    myClass ob1(4, 7), ob2(3, 5), ob3;
    cout << "ob1: " << ob1 << "\n"
         << "ob2: " << ob2 << endl;
    ob3 = ob1 - (++ob2);
    ob1++;
    int k, n;
    ob3.get(k, n);
    cout << k << " " << n << endl;
    cout << "ob1: " << ob1 << "\n"
         << "ob2: " << ob2 << endl;
    ob3 = ob1 - ob2++;
    ob3.get(k, n);
    cout << k << " " << n << endl;
    return 0;
}