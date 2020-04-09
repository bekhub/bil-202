#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
using namespace std;

#define cf complex<float>

int main()
{
    float tmp;
    vector<float> arr;
    vector<cf> carr;
    ifstream in("input");
    while(in >> tmp) {
        arr.push_back(tmp);
    }
    ofstream out("output");
    for(int i=0, j=0; i<arr.size(); i+=2, j++) {
        carr.push_back(cf(arr[i], arr[i+1]));
        cout << carr[j] << endl;
        out << carr[j] << "\n";
    }
    in.close();
    out.close();
}