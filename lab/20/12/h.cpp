#include <iostream>
#include <bitset>
using namespace std;

string get_bin(string str);
string from_bin(string str);
string from_ascii(int *arr, int size);
string bin(int num);

int main() {
    // string str = "HELLO";
    // cout << get_bin(str) << endl;
    int *arr = new int[100];
    int size = 0, t;
    while(cin >> t) arr[size++] = t;
    cout << from_ascii(arr, size) << "\n";
}

string from_ascii(int *arr, int size) {
    string res{};
    for(int i=0; i<size; i++) res+=(char)arr[i];
    return res; 
}

string from_bin(string str) {
    string res{};
    return res; 
}

string get_bin(string str) {
    string res{};
    for(auto i: str) {
        res+=bin(i) + " ";
    }
    return res;
}

string bin(int num) {
    bitset<8> b(num);
    string res = b.to_string();
    for(int i=0; i<8; i++){
        if(res[0] == '0') res = res.substr(1, 8-(i+1));
    }
    return res;
}
