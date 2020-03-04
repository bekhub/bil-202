/*******************************************************/
/*               Лаборатордук иш №7                    */
/*                  main.c  файлы                      */
/*******************************************************/
#include <stdio.h>
#include "substance.h"
#include "methods.h"
#include "functions.h"
#define N 100
SUBSTANCE mas[N]; /* жадыбал-массив */
int n = 0;     /* массив элементеринин саны */

/**** негизги функция ****/
int main(void)
{
    int amal; /* амал */
    int nom;  /* элемент номери */
    int ja;  /* жумуш аягы */
    /*  */
    for (ja = 0; !ja;)
    {
        /*  меню */
        printf("1 – Элементти кошуу\n");
        printf("2 – Элементти өчүрүү\n");
        printf("3 – Номер боюнча элементти көрсөтүү \n");
        printf("4 – Баарын чыгаруу\n");
        printf("0 - Чыгуу\n");
        printf("Танда > ");
        /* менюдан тандоо  */
        scanf("%d", &amal);
        switch (amal)
        {
            case 0: /* чыгуу */
                ja = 1;
                break;
            case 1: /* кошуу */
                if (!input_row(mas + n)) n++;
                break;
            case 2: /* өчүрүү */
                if (!check(nom = input_number())) {
                    erase(nom);
                    n--;
                }
                break;
            case 3: /* бирди чыгаруу */
                if (!check(nom = input_number()))
                    show_row(mas + nom - 1);
                break;
            case 4: /* барын чыгаруу */
                show_all();
                break;
            default:
                printf("Жаңылыш амал\n");
                break;
        } /* switch */
        if (amal) {
            printf("Каалаган баскычты бас \n");
            getchar();
        } /* if */
    }     /* for */
    return 0;
} /* main */