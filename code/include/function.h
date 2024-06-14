#ifndef DATA_H
#define DATA_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef unsigned long long ull;
typedef _Bool bool;
typedef char * string;

//string
_Bool stringcmp(const char *str1, char *str2,_Bool efficiency); //efficiency
ull stringsearch(char *str1, char *str2); 
char *erase(char *str,ull index,ull len);
char *strcopy(char *str, ull start, ull len);
//data conversion
string intToString(int num);
//file 
FILE *openfile(char *filename, char *mode);
string readfile(FILE *file, ull len);
void closefile(FILE *file);
void writetofile(FILE *file, char *str);
ull fileSize(FILE *file);
#endif