//
// @date:2024/07/16
// @file:PLinux.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "PLinux.h"

void gotoXY(int x, int y){
   printf("%c[%d;%df",0x1B,y,x);  
}

void ShellToUTF8(){
   setlocale(LC_ALL, "");
}