#include <iostream>
using namespace std;

bool even(int);
bool odd(int);
bool _signed(int);
bool _unsigned(int);
bool is_zero(int);

void amal(bool(*)(int), int[], int);

int main()
{
	int n = 8;
	int array[] = {-3, -2, -1, 0, 1, 2, 3, 4};
	cout << "odd numbers:\n";
	amal(odd, array, n);
	cout << "even numbers\n";
	amal(even, array, n);
	cout << "signed numbers\n";
	amal(_signed, array, n);
	cout << "unsigned numbers\n";
	amal(_unsigned, array, n);
	cout << "zero numbers\n";
	amal(is_zero, array, n);
}

bool odd(int x) {
	return x%2;
}

bool even(int x) {
	return !(x%2);
}

bool _signed(int x) {
	return x > 0;
}
bool _unsigned(int x) {
	return x < 0;
}

bool is_zero(int x) {
	return x == 0;
}

void amal(bool(*fun)(int), int arr[], int n) {
	for(int i=0; i<n; i++) {
		if(fun(arr[i])) cout << arr[i] << " ";
	}
	cout << endl;
}
