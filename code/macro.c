#include <stdio.h>
#include <stdlib.h>
#include "./include/data.h"
#include "./include/print.h"

// 完成对define的宏定义

void define(char *str, int line, int len){
    
}

void macro_read(char *str){
    bool string = false;
    bool annotation = false;
    int len = 0 ;
    int an_len = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '\n'){
            //完成刷新
            annotation = false;
            an_len = 0;
            string = false;
            len++;
            printf("clear");
        }else if (str[i] == '/')
        {
            //完成注释判断
            if(annotation){
                continue;
            }else{
                annotation++;
            }
            if(annotation >= 2){
                annotation = true;
            }
        }else if (str[i] == '"'||str[i] == 39)
        {
            //完成对字符串判断
            string = !string;
        }else if (str[i] == '#'){

        }else{

        }
    }
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