#include <iostream>
#include <algorithm>
using namespace std;

const int n = 12; 

class substance
{
    private:
        string name;
        char type;
        float temp1, temp2;
        friend ostream & operator<<(ostream &stream, const substance &ob);
        friend istream & operator>>(istream &stream, substance &ob);
        friend void header();
        friend void line();
    public:
        substance() {
            temp1 = 0;
            temp2 = 0;
        }
        substance(string name, char type, float temp1, float temp2);
        void set(string name, char type, float temp1, float temp2);
        void get(string &name, char &type, float &temp1, float &temp2);
        string getName() { return name;}
        void show();
};

class BB
{
    private:
        string title;
        substance *saptar[n];
        int num, queue;
    public:
        BB(string title) {
            this->title = title;
            num = 0;
            queue = 0;
        }
        ~BB() {
            if(num) for(int i=0; i<num; i++) delete saptar[i];
        }
        void add(string name, char type, float temp1, float temp2);
        void remove();
        void BB_sort();
        friend ostream & operator<<(ostream &stream, BB &ob);
};

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

void BB::add(string name, char type, float temp1, float temp2) {
    if(num >= 12) return;
    saptar[num++] = new substance(name, type, temp1, temp2);
    queue = 0;
}

void BB::remove() {
    if(num <= 0) return;
    delete saptar[num-1];
    num--;
}

void BB::BB_sort() {
    if(num < 2) return;
    string s1, s2;
    substance *temp;
    for(int i=0; i<num; i++) {
        for(int j=i+1; j<num; j++) {
            s1 = saptar[i]->getName();
            s2 = saptar[j]->getName();
            if(s1 > s2) {
                temp = saptar[i];
                saptar[i] = saptar[j];
                saptar[j] = temp;
            }
        }
    }
    queue = 1;
}

ostream & operator<<(ostream &stream, BB &ob) {
    stream << ob.title << endl;
    if(ob.queue == 0) stream << "Жадыбал сорттолгон эмес.\n";
    else stream << "Жадыбал сорттолгон.\n";
    header();
    if(!ob.num) stream << "Жадыбал бош.\n";
    else {
        for(int i=0; i<ob.num; i++) {
            stream << *ob.saptar[i];
        }
    }
    line();
    return stream;
}

ostream & operator<<(ostream &stream, const substance &ob) {
    char result[81];
    sprintf(result, "| %-18s| %-12c| %10.1f - %-11.1f|\n",
    ob.name.c_str(), ob.type, ob.temp1, ob.temp2);
    stream << result;
    return stream;
}

istream & operator>>(istream &stream, substance &ob) {
    printf("Заттын аталышын, тибин, 1 температурасын, 2 температурасын киргизгиле > \n");
    stream >> ob.name >> ob.type >> ob.temp1 >> ob.temp2;
    return stream;
}

substance::substance(string name, char type, float temp1, float temp2) {
    this->name = name;
    this->type = type;
    this->temp1 = temp1;
    this->temp2 = temp2;
}

void substance::set(string name, char type, float temp1, float temp2) {
    this->name = name;
    this->type = type;
    this->temp1 = temp1;
    this->temp2 = temp2;
}

void substance::get(string &name, char &type, float &temp1, float &temp2) {
    name = this->name;
    type = this->type;
    temp1 = this->temp1;
    temp2 = this->temp2;
}

void substance::show() {
    printf("%s %c %.1f %.1f\n", name.c_str(), type, temp1, temp2);
}

int main()
{
    string name;
    char type;
    float temp1, temp2;
    short i, q1, q2;
    BB *tmp = new BB("\n№1 берилиштер базасы\n");
    for(int a=0; !a; ){
        cout << "1. Жазылыш кошуу\n";
        cout << "2. Жазылышты очуруу\n";
        cout << "3. Базаны сорттоо\n";
        cout << "4. Базаны чыгаруу\n";
        cout << "5. Чыгуу\n> ";
        int p;
        cin >> p;
        switch (p)
        {
        case 1:
            cout << "Заттын аталышы, тиби, 1 температурасы, 2 температурасы \n";
            tmp->add("Zn", 'I', 0.8, 0.8);
            tmp->add("PBC", 'A', 2.7, 7.1);
            tmp->add("NDC", 'C', 10.1, 10.5);
            break;
        case 2:
            tmp->remove();
            break;
        case 3:
            tmp->BB_sort();
            break;
        case 4: {
            cout << *tmp;
            cout << "\nУлантуу учун каалаган баскычты бас...\n";
            getchar();
            break;
        }
        case 5: {
            a = 1;
            break;
        }
        default:
            cout << "Туура эмес чакыруу";
            getchar();
            break;
        }
    }
}