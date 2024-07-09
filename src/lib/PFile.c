#include "../include/PFile.h"

FILE *openfile(const char *filename, char *mode) {
    return fopen(filename, mode);
}

char *readfile(FILE *file, ull len){
    char *string = (char *)malloc(len+1);
    memset(string, 0, len+1);
    fread(string, len, 1, file);
    string[len] = '\0';
    return string;
}

void closefile(FILE *file) {
    fflush(file);
    fclose(file);
}

void writetofile(FILE *file, char *str) {
    fputs(str, file);
}

void writeline(FILE *file, char *str) {
    fputs(str, file);
    fputs("\n", file);
}

ull fileSize(FILE *file) {
    ull size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}
