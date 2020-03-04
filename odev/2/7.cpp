#include <iostream>
using namespace std;

int add(int, int);
int sub(int, int);
int mul(int, int);
int _div(int, int);
int (*tanda())(int, int);

int main() {
	int x = 5, y = 3, z;
	cout << "x = 5\ny = 3\n";
	cout << "1.add\n2.diff\n3.mul\n4.div\n5.exit\n";
	int (*amal)(int, int);
	while(1) {
		amal = tanda();
		if(amal == NULL) break;
		z = amal(x, y);
		cout << z << endl;
	}
}

int (*tanda())(int, int) {
	int c;
	int (*amal[])(int a, int b) = {add, sub, mul, _div};
	cout << "choose action\n";
	cin >> c;
	if(c > 0 && c < 5) return amal[c-1];
	else return NULL;
}

int add(int a, int b) {
	return a+b;
}

int sub(int a, int b) {
	return a-b;
}

int mul(int a, int b) {
    return a*b;
}

int _div(int a, int b) {
    return (float)a/b;
}