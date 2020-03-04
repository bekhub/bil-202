#include <iostream>
using namespace std;

void tan();
void kech();
void (*message(int))();

int main()
{
	void (*amal)();
	amal = message(16);
	amal();
}

void (*message(int time))(){
	if(time <= 12) return tan;
	else return kech;
}

void tan() {
	cout << "kutman tan\n";
}

void kech() {
	cout << "kutman kech\n";
}
