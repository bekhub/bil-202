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
    int operator==(myClass ob);
    int operator&&(myClass ob);
};
int myClass::operator==(myClass ob)
{
    return x == ob.x && y == ob.y;
}
int myClass::operator&&(myClass ob)
{
    return (x && ob.x) && (y && ob.y); //&& логикалык кобойтуу
}
int main()
{
    myClass ob1(3, 4), ob2(0, 0), ob3(3, 4), ob4(-5, -6);
    if (ob1 == ob2)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    if (ob3 == ob1)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    if (ob2 && ob3)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    if (ob3 && ob4)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}