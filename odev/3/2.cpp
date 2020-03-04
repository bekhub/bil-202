#include <iostream>
#include <cstring>
using namespace std;

class Person;
class Auto
{
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
    void volga(Auto &a);
    void setPrice(Auto &a, int price);

private:
    string name;
    int price;
};

class Person
{
public:
    Person(string n)
    {
        name = n;
    }

private:
    friend void Auto::volga(Auto &a);
    friend void Auto::setPrice(Auto &a, int price);
    string name;
};

void Auto::volga(Auto &a)
{
    cout << a.name << endl;
}
void Auto::setPrice(Auto &a, int price)
{
    if (price > 0)
        a.price = price;
}
int main()
{
    Auto araba("Gaz-24", 15000);
    Person adam("Asan");
    araba.volga(araba);
    araba.setPrice(araba, 8000);
    cout << araba.getName() << " " << araba.getPrice() << "\n";
    return 0;
}