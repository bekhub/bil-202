/*******************************************************/
/*               Лаборатордук иш №9                    */
/*      Программаны бир нече файлдан түзүү             */
/*                  20-Вариант                         */
/*******************************************************/
/*               substance.h файлы                     */
/*******************************************************/
#ifndef SUBSTANCE_H
#define SUBSTANCE_H
#define SUBSTANCE struct substance
#define VALUE sizeof(struct substance)

/* Затты баяндаган түзүмдү баяндоо */
struct substance
{
    char name[15]; /* аталышы */
    char type;     /* тиби */
    float temp1;   /* температурасы */
    float temp2;   /* температурасы */
};

#endif