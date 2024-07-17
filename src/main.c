#include <stdio.h>
#include <stdlib.h>
#include "./include/PDebug.h"
#include "./include/Pprint.h"
#include "./include/PSystem.h"
#include "./include/PDataStructure.h"

int main(int argc, char ** argv){
    _ShellToUTF8();
    FILE *fp = fopen("build.xml", "r");
    if (fp == NULL) printError("yzcc", "文件打开错误", "build.xml文件不存在!");
    else{
        string file = "<project name='test.c' default='build'>\
    <symbol>\
        <int name='a' scope='global' value='1'></int>\
        <char name = 'b' scope='global' value='a'></char>\
    </symbol>\
    <text>\
        <fun name = 'test' args='' return = 'int'>\
            <return> '</return>\
        </fun> \
        <fun name='main' args='' return = 'int'>\
            <int name='a' scope='local' value='1'></int>\
            <char name = 'b' scope = 'local' value = 'a'></char>\
            <call name='test' args=''></call>\
            <set name='a' value='1'></set>\
            <call name='printf'    args='{string:,int:a}'></call>\
            <return fun='main'> 0</return>\
        </fun>\
    </text>\
</project>";
        get_tree_from_XML(file);
    }
    // bool is_str = false, is_str_dm = false;
    // string str = "name='a' scope='global'                           value='1'";
    // string data = malloc(strlen(str)+1); memset(data, 0, strlen(str)+1);
    // for(ull i = 0; i < strlen(str); i++){
    //     if(str[i] == ' ' && str[i-1] == ' '){
    //         if(is_str || is_str_dm) data[strlen(data)] = ' ';
    //         else continue;;
    //     }else if(str[i] == ' ' && str[i-1] != ' '){
    //         data[strlen(data)] = ',';
    //     }else{
    //         data[strlen(data)] = str[i];
    //     }
    // }
    // data[strlen(data)] = '\0';
    // print_list(split(data, ','));
    // print_String(data);
    return 0;
} 