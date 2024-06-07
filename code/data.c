#include "./include/data.h"

_Bool stringcmp(const char *str1, char *str2,_Bool efficiency){
    if(strlen(str1)!=strlen(str2)){
        return 0;
    }
    if(efficiency){
        for (ull index = 0; index < strlen(str2); index++){
            if (str1[index]!=str2[index]){
                return 0;
            }
        }
        return 1;
    }else{
        _Bool flag = 1;
        for (ull index = 0; index < strlen(str2); index++){
            if (str1[index]!=str2[index]){
                flag = 0;
            }
        }
        return flag;
    }
}

ull stringsearch(char *str1, char *str2) {
    ull index2=0;
    if(strlen(str1)<strlen(str2)){
        return -1;
    }else if (strlen(str1)==strlen(str2))
    {
        stringcmp(str1,str2,1);
    }else{
        for (ull index1 = 0; index1 < strlen(str1); index1++){
            if (str1[index1]==str2[index2]){
                index2++;
            }else if(index2==(strlen(str2))){
                return index1-index2;
            }else{
                index2=0;
            }
        }
    }
}

char *erase(char *str,ull index,ull len){
    char *string = (char *)malloc(strlen(str));
    memset(string,0,strlen(str)-len);
    ull lenght = strlen(str);
    _Bool flag = 0;
    for(int idx = 0; idx < lenght; idx++){
        if(idx<index||idx>=index+len&&!flag){
            string[idx] = str[idx];
        }else if(flag&&idx<index||idx>=index+len){
            string[idx-len] = str[idx];
        }else{
            flag = 1;
            continue;
        }
    }
    return string;
}

char *strcopy(char *str, ull start, ull len){

}

string intToString(int num){
    int len = log10((double)num) + 1;
    char *str = malloc(len);
    memset(str,0,sizeof(str));
    for(int i = 0 ; i < len ; i++){
        str[len-1-i]=(num%10)+'0';
        num/=10;
    }
    return str ;
}

FILE *openfile(char *filename, char *mode) {
    FILE *file = fopen(filename, mode);
    return file;
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