#ifndef _NETWORK_
#define _NETWORK_

#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
/*
copyright (c) Writing
modification time :2024-06-28
*/
// 网络通信
void link_init() ;
void link_to_ip() ;
void link_close() ;

#endif