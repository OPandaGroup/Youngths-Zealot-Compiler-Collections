#ifndef STUCTURE_H
#define STUCTURE_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
typedef char * string;
typedef _Bool bool;

//data structure

struct stack{
    int len;
    struct stack_node *top,*end;
};
struct stack_node{
    string data;
    struct stack_node *next;
    struct stack_node *last;
};
//stack fun
struct stack *new_stack();
void push_stack(struct stack *stack, string data);
void pop_stack(struct stack *stack);
void print_stack(struct stack *stack);
#endif