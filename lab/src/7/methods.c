/*******************************************************/
/*                  Лаборатодук иш №7                  */
/*                  methods.c  файлы                   */
/*******************************************************/
#include <stdio.h>
#include <string.h>
#include "substance.h"
#include "methods.h"
extern SUBSTANCE mas[];
extern int n;

/**** бир зат жөнүндө маалыматтарды чыгаруу ***/
void show_row(SUBSTANCE *m)
{
    line();
    printf("| Зат             : %s", m->name);
    printf("\n| Тиби            : ");
    switch (m->type)
    {
        case 'I':
            printf("Темир");
            break;
        case 'A':
            printf("Эритме");
            break;
        case 'C':
            printf("Кошунду");
            break;
    }
    printf("\n| Температура     : %.1f - %.1f\n", m->temp1, m->temp2);
    line();
}

/**** жадыбалдын сабын чыгаруу ****/
void print_row(SUBSTANCE *m)
{
    printf("| %-18s| %c           | %10.1f - %-11.1f|\n",
           m->name, m->type, m->temp1, m->temp2);
}

/**** астын сызуу ****/
void line()
{
    printf("|-----------------------------------------------------------|\n");
}

/**** жадыбалдын башын чыгаруу ****/
void header()
{
    line();
    printf("|Заттын жогорку өткөргүч абалына өтүү температурасы         |\n");
    printf("|-----------------------------------------------------------|\n");
    printf("| Зат               | Тиби        | Температура             |\n");
    printf("|-------------------|-------------|-------------------------|\n");
}

/**** элементти өчүрүү ****/
void erase(int m)
{
    for (; m < n; m++)
        memcpy(mas + m - 1, mas + m, VALUE);
}

/**** массивди толугу менен чыгаруу ****/
void show_all()
{
    header();
    for (int i = 0; i < n; print_row(mas + i), i++);
    line();
}