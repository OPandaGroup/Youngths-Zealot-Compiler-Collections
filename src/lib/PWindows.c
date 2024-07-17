//
// @date:2024/07/16
// @file:PWindows.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "../include/PWindows.h"

void ShellToUTF8(){
    SetConsoleOutputCP(65001) ;
}

void gotoXY(int x, int y) {
	COORD pos = {x,y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}