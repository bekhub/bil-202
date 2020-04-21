/*******************************************************/
/*               Лаборатордук иш №9                    */
/*                  main.c  файлы                      */
/*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "substance.h"
#include "methods.h"
#include "functions.h"
#define N 100
SUBSTANCE x; /* жадыбал-массив */
int n = 0;     /* массив элементеринин саны */

/**** негизги функция ****/
int main(int par1, char *par2[])
{
    int amal; /* амал */
    int nom;  /* элемент номери */
    int ja;  /* жумуш аягы */
    /* параметрди текшерүү */
    if (par1 < 2)
    {
        printf("Программага кайрылуу туура эмес\n");
        exit(0);
    }
    /* файлды ачуу */
    initfile(par2[1]);
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
                if (!input_row(&x)){
                    add(&x);
                    n++;
                }
                break;
            case 2: /* өчүрүү */
                if (!check(nom = input_number())) {
                    erase(nom);
                    n--;
                }
                break;
            case 3: /* бирди чыгаруу */
                if (!check(nom = input_number())) f_show_row(nom);
                break;
            case 4: /* барын чыгаруу */
                show_all();
                break;
            default:
                printf("Жаңылыш амал\n");
                break;
        } /* switch */
        if (amal) {
            printf("Каалаган баскычты бас ");
            getchar();
            getchar();
        } /* if */
    }     /* for */
    _close();
    return 0;
} /* main */