//
// @date:2024/07/16
// @file:PDebug.h
// @author:Writing 
// @copyright: Panda, 2024
//
#include <stdio.h>
#include <stdlib.h>
#include "../include/PString.h"
#include "../include/PColor.h"
#include "../include/PFile.h"

void PDebug(string message) ;
void PDebugLine(string message, _Bool newline) ;
void init_DebugFile();
void print_DebugFile(string message);
void print_DebugFileLine(string message, _Bool newline);
void print_String(string message);