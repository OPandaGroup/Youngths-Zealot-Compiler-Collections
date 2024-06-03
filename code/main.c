#include <stdio.h>  
#include <stdlib.h>
#include <Windows.h>
#include "./include/data.h"

int main(int argc, char const *argv[])
{
    if (argc == 1){
        system(".\\version.exe");
        return 0;
    }
    //完成对指令的解析
    for (int i=1;i<argc;i++){
        if (stringcmp(argv[i],"--version",0)){
            system(".\\version.exe");
            return 0;
        }else if (stringcmp(argv[i],"--help",0))
        {
            system(".\\help.exe");
            return 0;
        }
        else
        {
            perror("参数错误");
        }
        
    }
    return 0;
}
