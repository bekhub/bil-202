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
    friend myClass operator+(myClass ob);
    friend myClass operator-(myClass ob);
    friend myClass operator++(myClass ob);
    friend myClass operator++(myClass ob, int);
    friend myClass operator--(myClass ob);
    friend myClass operator--(myClass ob, int);
    friend ostream &operator<<(ostream &out, myClass ob);
};
ostream &operator<<(ostream &out, myClass ob) {
    out << ob.x << " " << ob.y << "\n";
    return out;
}
myClass operator++(myClass ob) {
    ob.x++;
    ob.y++;
    return ob;
}
myClass operator++(myClass ob, int) {
    ob.x++;
    ob.y++;
    return ob;
}
myClass operator--(myClass ob) {
    ob.x--;
    ob.y--;
    return ob;
}
myClass operator--(myClass ob, int) {
    ob.x--;
    ob.y--;
    return ob;
}
myClass operator+(myClass ob)
{
    ob.x = +ob.x;
    ob.y = +ob.y;
    return ob;
}
myClass operator-(myClass ob)
{
    ob.x = -ob.x;
    ob.y = -ob.y;
    return ob;
}
int main()
{
    myClass ob1(4, 6);
    cout << +ob1;
    ob1 = -ob1;
    cout << ob1;
    ob1 = ob1++;
    cout << ob1;
    ob1 = ++ob1;
    cout << ob1;
    ob1 = ob1--;
    cout << ob1;
    ob1 = --ob1;
    cout << ob1;
    cout << -ob1;
    return 0;
}