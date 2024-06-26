// 
// function.h
// time: 2024年6月23日
// Copyright (c) 写代码ing. All rights reserved.
//

#ifndef DATA_H
#define DATA_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef unsigned long long ull;
typedef _Bool bool;
typedef char * string;

//string
_Bool stringcmp(const char *str1, char *str2,_Bool efficiency); //efficiency
ull stringsearch(char *str1, char *str2); 
char *erase(char *str,ull index,ull len);
char *strappend(char *str, char *str2);
char *stringcut(char *str, ull index, ull len);
char *stringcut_(char *str, ull index, ull len);
//Forward_Ergodic和Forward_Icts一样
string Forward_Ergodic(string str, ull index, char stop) ;
string stringFlip(string str);
string insert(string str, ull index, char *str2);
void inserts(string str, ull index, char *str2);
void Flip(string str);
//这里面的无效字符指的是空格,换行符,制表符 默认将保留" ,'中的字符串内容
string Nicts(string str, ull index, char stop) ;//到...字符停止，中间不保留无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 hello    确定起点遍历
string Forward_Nicts(string str, ull index, char stop) ; //到...字符停止，中间不保留无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 ow   确定终点遍历
string Icts(string str, ull index, char stop) ; //到...字符停止，中间保留无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 h ello,world!
string Forward_Icts(string str, ull index, char stop) ; //到...字符停止，中间保留无效字符，倒序 例如 : he llo,wo rld! stop = ',' index = 8 结果为 !dlr ow
bool Nicts_bool(string str, ull index, char stop) ; //到...字符停止，中间不包含无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 false
bool Icts_bool(string str, ull index, char stop) ; //到...字符停止，中间包含无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 true
bool Fowrard_Nicts_bool(string str, ull index, char stop) ; //到...字符停止，中间不包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 true
bool Forward_Icts_bool(string str, ull index, char stop) ; //到...字符停止，中间包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 false
//跟上面类似，只不过可以指定无效字符,默认将保留" ,'中的字符串内容
string Nictsc(string str, char ch[], ull index, char stop) ;//到...字符停止，中间不保留无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 hello    确定起点遍历
string Forward_Nictsc(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不保留无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 ow   确定终点遍历 ; //到...字符停止，中间保留无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 h ello,world! ; //到...字符停止，中间保留无效字符，倒序 例如 : he llo,wo rld! stop = ',' index = 8 结果为 !dlr ow
bool Nictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不包含无效字符 例如 : he llo,world! stop = ',' index = 0 结果为 false
bool Ictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间包含无效字符 例如 : he llo,world! stop = '!' index = 0 结果为 true
bool Fowrard_Nictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间不包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 true
bool Forward_Ictsc_bool(string str, char ch[], ull index, char stop) ; //到...字符停止，中间包含无效字符，倒序 例如 : he llo,world! stop = ',' index = 8 结果为 false
string delchar(string str, char ch); //在字符串中删除指定字符 不包含" ,' 中的任何字符
//data conversion
string intToString(int num);
int stringToInt(string str);
//file 
FILE *openfile(const char *filename, char *mode);
string readfile(FILE *file, ull len);
void closefile(FILE *file);
void writetofile(FILE *file, char *str);
ull fileSize(FILE *file);
#endif