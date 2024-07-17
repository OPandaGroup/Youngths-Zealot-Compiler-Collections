//
// @date:2024/07/16
// @file:Pprint.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "../include/Pprint.h"

void printError(char *sender, char *error, char *situation){
    printf("\033[1;31;40m[Error]%s: %s\ndetails:%s \033[0m",sender,situation,error );
}