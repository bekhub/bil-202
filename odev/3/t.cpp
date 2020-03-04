#include <iostream>
#include <cstring>
using namespace std;

class Auto;
class Person
{
public:
    Person(string n)
    {
        name = n;
    }
    void volga(Auto &a);
    void setPrice(Auto &a, int price);

private:
    string name;
};
class Auto
{
    friend void Person::volga(Auto &a);
    friend void Person::setPrice(Auto &a, int price);

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
void Person::volga(Auto &a)
{
    cout << a.name << endl;
}
void Person::setPrice(Auto &a, int price)
{
    if (price > 0)
        a.price = price;
}
int main()
{
    Auto araba("Gaz-24", 15000);
    Person adam("Asan");
    adam.volga(araba);
    adam.setPrice(araba, 8000);
    cout << araba.getName() << " " << araba.getPrice();
    return 0;
}