/*******************************************************/
/*               Лаборатордук иш №7                    */
/*               functions.c  файлы                    */
/*******************************************************/
/*  Глобалдык өзгөрмөлөрдү колдонгон функциялар  */
#include <stdio.h>
#include <string.h>
#include "substance.h"
#include "functions.h"
extern int n;

/**** элемент номерини текшерүү ****/
int check(int a)
{
    if (a < 1)
    {
        printf("Минималдуу номер : 1\n");
        return -1;
    }
    if (a > n)
    {
        printf("Максималдуу номер : %d\n", n);
        return -1;
    }
    return 0;
}

/****  номерди киргизүү ****/
int input_number()
{
    int b;
    printf("номерди киргиз > ");
    scanf("%d", &b);
    return b;
}

/**** бир зат жөнүндө берилиштерди киргизүү ***/
int input_row(SUBSTANCE *m)
{
    /* берилиштерди киргизүү */
    printf("Заттын аталышын, тибин, 1 температурасын, 2 температурасын киргизгиле > \n");
    scanf("%s %c %f %f", m->name, &m->type, &m->temp1, &m->temp2);
    if (!strcmp(m->name, "***"))
        return -1;

    if (strchr("IAC", m->type) == NULL)
    {
        printf("Ката\n");
        return -2;
    }
    return 0;
}