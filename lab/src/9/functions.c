/*******************************************************/
/*               Лаборатордук иш №9                    */
/*               functions.c  файлы                    */
/*******************************************************/
/*  Глобалдык өзгөрмөлөрдү колдонгон функциялар  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "substance.h"
#include "functions.h"
#include "methods.h"
static FILE *file; /* файл */
static char filename[15];
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

void initfile(char *name)
{
    strcpy(filename, name);
    if ((file = fopen(filename, "a+")) == NULL)
    {
        printf("%s - файлын ачууга мүмкүн эмес! \n", filename);
        exit(0);
    }
    char temp[81];
    while (fgets(temp, 80, file)) n++;
    
}

void file_cleaning() {
    fclose(file);
    if((file = fopen(filename, "w+")) == NULL) {
        printf("%s - файлын ачууга мүмкүн эмес! \n", filename);
        exit(0);
    }
}

void _close() {
    fclose(file);
}

void add(SUBSTANCE *a) {
    fseek(file, 0, SEEK_END);
    fprintf(file, "%s %c %.1f %.1f\n", a->name, a->type, a->temp1, a->temp2);
}

void f_show_row(int n) {
    SUBSTANCE x;
    char buf[81];
    fseek(file, 0, SEEK_SET);
    for(int i=0; fgets(buf, 80, file); i++) {
        if(i == n-1) {
            sscanf(buf, "%s %c %f %f", x.name, &x.type, &x.temp1, &x.temp2);
            show_row(&x);
            return;
        }
    }
}

void show_all() {
    SUBSTANCE x;
    char buf[81];
    fseek(file, 0, SEEK_SET);
    header();
    while (fgets(buf, 80, file)) {
        sscanf(buf, "%s %c %f %f", x.name, &x.type, &x.temp1, &x.temp2);
        print_row(&x);
    }
    line();
}

/**** элементти өчүрүү ****/
void erase(int m) {
    int c = 0;
    fseek(file, 0, SEEK_END);
    char buf[ftell(file)], temp[81];
    fseek(file, 0, SEEK_SET);
    char *k1, *k2;
    k1 = buf;
    for(int i=1; fgets(temp, 80, file); i++) {
        if(i == m) continue;
        k2 = temp;
        while(*k2) {
            *k1++ = *k2++;
            c++;
        }
    }
    buf[c] = 0;
    file_cleaning();
    fprintf(file, "%s", buf);
}
