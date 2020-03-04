#include <iostream>
using namespace std;

void add(int, int);
void sub(int, int);

int main()
{
	int a=3, b=1, c;
	void(*amal[2])(int, int) = {add, sub};
	for(int i=0; i<2; i++) {
		amal[i](a, b);
	}
}

void add(int a, int b) {
	cout << a+b << endl;
}

void sub(int a, int b) {
	cout << a-b << endl;
}
