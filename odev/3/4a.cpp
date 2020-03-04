#include <iostream>
#include <cstring>
using namespace std;

class Person;
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
    void setPrice(int price) {
        this->price = price;
    }
    string getPersonName(Person &a);
    string getPersonName();

private:
    string name, personName;
    int price;
};

class Person
{
public:
    Person(string n)
    {
        name = n;
    }
    void volga(Auto &a);
    void setPrice(Auto &a, int price);
    string getName() {
        return name;
    }

private:
    string name;
    // friend string Auto::getPersonName(Person &a);
    friend class Auto;
};

string Auto::getPersonName(Person &a) {
    return a.name;
}

string Auto::getPersonName() {
    return personName;
}

void Person::volga(Auto &a)
{
    cout << name << " " << a.name << endl;
}
void Person::setPrice(Auto &a, int price)
{
    if (price > 0)
        a.price = price;
    a.personName = name;
}
int main()
{
    Auto araba("Gaz-24", 15000);
    Person adam("Asan");
    adam.setPrice(araba, 8000);
    cout << araba.getName() << " " << araba.getPrice() << " " << araba.getPersonName() << "\n";
    return 0;
}