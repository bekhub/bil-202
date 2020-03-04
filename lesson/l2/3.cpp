#include <iostream>
using namespace std;

int add(int, int);
int sub(int, int);

int amal(int(*)(int, int), int, int);

int main()
{
	int a = 5, b = 2, c;
	c = amal(add, a, b);
	cout << c << endl;
	c = amal(sub, a, b);
	cout << c << endl;
}

int add(int a, int b) {
	return a+b;
}

int sub(int a, int b) {
	return a-b;
}

int amal(int(*fun)(int, int), int a, int b) {
	return fun(a, b);
}
