#include "../include/function.h"

/*string function*/
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

char *strappend(char *str, char *str2){
    char *string = (char *)malloc(strlen(str)+strlen(str2)+1);
    memset(string,0,strlen(str)+strlen(str2)+1);
    for (int i = 0; i < strlen(str); i++){
        string[i] = str[i];
    }
    for (int i = 0; i < strlen(str2); i++){
        string[strlen(str)+i] = str2[i];
    }
    return string ;
}

char *stringcut(char *str, ull index, ull len) {
    char *string = (char *)malloc(len+1);
    memset(string,0,len+1);
    for (int i = 0; i < len; i++){
        string[i] = str[index+i];
    }
    string[len] = '\0';
    return string;
}

char *Forward_Ergodic(char *str, ull index, char stop) {
    char *string = (char *)malloc(strlen(str));
    memset(string, 0, strlen(str));
    int fi = 0 ; 
    for(int i = index ; i >= 0 ; i--){
        if(str[i]==stop){
            break;
        }else{
            string[fi++] = str[i];
        }
    }
    string[fi] = '\0';
    string = realloc(string,strlen(string)+1);
    return string;
}

string stringFlip(string str){
    string strs = "\0";
    for(int i = 0;i < strlen(str) ; i++){
        strs[i] = str[strlen(str)-1-i];
    }
    return strs;
}

void Flip(string str){
    str = stringFlip(str);
}

string Nicts(string str, ull index, char stop) {
    char *strs = "\0";
    int len = 0;
    bool is_str = false, is_str_md = false; // md为双引号
    for(int i = index ; i < strlen(str) ; i++){
        if (str[i] == stop){
            strs[++len] = '\0';
        }else if (str[i] == '"'){
            is_str_md = !is_str_md;
        }else if (str[i] == 39){
            is_str = !is_str;
        }else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') && !is_str && !is_str_md){
            continue;
        }else{
            strs[++len] = str[i];
        }
    }
    return strs;
}

string Forward_Nicts(string str, ull index, char stop) {
    char *strs = "\0";
    int len = 0;
    bool is_str = false, is_str_md = false; // md为双引号
    for (int i = index; i >= 0; i--){
        if (str[i] == stop){
            strs[++len] = '\0';
        }else if (str[i] == '"'){
            is_str_md = !is_str_md;
        }else if (str[i] == 39){
            is_str = !is_str;
        }else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') && !is_str && !is_str_md){
            continue;
        }else{
            strs[++len] = str[i];
        }
    }
    return strs;
}

string Icts(string str, ull index, char stop){
    string strs = "\0";
    printf("%ld", strlen(str));
    ull len = strlen(str);
    for(int i = index ; i < strlen(str) ; i++){
        printf("%d", i);
        if (str[i] == stop){
            strs[i-index] = '\0';
            break;
        }else{
            strs[i-index] = str[i];
        }
    }
}

string Forward_Icts(string str, ull index, char stop){
    return Forward_Ergodic(str,index,stop);
}

/*data function*/

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

/*file function*/

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