#include <iostream>
using namespace std;

void add(int, int);
void sub(int, int);
void mul(int, int);
void _div(int, int);

int main()
{
	int a=6, b=4;
	void(*amal[4])(int, int) = {add, sub, mul, _div};
	for(int i=0; i<4; i++) {
		amal[i](a, b);
	}
}

void add(int a, int b) {
	cout << a << " + " << b << " = " << a+b << endl;
}

void sub(int a, int b) {
	cout << a << " - " << b << " = " << a-b << endl;
}

void mul(int a, int b) {
	cout << a << " * " << b << " = " << a*b << endl;
}

void _div(int a, int b) {
	cout << a << " / " << b << " = " << (float)a/b << endl;
}