#include <stdio.h>  
#include <stdlib.h>
#include <Windows.h>
#include "./include/data.h"
#include "./include/structure.h"

int main(int argc, char const *argv[])
{
    struct stack* st = new_stack();
    push_stack(st,"hello1");
    push_stack(st,"hello2");
    pop_stack(st);
    print_stack(st);
    return 0;
}
