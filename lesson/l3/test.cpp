#include <iostream>

#define cout std::cout
#define endl '\n'

template <typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a: b;
}

int main()
{
    int i = max(5, 4);
    cout << i << endl;
    double d = max(5.14, 2.17);
    cout << d << endl;
    char ch = max('b', '9');
    cout << ch << endl;
}