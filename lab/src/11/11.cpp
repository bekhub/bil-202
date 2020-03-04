#include <iostream>
using namespace std;

class A {
    int a;
    public:
        A() {};
        A(int a) {this->a = a;}
        void korsot_A() {cout << "A = " << a << "\n";}
};

class B1: protected A {
    int b1;
    public:
        B1(int b1, int a): A(a) {this->b1 = b1;}
        void korsot_B1() {cout << "B1 = " << b1 << "\n"; korsot_A();}
};

class B2: public A {
    int b2;
    public:
        B2(int b2, int a): A(a) {this->b2 = b2;}
        void korsot_B2() {cout << "B2 = " << b2 << "\n"; korsot_A();}
};

class B3 {
    int b3;
    public:
        B3(int b3) {this->b3 = b3;}
        void korsot_B3() {cout << "B3 = " << b3 << "\n";}
};

class C: protected B2, protected B3 {
    int c;
    public:
        C(int b2_1, int b2_2, int b3, int c): B2(b2_1, b2_2), B3(b3) {this->c = c;}
        void korsot_C() {cout << "C = " << c << "\n"; korsot_B2(); korsot_B3();}
};

class D: public B1, public C {
    int d;
    public:
        D(int b1_1, int b1_2, int c1, int c2, int c3, int c4, int d): B1(b1_1, b1_2), C(c1, c2, c3, c4)
        {this->d = d;}
        void korsot_D() {cout << "D = " << d << "\n"; korsot_B1(); korsot_C();}
};

int main()
{
    D d_ob(10, 20, 30, 40, 50, 60, 70);
    cout << "D d_ob(10, 20, 30, 40, 50, 60, 70);\n";
    cout << "D классынын иерархиясы боюнча:\n";
    d_ob.korsot_D();
    getchar();
}
