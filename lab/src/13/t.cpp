#include <iostream>
using namespace std;

char *get_arr(char arr[]) {
    for(int i=0; i<26; i++) arr[i] = i+97;
    return arr;
}

int main()
{
    char arr[] = ",.!?()\"-;:";
    for(char i: arr) cout << (int)i << ' ';
    cout << '\n';
}