#include <iostream>
#include <cstring>
using namespace std;
class A{
    char name[80];
    public:
    void put_name(char *c){
        strcpy(name, c);
    }
    void show(){
        cout<<name;
    }
};
class B: public A{
    char phone_num[20];
    public:
    void put_phone_num(char *c){
        strcpy(phone_num, c);
    }
    void show1(){
        cout<<phone_num;
    }
};
int main(){
    A *p;
    A a_ob;
    B *b_p;
    B b_ob;
    p=&a_ob;
    p->put_name("Asan");
    p->show();
    p=&b_ob;
    // p->put_phone_num("123");
    // p->show1();
    p->put_name("Bekjan");
    p->show();
    b_p=&b_ob;
    b_p->put_phone_num("456");
    b_p->show1();
    return 0;
}