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
    friend class Person;

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
    cout << name << " " << a.name << endl;
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
    adam.setPrice(araba, 8000);
    cout << araba.getName() << " " << araba.getPrice() << "\n";
    return 0;
}