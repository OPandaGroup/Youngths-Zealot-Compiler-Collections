//
// @date:2024/07/16
// @file:PDebug.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "../include/PDebug.h"

#ifdef __Panda_Debug__
void PDebug(string message){
    SetColor(GREEN);
    printf("Debug: %s", message);
    ClearColor();
}

void PDebugLine(string message, _Bool newline){
    SetColor(GREEN);
    if(newline){
        printf("Debug: %s\n", message);
    }else{
        printf("Debug: %s", message);
    }
    ClearColor();
}

void print_DebugFile(string message){
    FILE *fp = openfile("debug.log", "a");
    fprintf(fp ,"%s", message);
    closefile(fp);
}

void init_DebugFile(){
    FILE *fp = openfile("debug.log", "w");
    fprintf(fp ,"-----------Panda Debug-----------\n");
    closefile(fp);
}

void print_DebugFileLine(string message, _Bool newline){
    FILE *fp = openfile("debug.log", "a");
    if(newline){
        fprintf(fp ,"%s\n", message);
    }else{
        fprintf(fp ,"%s", message);
    }
    closefile(fp);
}

void print_String(string message){
    SetColor(BLUE);
    for (ull i = 0; i < strlen(message); i++){
        putchar(message[i]);
    }
    ClearColor();
}

#else
void PDebug(string message){}
void PDebugLine(string message, _Bool newline){}
void print_DebugFile(string message){}
void print_DebugFileLine(string message, _Bool newline){}
void print_String(string message){}
void init_DebugFile(){}
#endif