#include <stdio.h>
#include <alloca.h>
#include <time.h>
#include <stdlib.h>

void check(int);
void fill(int*, int);

int main() {
    int *A, *C;
    int size, i;

    printf("Матрицанын олчомун киргизгиле > ");
    scanf("%d", &size);
    check(size);
    if((A = (int*)malloc(sizeof(int)*size*size)) == NULL) {
        printf("Эс жетишсиз\n");
        exit(0);
    }

    fill(A, size);

    putchar('\n');
    for(C = A, i = 0; i < size*size; C++, i++) {
        printf("%3d", *C);
        if(i%size == size-1) putchar('\n');
    }

    free(A);
    return 0;
}

void fill(int *A, int size) {
    int *C, i, xi = size - 1, j, r = 0;
    int sum[size], arr[size][size];
    for(int x = 0; x < size; sum[x++] = 0);
    srand(time(NULL));
    for(C = A, i = 0, j = 0; C < A + (size*size); i++, C++) {
        *C = rand() % 6;
        arr[j][i%size] = *C;
        if(i%size == size-1) j++;
    }
    for(C = A, i = 0; i < size*size; C++, i++) {
        printf("%3d", *C);
        if(i%size == size-1) putchar('\n');
    }
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            sum[x]+=arr[x][y];
            sum[x]+=arr[y][size-x-1];
        }
        sum[x]-=arr[x][size-x-1];
    }
    for(C = A, i = 0, j = 0; i < size*size && xi >= 0; C++, i++) {
        if(i == j*size+xi){
            *C = sum[r++];
            xi--;
        }
        if(i%size == size-1) j++;
    }
}

void check(int size) {
    if(size <= 0) {
        printf("Олчому ото кичинекей\n");
        exit(0);
    }
    if(size > 24) {
        printf("Олчому ото чон\n");
        exit(0);
    }
    printf("size = %d\n", size);
}