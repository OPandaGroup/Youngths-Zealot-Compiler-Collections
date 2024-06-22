// 
// stucture.h
// time: 2024年6月22日
// Copyright (c) 写代码ing. All rights reserved.
//

#ifndef STUCTURE_H
#define STUCTURE_H

#define None "None"
#include <stdio.h>
#include <stdlib.h>
#include "../include/function.h"

typedef unsigned long long ull;
typedef char * string;
typedef _Bool bool;

//data structure
/*The code that follows is the stack definition, 
the struct and function definition*/
typedef struct stack{
    int len;
    struct stack_node *top,*end;
}stack;
struct stack_node{
    string data;
    struct stack_node *next;
    struct stack_node *last;
};
/*function definition of stack*/
struct stack *new_stack();
void push_stack(struct stack *stack, string data);
void pop_stack(struct stack *stack);
void print_stack(struct stack *stack);

/*The following code is the list definition, 
the struct and function definition*/
typedef struct list{
    int len;
    struct list_node *head,*tail;
}list;
struct list_node{
    string data;
    struct stack_node *next;
    struct stack_node *last;
};
/*function definition of list*/
struct list *new_list();
void append_list(struct list *list, string data);
void remove_list(struct list *list, int index);
void print_list(struct list *list);

/*The following code is the dirt definition, 
the struct and function definition*/
typedef struct dirt{
    int len;
    struct dirt_node *head,*tail;
}dirt;
struct dirt_node{
    string key,value;
    struct stack_node *next;
    struct stack_node *last;
};
/*function definition of dirt*/
struct dirt *new_dirt();
void append_dirt(struct dirt *dirt, string key, string value);
void remove_dirt_key(struct dirt *dirt, string key);
bool find_dirt_key(struct dirt *dirt, string key);
void print_dirt(struct dirt *dirt);
/*The following code is the tree definition, 
the struct and function definition*/
typedef struct tree{
    int child_num;
    struct tree *parent;
    struct tree **child;
    void **add_data;
    int data_num;
    string data;
    string key;
}tree;
/*function definition of tree*/
struct tree *new_tree(string data, string key, struct tree *parent);
void append_tree(struct tree *tree, string data, string key);
void print_tree(struct tree *tree, int level);
void add_tree_data(struct tree *tree, void *data);
string get_tree_XML(struct tree *tree,int level); //Format: xml
#endif