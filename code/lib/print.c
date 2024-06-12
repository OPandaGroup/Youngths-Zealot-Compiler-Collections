#include "../include/print.h"

void printError(char *sender, char *error, char *situation){
    printf("\033[1;31;40m[Error]%s: %s\ndetails:%s",sender,situation,error);
}