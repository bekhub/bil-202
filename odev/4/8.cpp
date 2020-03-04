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
    friend bool operator==(myClass ob1, myClass ob2);
    friend bool operator!=(myClass ob1, myClass ob2);
    friend bool operator>(myClass ob1, myClass ob2);
    friend bool operator<(myClass ob1, myClass ob2);
    friend bool operator<=(myClass ob1, myClass ob2);
    friend bool operator>=(myClass ob1, myClass ob2);
    friend bool operator&&(myClass ob1, myClass ob2);
    friend bool operator||(myClass ob1, myClass ob2);
    friend bool operator!(myClass ob);
};
bool operator==(myClass ob1, myClass ob2)
{
    return ob1.x == ob2.x && ob1.y == ob2.y;
}
bool operator!=(myClass ob1, myClass ob2)
{
    return ob1.x != ob2.x && ob1.y != ob2.y;
}
bool operator>(myClass ob1, myClass ob2)
{
    return ob1.x > ob2.x && ob1.y > ob2.y;
}
bool operator<(myClass ob1, myClass ob2)
{
    return ob1.x < ob2.x && ob1.y < ob2.y;
}
bool operator<=(myClass ob1, myClass ob2)
{
    return ob1.x <= ob2.x && ob1.y <= ob2.y;
}
bool operator>=(myClass ob1, myClass ob2)
{
    return ob1.x >= ob2.x && ob1.y >= ob2.y;
}
bool operator&&(myClass ob1, myClass ob2)
{
    return (ob1.x && ob2.x) && (ob1.y && ob2.y);
}
bool operator||(myClass ob1, myClass ob2)
{
    return (ob1.x || ob2.x) || (ob1.y || ob2.y);
}
bool operator!(myClass ob)
{
    return (!ob.x && !ob.y);
}

int main()
{
    myClass ob1(3, 4), ob2(0, 0), ob3(3, 4), ob4(-5, -6);
    cout << "ob1(3, 4), ob2(0, 0), ob3(3, 4), ob4(-5, -6)\n\n";
    cout << "ob1 == ob2 " << (ob1 == ob2 ? "True": "False") << '\n';
    cout << "ob1 != ob2 " << (ob1 != ob2 ? "True": "False") << '\n';
    cout << "ob1 > ob2  " << (ob1 > ob2 ? "True": "False") << '\n';
    cout << "ob1 < ob2  " << (ob1 < ob2 ? "True": "False") << '\n';
    cout << "ob1 >= ob3 " << (ob1 >= ob3 ? "True": "False") << '\n';
    cout << "ob1 <= ob4 " << (ob1 <= ob4 ? "True": "False") << '\n';
    cout << "ob1 && ob2 " << (ob1 && ob2 ? "True": "False") << '\n';
    cout << "ob1 || ob2 " << (ob1 || ob2 ? "True": "False") << '\n';
    cout << "!ob2       " << (!ob2 ? "True": "False") << '\n';
    return 0;
}