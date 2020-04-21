#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <alloca.h>
#include <math.h>

int main(void) {
    int size, max = 0;
    int *A;
    int *C, *I, *S, *E;
    int ort, n;
    srand(time(NULL));
    size = 50 + rand() % 151;
    printf("size=%d\n", size);
    A = (int*)malloc(size * sizeof(int));
    printf("Баштапкы массив:\n");
    for(C = A; C < A + size; C++){
        *C = rand() % 101 - 50;
        printf("%3d ", *C);
    }
    putchar('\n');
    for(n=0, C=A; C < A + size; C++) {
        if(*C < 0)
            if(!n) {
                I = C;
                ort = *C;
                n = 1;
            }
            else {
                ort += *C;
                n++;
            }
        else
            if(n) {
                ort /= n;
                if(max < abs(ort)){
                    max = abs(ort);
                    S = I;
                    E = C;
                }
                n = 0;
            }
    }
    if(n){
        ort /= n;
        if(max < abs(ort)){
            max = abs(ort);
            S = I;
            E = C;
        }
    }
    printf("Эн чон орточо арифметикалык маанисинин абсолюттук маанисине ээ болгон удаалаштык:\n");
    for(; S < E; printf("%3d ", *S++));
    putchar('\n');
    free(A);
    return 0;
}