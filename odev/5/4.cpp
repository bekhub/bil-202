#include <iostream>
using namespace std;

class Date
{
    int day, month, year;

public:
    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    friend ostream &operator<<(ostream &os, /*const*/ Date &dt);
};
ostream &operator<<(ostream &os, /*const*/ Date &dt)
{
    char s[80];
    Date data(26, 2, 2020);
    dt = data;
    sprintf(s, "%02d %02d %d", dt.day, dt.month, dt.year);
    os << s;
    return os;
}
int main()
{
    Date ob(24, 2, 2020);
    cout << ob << "\n";
    return 0;
}