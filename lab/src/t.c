#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <alloca.h>

int main()
{
    char *sap;//[30];
    sap = (char*)malloc(30 * sizeof(char));
    gets(sap);
    for(; *sap; printf("%c", *sap), sap++);
    if(!*sap) printf("tadam %c %d", *sap, *sap);
    putchar('\n');
}