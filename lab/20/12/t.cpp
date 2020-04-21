#include <iostream>
#include <bitset>
using namespace std;

void print(char *a) {
    for(; *a; a++) cout << *a;
    cout << "\n";
}

int main()
{
    // const int n = 20;
    // char a[n] = "hello world";
    // print(a);
    // string s = "b", s1 = "a";
    bitset<8> a(101);
    string str = a.to_string();
    cout << (int)'2' << "\n";
}








{
                    1110110 1100001 1101100 1100001
                    1110010 100000  1101101 1101111
                    1110010 1100111 1101000 1110101
                    1101100 1101001 1110011                                                     
}