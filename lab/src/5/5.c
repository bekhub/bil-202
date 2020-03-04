#include <stdio.h>
#include <string.h>

int func(char *, char *);

int main(void)
{
    char soz[20], sap[80];
    int r;
    while(1) {
        printf("Сап киргизгиле>");
        gets(sap);
        if(!strcmp(sap, "***")) break;
        printf("Созду киргизгиле > ");
        scanf("%s", soz);
        r = func(soz, sap);
        printf("сап =>>%s<<\n", sap);
        printf("соз =>>%s<<\n", soz);
        printf("Саптагы создун биринчи жолуккан жери=%d\n\n", r);
        gets(sap);
    }
}

int func(char *soz, char *sap){
    int index, n = 0;
    char *I;
    I = soz;
    for(int i = 0; *sap; sap++, i++) {
        if(*sap == *I) {
            if(*soz == *I) {
                index = i;
                I++;
            }
            else I++;
        } else {
            if(!*I) return index;
            else I = soz;
        }
    }
    if(!*I) return index;
    return -1;
}