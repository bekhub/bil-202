#include <iostream>
#include <cstring>
#include <stdarg.h>
using namespace std;

void print(const char *format, ...) {
    int ival;
    float dval;
    char *sval = (char*)malloc(100);
    char cval;
    va_list ap;
    va_start(ap, format);
    for (const char *p = format; *p; p++) 
    {
        if (*p == '%')
        {
            switch (*++p)
            {
                case 'd':
                    ival = va_arg(ap, int);
                    cout << ival;
                    break;
                case 'f':
                    dval = va_arg(ap, double);
                    cout << dval;
                    break;
                case 's':
                    sval = va_arg(ap, char*);
                    cout << sval;
                    break;
                case 'c':
                    cval = va_arg(ap, int);
                    cout << (char)cval;
                    break;
            }
        }
        else
            cout << *p;
    }
    va_end(ap);
}

void scan(const char *format, ...) {
    int ival;
    float dval;
    char *sval = (char*)malloc(100);
    char cval;
    va_list ap;
    va_start(ap, format);
    for (const char *p = format; *p; p++) 
    {
        if (*p == '%')
        {
            switch (*++p)
            {
                case 'd':
                    cin >> ival;
                    *va_arg(ap, int*) = ival;
                    break;
                case 'f':
                    cin >> dval;
                    *va_arg(ap, float*) = dval;
                    break;
                case 's':
                    cin >> sval;
                    strcpy(va_arg(ap, char*), sval);
                    break;
                case 'c':
                    cin >> cval;
                    *va_arg(ap, char*) = cval;
                    break;
            }
        }
    }
    va_end(ap);
}

int main()
{
    system("clear");
    char name[30];
    int age;
    float student_id;
    char gender;
    print("Input your name(string), age(int), student_id(float), gender(char) : \n");
    scan("%s %d %f %c", &name, &age, &student_id, &gender);
    print("Hello %s, your age: %d, student_id: %f, gender: %c\n", name, age, student_id, gender);
}