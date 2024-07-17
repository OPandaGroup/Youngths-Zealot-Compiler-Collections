//
// @date:2024/07/16
// @file:PSystem.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "../include/PSystem.h"

#ifndef Sys
#define Sys "Windows"
#endif

void _ShellToUTF8() {
    ShellToUTF8();
}

void _gotoXY(int x, int y) {
    gotoXY(x, y);
}

char *_getSystem() {
    #ifdef Win_NT
        return "Windows";
    #endif
    #ifdef Linux
        return "Linux";
    #endif
}