#include <iostream>
using namespace std;
class Base{
    public:
    Base() {
        cout << "C Base\n";
    }
    ~Base() {
        cout << "D Base\n";
    }
    int i;
};
class der1:virtual public Base{
    public:
    der1() {
        cout << "C der1\n";
    }
    ~der1() {
        cout << "D der1\n";
    }
    int j;
};
class der2:virtual public Base{
    public:
    der2() {
        cout << "C der2\n";
    }
    ~der2() {
        cout << "D der2\n";
    }
    int k;
};
class der3:public der1, public der2{
    public:
    der3() {
        cout << "C der3\n";
    }
    ~der3() {
        cout << "D der3\n";
    }
    int sum(){
        return i+j+k;
    }
};
int main(){
    der3 ob;
    ob.i=5;
    ob.j=3;
    ob.k=2;
    cout<<ob.sum()<<endl;
    return 0;
}