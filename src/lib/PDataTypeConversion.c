//
// @date:2024/07/16
// @file:PDataTypeConversion.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "../include/PDataTypeConversion.h"

string intToString(int num){
    string str = malloc(1);
    memset(str, 0, sizeof(char));
    int len = 0;
    if(num == 0){
        return "0";
    }
    while (num){
        str[len] = (num % 10) + '0';
        num /= 10;
        len++;
        str = realloc(str,len+1);
    }
    str[len] = '\0';
    return stringFlip(str);
    // return stringFlip(str);
}

int stringToInt(string str){
    bool is_f = 0;
    int num = 0;
    for(int i = 0; i < strlen(str); i++){
        if((str[i] < '0' || str[i] > '9') && str[i] != '-'){
            return 0;
        }else if(str[i] == '-' && i != 0){
            return 0;
        }else if(str[i] == '-' && i == 0){
            is_f = true;
        }else{
            num = num * 10 + (str[i] - '0');
        }
    }
    if(is_f){
        return -1*num;
    }else{
        return num;
    }
}