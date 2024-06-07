#include <stdio.h>
#include <stdlib.h>
#include "./include/data.h"
#include "./include/print.h"

// 完成对define的宏定义

void define(char *str, int line, int len){
    
}

void macro_read(char *str){
    string str_list = (string )malloc(sizeof(string));
    int len = 0 ;  //string len 
    for(int i = 0; i < strlen(str); i++){
        switch (str[i]){
            case '\n':
                if (str_list[len-1])
                {
                    /* code */
                }
                
                break;
            case '/':
                break;
            case ' ':
                str_list = (string)realloc(str_list,sizeof(str_list)-1);
                break;
            default:
                str_list[len] = str[i] ;
                break;
        }
        if(str[i] != ' '){
            len ++;
        }
    }
    return str_list;
}

int main(int argc, char *argv[]){    
    if(argc != 2){
        perror("Usage: ./macro <filename>");
    }
    FILE *file = openfile(argv[1], "r");
    if(file == NULL){
        perror("Error opening file");
    }
    char *str = readfile(file, fileSize(file));
    printf("%s",str);
    macro_read(str);
    closefile(file);
}