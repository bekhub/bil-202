#include <iostream>
using namespace std;
class A{
    public:
    A(){
        cout<<"Konst A\n";
    }
    ~A(){
        cout<<"Dest A\n";
    }
};
class B: public A{
    public:
    B(){
        cout<<"Konst B\n";
    }
    ~B(){
        cout<<"Dest B\n";
    }
};
class C:public B{
    public:
    C(){
        cout<<"Konst C\n";
    }
    ~C(){
        cout<<"Dest C\n";
    }
};
int main(){
    C ob;
    return 0;
}