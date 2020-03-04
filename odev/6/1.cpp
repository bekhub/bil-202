#include <iostream>
using namespace std;

class Adam{
    public:
    Adam(string n, int m){
        name=n;
        age=m;
    }
    void show(){
        cout<<name<<" "<<age<<" ";
    }
    protected:
        string name;
    private:
        int age;
};

class Kizmatker:private Adam{
    public:
    Kizmatker(string n, int m, string k):Adam(n,m){
        company=k;
    }
    void show_name(){
        cout<<name;
    }
    private:
        string company;
};

int main (){
    Adam ob1("Asan", 19);
    ob1.show();
    cout << '\n';
    //ob1.name="Esen";
    Kizmatker ob2("Uson", 20, "KTMU");
    //ob2.name="Ten";
    //ob2.show();
    ob2.show_name();
    cout << '\n';
    return 0;
}
