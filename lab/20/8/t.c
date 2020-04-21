#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sap[20] = "02 hello world\n", *s;
    int ss, su;
    printf("%s\n", sap);
    sap[2] = 0;
    ss = atoi(sap);
    s = sap + 3;
    su = strlen(s) - 1;
    s[su] = 0;
    printf("%d %s\n%s\n", ss, sap, s);
}