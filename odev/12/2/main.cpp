#include <iostream>
using namespace std;

class Example
{
    string example;
public:
    friend istream &operator>>(istream &in, Example &ex);
    friend ostream &operator<<(ostream &out, const Example &ex);
};

istream &operator>>(istream &in, Example &ex) {
    cout << "Input some text:\n";
    getline(in, ex.example);
    return in;
}

ostream &operator<<(ostream &out, const Example &ex) {
    string temp;
    for(auto i: ex.example) {
        if(isupper(i) || isdigit(i)) continue;
        temp.push_back(i);
    }
    out << temp;
    return out;
}

int main()
{
    Example ex;
    cin >> ex;
    cout << ex << endl;
}