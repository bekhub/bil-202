#include <iostream>
using namespace std;

class Adam
{
    string Name;
    int age;

public:
    Adam(string str, int i)
    {
        Name = str;
        age = i;
    }
    void show(char c = ' ')
    {
        cout << Name << " " << age << c;
    }
};
class Kizmatker : public Adam
{
public:
    Kizmatker(string a, int i, string c) : Adam(a, i)
    {
        company = c;
    }
    void show1(char c = ' ')
    {
        show(' ');
        cout << company << c;
    }

private:
    string company;
};
int main()
{
    Adam ob1("Asan", 17);
    ob1.show('\n');
    Kizmatker ob2("Esen", 18, "KTMU");
    ob2.show1('\n');
    return 0;
}