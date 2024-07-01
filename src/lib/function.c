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
    }else if (strlen(str1)==strlen(str2)){
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
    return -1;
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

char *stringcut_(char *str, ull start, ull end){
    return stringcut(str, start, end - start + 1);  
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
    string strs = malloc(strlen(str)+1);
    for(int i = 0;i < strlen(str) ; i++){
        strs[i] = str[strlen(str)-1-i];
    }
    return strs;
}

string insert(string str, ull index, char *str2){
    string strs = malloc(strlen(str)+strlen(str2)+1);
    memset(strs, 0, strlen(str)+strlen(str2)+1);
    for(ull i = 0;i < index ; i++){
        strs[i] = str[i];
    }
    for(ull i = 0;i < strlen(str2) ; i++){
        strs[index+i] = str2[i];
    }
    for (ull i = 0; i < strlen(str) - index ; i++){
        strs[index+strlen(str2)+i] = str[index+i];
    }
    return strs;
}

void inserts(string str, ull index, char *str2){
    str = insert(str,index,str2);
}

void Flip(string str){
    str = stringFlip(str);
}

string Nicts(string str, ull index, char stop) {
    char *strs = malloc(strlen(str));
    int len = 0;
    bool is_str = false, is_str_md = false; // md为双引号
    for(int i = index ; i < strlen(str) ; i++){
        if (str[i] == stop){
            strs[++len] = '\0';
        }else if (str[i] == '"' && !is_str){
            is_str_md = !is_str_md;
            strs[++len] = str[i];
        }else if (str[i] == 39 && !is_str_md){
            is_str = !is_str;
            strs[++len] = str[i];
        }else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') && !is_str && !is_str_md){
            continue;
        }else{
            strs[++len] = str[i];
        }
    }
    strs[++len] = '\0';
    strs = realloc(strs,strlen(strs)+1);
    return strs;
}

string Nictsc(string str, char ch[], ull index, char stop) {
    char *strs = malloc(strlen(str));
    int len = 0;
    bool is_str = false, is_str_md = false, flag = 0; // md为双引号
    for(int i = index ; i < strlen(str) ; i++){
        if (str[i] == stop){
            strs[++len] = '\0';
        }else if (str[i] == '"' && !is_str){
            is_str_md = !is_str_md;
            strs[++len] = str[i];
        }else if (str[i] == 39 && !is_str_md){
            is_str = !is_str;
            strs[++len] = str[i];
        }else{
            flag = 0;
            for(int j = 0; j < strlen(ch); j++){
                if (str[i] == ch[j] && !is_str_md && !is_str){
                    flag = 1;
                    break;
                }
            }
            if(!flag)   strs[++len] = str[i];
        }
    }
    strs[++len] = '\0';
    strs = realloc(strs,strlen(strs)+1);
    return strs;
}

string Forward_Nicts(string str, ull index, char stop) {
    char *strs = malloc(strlen(str));
    int len = 0;
    bool is_str = false, is_str_md = false; // md为双引号
    for (int i = index; i >= 0; i--){
        if (str[i] == stop){
            strs[++len] = '\0';
        }else if (str[i] == '"' && !is_str){
            is_str_md = !is_str_md;
            strs[++len] = str[i];
        }else if (str[i] == 39 && !is_str_md){
            is_str = !is_str;
            strs[++len] = str[i];
        }else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') && !is_str && !is_str_md){
            continue;
        }else{
            strs[++len] = str[i];
        }
    }
    strs[++len] = '\0';
    strs = realloc(strs,strlen(strs)+1);
    return strs;
}

string Forward_Nictsc(string str, char ch[], ull index, char stop){
    char *strs = malloc(strlen(str));
    int len = 0;
    bool is_str = false, is_str_md = false, flag = 0; // md为双引号
    for (int i = index; i >= 0; i--){
        if (str[i] == stop){
            strs[++len] = '\0';
        }else if (str[i] == '"' && !is_str){
            is_str_md = !is_str_md;
            strs[++len] = str[i];
        }else if (str[i] == 39 && !is_str_md){
            is_str = !is_str;
            strs[++len] = str[i];
        }else{
            flag = 0;
            for(int j = 0; j < strlen(ch); j++){
                if (str[i] == ch[j] && !is_str_md && !is_str){
                    flag = 1;
                    break;
                }
            }
            if(!flag)   strs[++len] = str[i];
        }
    }
    strs[++len] = '\0';
    strs = realloc(strs,strlen(strs)+1);
    return strs;
}

string Icts(string str, ull index, char stop){
    string strs = malloc(strlen(str));
    ull len = strlen(str);
    for(int i = index ; i < strlen(str) ; i++){
        if (str[i] == stop){
            strs[i-index] = '\0';
            break;
        }else{
            strs[i-index] = str[i];
        }
    }
    strs[++len] = '\0';
    strs = realloc(strs,strlen(strs)+1);
    return strs;
}

string Forward_Icts(string str, ull index, char stop){
    return Forward_Ergodic(str,index,stop);
}

bool Nicts_bool(string str, ull index, char stop){
    bool is_str = 0, is_str_md = 0;
    for(int i = index; i<strlen(str);i++){
        if(str[i]==stop){
            return 0;
        }else if (str[i]=='"' && !is_str){
            is_str_md = !is_str_md;
        }else if (str[i]==39 && !is_str_md){
            is_str = !is_str;
        }else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') && !is_str && !is_str_md){
            return 1;
        }else{
            continue;
        }
    }
    return 0;
}

bool Nictsc_bool(string str, char ch[], ull index, char stop){
    bool is_str = 0, is_str_md = 0;
    for(int i = index; i<strlen(str);i++){
        if(str[i]==stop){
            return 0;
        }else if (str[i]=='"' && !is_str){
            is_str_md = !is_str_md;
        }else if (str[i]==39 && !is_str_md){
            is_str = !is_str;
        }else{
            for(int j = 0; j < strlen(ch); j++){
                if (str[i] == ch[j] && !is_str_md && !is_str){
                    return 0;
                }
            }
            continue;
        }
    }
    return 0;
}

bool Icts_bool(string str, ull index, char stop){
    bool is_str = 0, is_str_md = 0;
    for(int i = index; i<strlen(str);i++){
        if (str[i] == stop){
            return 0;
        }else if (str[i]=='"' && !is_str){
            is_str_md = !is_str_md;
        }else if (str[i]==39 && !is_str){
            is_str = !is_str;
        }else if((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') && !is_str_md && !is_str){
            return 1;
        }else{
            continue;
        }
        return 0;
    }
}

bool Ictsc_bool(string str, char ch[], ull index, char stop){
    bool is_str = 0, is_str_md = 0;
    for(int i = index; i<strlen(str);i++){
        if (str[i] == stop){
            return 0;
        }else if (str[i]=='"' && !is_str){
            is_str_md = !is_str_md;
        }else if (str[i]==39 && !is_str_md){
            is_str = !is_str;
        }else{
            for (int j = 0; j < strlen(ch); j++){
                if(ch[j] == str[i] && !is_str_md && !is_str){
                    return 1;
                }
            }
            continue;
        }
        return 0;
    }
}

bool Fowrard_Nicts_bool(string str, ull index, char stop){
    bool is_str = 0, is_str_md = 0;
    for(int i = index; i>=0; i--){
        if(str[i]==stop){
            return 0;
        }else if (str[i]=='"'){
            is_str_md = !is_str_md;
        }else if (str[i]==39){
            is_str = !is_str;
        }else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r') && !is_str && !is_str_md){
            return 1;
        }else{
            continue;
        }
    }
}

bool Fowrard_Nictsc_bool(string str, char ch[], ull index, char stop){
    bool is_str = 0, is_str_md = 0;
    for(int i = index; i>=0; i--){
        if(str[i]==stop){
            return 0;
        }else if (str[i]=='"' && !is_str){
            is_str_md = !is_str_md;
        }else if (str[i]==39 && !is_str_md){
            is_str = !is_str;
        }else{
            for (int j = 0; j < strlen(ch); j++){
                if(ch[j] == str[i] && !is_str_md && !is_str){
                    return 1;
                }
            }
            continue;
        }
    }
}

bool Forward_Icts_bool(string str, ull index, char stop){
    bool is_str = 0, is_str_md = 0;
    for(int i = index; i<strlen(str);i++){
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'){
            return 1;
        }else{
            continue;
        }
    }
}

bool Forward_Ictsc_bool(string str, char ch[], ull index, char stop){
    bool is_str = 0, is_str_md = 0;
    for(int i = index; i<strlen(str);i++){
        for (int j = 0; i < strlen(ch); i++){
            if(ch[j] == str[i] && !is_str_md && !is_str){
                return 1;
            }
        }
        
    }
    return 0;
}

string delchar(string str, char ch){
    string strs = malloc(strlen(str));
    bool is_str = 0, is_str_dm = 0;
    int index = 0;
    for (int i = 0; i < strlen(str); i++){
        if(str[i]==ch && !is_str_dm && !is_str){
            continue;
        }else if(str[i]=='"' && !is_str){
            is_str_dm = !is_str_dm;
            strs[index] = str[i];
            index++;
        }else if(str[i]=='\'' && !is_str_dm){
            is_str = !is_str;
            strs[index] = str[i];
            index++;
        }else{
            strs[index] = str[i];
            index ++;
        }
    }
    strs = realloc(strs,strlen(strs)+1);
    strs[index] = '\0';
    return strs;
}

/*data function*/

string intToString(int num){
    string str = malloc(1);
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
    return stringFlip(str);
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

/*file function*/

FILE *openfile(const char *filename, char *mode) {
    return fopen(filename, mode);
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