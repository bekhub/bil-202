#include <iostream>
using namespace std;

int n = 3; // класстагы экземплярлардын саны

class substance
{
private:
    string name, type;
    float temp1, temp2;
    friend ostream & operator<<(ostream &stream, const substance &ob);
    friend istream & operator>>(istream &stream, substance &ob);
    friend substance operator+(const substance &ob1, const substance &ob2);
    friend void header();
    friend void line();
    friend int check(int a, int b);
    friend int check(int a);
public:
    substance();
    substance(string name, string type, float temp1, float temp2);
    void setAll(string name, string type, float temp1, float temp2);
    void showAll();
    substance operator=(substance &ob);
    bool operator==(substance &ob);
};

substance::substance() {
    temp1 = 0;
    temp2 = 0;
}

/**** астын сызуу ****/
void line() {
    printf("|-----------------------------------------------------------|\n");
}

/**** жадыбалдын башын чыгаруу ****/
void header() {
    line();
    printf("|Заттын жогорку өткөргүч абалына өтүү температурасы         |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("| Зат               | Тиби        | Температура             |\n");
    printf("|-------------------|-------------|-------------------------|\n");
}

ostream & operator<<(ostream &stream, const substance &ob) {
    char result[81];
    sprintf(result, "| %-18s| %-12s| %10.1f - %-11.1f|\n",
    ob.name.c_str(), ob.type.c_str(), ob.temp1, ob.temp2);
    header();
    stream << result;
    line();
    return stream;
}

istream & operator>>(istream &stream, substance &ob) {
    printf("Заттын аталышын, тибин, 1 температурасын, 2 температурасын киргизгиле > \n");
    stream >> ob.name >> ob.type >> ob.temp1 >> ob.temp2;
    return stream;
}

int check(int a, int b) {
    if(((a > n-1) || (a < 0) || (b > n-1) || (b < 0))) {
        cout << "Ката! Андай индекстуу экземпляр жок\n";
        getchar();
        return -1;
    }
    else if(a == b) {
        cout << "Ката! Экземпляр озуно озу жазылбайт.\n";
        getchar();
        return -2;
    }
    return 0;
}

int check(int a) {
    if(((a > n-1) || (a < 0))) {
        cout << "Ката! Андай индекстуу экземпляр жок\n";
        getchar();
        return -1;
    }
    return 0;
}

substance operator+(const substance &ob1, const substance &ob2) {
    return substance(ob1.name + ob2.name,
                    ob1.type + ob2.type,
                    ob1.temp1 + ob2.temp1,
                    ob1.temp2 + ob2.temp2);
}

bool substance::operator==(substance &ob) {
    if(temp1 != ob.temp1 || temp2 != ob.temp2 || name != ob.name || type != ob.type) {
        cout << "Класстын бул экземплярлары барабар эмес.\n";
        return false;
    } else {
        cout << "Класстын бул экземплярлары барабар.\n";
        return true;
    }
}

substance substance::operator=(substance &ob) {
    if(!ob.name.length() || !ob.type.length()) {
        cout << "Ката! Эс болунгон жок.\n";
        exit(0);
    }
    name = ob.name;
    type = ob.type;
    temp1 = ob.temp1;
    temp2 = ob.temp2;
    return ob;
}

substance::substance(string name, string type, float temp1, float temp2) {
    this->name = name;
    this->type = type;
    this->temp1 = temp1;
    this->temp2 = temp2;
}

void substance::setAll(string name, string type, float temp1, float temp2) {
    this->name = name;
    this->type = type;
    this->temp1 = temp1;
    this->temp2 = temp2;
}

void substance::showAll() {
    printf("%s %s %.1f %.1f\n", name.c_str(), type.c_str(), temp1, temp2);
}

int main()
{
    int q1, q2;
    substance arr[] = {substance("ZN", "I", 0.8, 0.8),
                        substance("PBC", "A", 12.1, 15.7),
                        substance("NDC", "C", 10.5, 113.9)};
    cout << "Заттын аталышы, тиби, 1 температурасы, 2 температурасы: \n";
    for(auto ob: arr) ob.showAll();

    cout << "\n'=' менчиктоо операторун жаныдан жуктоо.";
    cout << "\nКласстын орун алмашчу экземплярларынын номерлерин киргизгиле: ";
    cin >> q1 >> q2;
    substance temp;
    if(check(q1, q2) != 0) exit(-1);
    temp = arr[q1];
    arr[q1] = arr[q2];
    arr[q2] = temp;

    cout << "Заттын аталышы, тиби, 1 температурасы, 2 температурасы: \n";
    for(auto ob: arr) ob.showAll();

    cout << "\n'==' дал келуу операторун жаныдан жуктоо.";
    cout << "\nКласстын салыштырылуучу экземплярларынын номерлерин киргизгиле: ";
    cin >> q1 >> q2;
    if(check(q1, q2) != 0) exit(-1);
    arr[q1] == arr[q2];

    cout << "\n'+' кошуу операторун жаныдан жуктоо.";
    cout << "\nКласстын кошулуучу экземплярларынын номерлерин киргизгиле: ";
    cin >> q1 >> q2;
    if(check(q1, q2) != 0) exit(-1);
    substance temp1 = arr[q1] + arr[q2];
    cout << "Заттын аталышы, тиби, 1 температурасы, 2 температурасы: \n";
    temp1.showAll();

    cout << "\n'>> <<' киргизуу жана чыгаруу операторлорун жаныдан жуктоо.";
    cout << "\nКласстын экземплярынын номерин киргизгиле: ";
    cin >> q1;
    if(check(q1) != 0) exit(-1);
    cin >> arr[q1];
    cout << arr[q1];
}