#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class io_stream
{
    char *p;
public:
    void operator>>(ostream &stream);
    void operator<<(char arr[]);
};

class lower_case_letters
{
public:
    char arr[27];
    lower_case_letters();
};

class letters
{
public:
    char arr[53];
    letters();
};

class letters_digits
{
public:
    char arr[63];
    letters_digits();
};

class id_symbols
{
public:
    char arr[64];
    id_symbols();
};

class punc_marks
{
public:
    char arr[11] = ",.!?()\"-;:";
};

int main() {
    lower_case_letters lcl;
    letters lts;
    letters_digits ld;
    id_symbols is;
    punc_marks pm;
    io_stream io;
    io << lcl.arr;
    cout << "\nБардык кичинекей тамгалар:\n\n";
    io >> cout;
    io << lts.arr;
    cout << "Бардык тамгалар:\n\n";
    io >> cout;
    io << ld.arr;
    cout << "Бардык тамга жана цифралар:\n\n";
    io >> cout;
    io << is.arr;
    cout << "С++ тилинде идентификаторлордо колдонуучу символдор:\n\n";
    io >> cout;
    io << pm.arr;
    cout << "Тыныш символдор:\n\n";
    io >> cout;
}

lower_case_letters::lower_case_letters() {
    for(int i=0; i<26; i++) {
        arr[i] = i+97;
    }
    arr[26] = 0;
}

letters::letters() {
    for(int i=0; i<26; i++) {
        arr[i] = i+97;
    }
    for(int i=26; i<52; i++) {
        arr[i] = i+39;
    }
    arr[52] = 0;
}

letters_digits::letters_digits() {
    for(int i=0; i<26; i++) {
        arr[i] = i+97;
    }
    for(int i=26; i<52; i++) {
        arr[i] = i+39;
    }
    for(int i=52; i<62; i++) {
        arr[i] = i-4;
    }
    arr[62] = 0;
}

id_symbols::id_symbols() {
    for(int i=0; i<26; i++) {
        arr[i] = i+97;
    }
    for(int i=26; i<52; i++) {
        arr[i] = i+39;
    }
    for(int i=52; i<62; i++) {
        arr[i] = i-4;
    }
    arr[62] = '_';
    arr[63] = 0;
}

void io_stream::operator>>(ostream &out) {
    for(; *p; p++) out << *p;
    out << "\n\n";
}

void io_stream::operator<<(char arr[]) {
    p = arr;
}