#include <iostream>
using namespace std;

string onlylower(string str);
string onlyalpha(string str);
string onlyalnum(string str);
string onlyupper(string str);
string onlypmarks(string str);

int main()
{
    string input;
    int choose;
    cout << "Input some text:\n";
    getline(cin, input);
    do {
        cout << "Choose variant:\n0) Exit\n1) Only lowercase\n2) Only alpha\n3) Only alpha and digits";
        cout << "\n4) Only uppercase\n5) Only punctuation marks\n";
        cin >> choose;
        switch (choose) {
            case 1: cout << onlylower(input) << endl; break;
            case 2: cout << onlyalpha(input) << endl; break;
            case 3: cout << onlyalnum(input) << endl; break;
            case 4: cout << onlyupper(input) << endl; break;
            case 5: cout << onlypmarks(input) << endl; break;
            default: break;
        }
    } while (choose);
}

string onlylower(string str) {
    string temp;
    for(auto i: str) {
        if(i == ' ' || isalpha(i) && islower(i)) temp.push_back(i);
    }
    return temp;
}

string onlyalpha(string str) {
    string temp;
    for(auto i: str) {
        if(i == ' ' || isalpha(i)) temp.push_back(i);
    }
    return temp;
}

string onlyalnum(string str) {
    string temp;
    for(auto i: str) {
        if(i == ' ' || isalnum(i)) temp.push_back(i);
    }
    return temp;
}

string onlyupper(string str) {
    string temp;
    for(auto i: str) {
        if(i == ' ' || isalpha(i) && isupper(i)) temp.push_back(i);
    }
    return temp;
}

string onlypmarks(string str) {
    string temp;
    for(auto i: str) {
        if(!isalnum(i)) temp.push_back(i);
    }
    return temp;
}