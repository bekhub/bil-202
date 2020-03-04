#include <iostream>
#include <cstring>
using namespace std;

class Auto
{
    friend void drive(Auto &a);
    friend void setPrice(Auto &, int price);

public:
    Auto(string autoName, int autoPrice)
    {
        name = autoName;
        price = autoPrice;
    }
    string getName()
    {
        return name;
    }
    int getPrice()
    {
        return price;
    }

private:
    string name;
    int price;
};
void drive(Auto &a)
{
    cout << a.name << endl;
}
void setPrice(Auto &a, int price)
{
    if (price > 0)
        a.price = price;
}
int main()
{
    Auto volga("GAZ-24", 15000);
    drive(volga);
    cout << volga.getName() << " " << volga.getPrice() << endl;
    setPrice(volga, 11000);
    cout << volga.getName() << " " << volga.getPrice() << endl;
    return 0;
}