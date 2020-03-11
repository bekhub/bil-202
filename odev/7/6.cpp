#include <iostream>
using namespace std;
class Adam{
    public:
    Adam(string n, int a){
        name=n;
        age=a;
    }
    virtual void show(){
        cout<<name<<" "<<age << endl;
    }
    protected:
        string name;
    private:
        int age;
};
class Kizmatker: public Adam{
    public:
    Kizmatker(string n, int a, string c):Adam(n,a){
        company=c;
    }
    // void show() override {
    //     Adam::show();
    //     cout<<company << endl;
    // }
    private:
        string company;
};
int main (){
    Adam ob1("Asan", 19);
    ob1.show();
    Kizmatker ob2("Esen", 20, "KTMU");
    ob2.show();
    return 0;
}