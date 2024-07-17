//
// @date:2024/07/16
// @file:PFile.h
// @author:Writing 
// @copyright: Panda, 2024
//
#ifndef _PFile_H_
#define _PFile_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/PDataStructure.h"

typedef size_t ull;
typedef char * string;

FILE *openfile(const char *filename, char *mode);
string readfile(FILE *file, ull len);
void closefile(FILE *file);
void writetofile(FILE *file, char *str);
ull fileSize(FILE *file);

#endif 