#include <iostream>
using namespace std;
class A{
    int i;
    public:
        A(int k=1){
            i=k;
            cout<<"AC1\n";
        }
        ~A(){
            cout<<"AD\n";
        }
        void show(){
            cout<<i<<" ";
        }
};
class B: public A{
    int j;
    public: 
        B(int k):A(k){
            j=k;
            cout<<"BC1\n";
        }
        B(){
                cout << "BC2\n";
                j = 0;
        }
        ~B(){
            cout<<"BD\n";
        }
        void show1(){
            cout<<j<<"\n";
        }
};
int main (){
    B ob;
    ob.show();
    ob.show1();
    return 0;
}
