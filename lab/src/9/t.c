#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int c = 0;
    if ((file = fopen("text.txt", "r")) == NULL)
    {
        printf("%s - файлын ачууга мүмкүн эмес! \n", "text.txt");
        exit(0);
    }
    fseek(file, 0, SEEK_END);
    char buf[ftell(file)], temp[81];
    fseek(file, 0, SEEK_SET);
    char *k1, *k2;
    k1 = buf;
    for(int i=1; fgets(temp, 80, file); i++) {
        if(i == 2) continue;
        k2 = temp;
        while(*k2) {
            *k1++ = *k2++;
            c++;
        }
    }
    buf[c] = 0;
    fclose(file);
    file = fopen("text.txt", "w+");
    fprintf(file, "%s", buf);
    fclose(file);
}