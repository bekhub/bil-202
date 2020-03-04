#include <iostream>
using namespace std;
class base{
    protected:
        int a, b;
    public:
        void setab(int n, int m){
            a=n;
            b=m;
        }  
};
class derived:protected base{
    int c;
    public:
    void setc(int n){
        c=n;
    }
    void show(){
        cout<<a<<" "<<b<<" "<<c;
    }
};
int main (){
    //a, b jabyk
    derived ob;
    ob.setab(3,5);
    ob.setc(6);
    ob.show();
    return 0;
}
