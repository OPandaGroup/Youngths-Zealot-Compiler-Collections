//
// @date:2024/07/16
// @file:PDataStructure.h
// @author:Writing 
// @copyright: Panda, 2024
//

#ifndef STUCTURE_H
#define STUCTURE_H

#define None "None"
#define endl printf("\n")
#define Debug(...) printf(__VA_ARGS__)
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../include/PFile.h"
#include "../include/PString.h"
#include "../include/PDebug.h"
#include "../include/Pprint.h"
#include "../include/PSystem.h"
#include "../include/PDataTypeConversion.h"

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
    void *more_data;
    int add_len ;
    struct stack_node *next;
    struct stack_node *last;
};
/*function definition of stack*/
struct stack *Stack();
void push_stack(struct stack *stack, string data);
void add_stack_data(struct stack *stack, void *data); //默认给栈顶添加数据
void pop_stack(struct stack *stack);
void print_stack(struct stack *stack);
struct stack_node *get_stack_top(struct stack *stack);//获得栈顶
/*The following code is the list definition, 
the struct and function definition*/
typedef struct list{
    int len;
    struct list_node *head,*tail;
}list;
struct list_node{
    string data;
    struct list_node *next;
    struct list_node *last;
};
/*function definition of list*/
struct list *List();
struct list *split(string str, char delimiter);
struct list_node *get_list_node(struct list *list, int index);
void append_list(struct list *list, string data);
void append_list_plus(struct list *list, string data) ;//添加数据,主要针对一些特殊字符处理,例如:"", "None", "(null)"就不允许被添加进list
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
    struct dirt_node *next;
    struct dirt_node *last;
};
/*function definition of dirt*/
struct dirt *Dirt();
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
    dirt *more;
    string data;
    string key;
}tree;
/*function definition of tree*/
struct tree *Tree(string data, string key, struct tree *parent);
void append_tree(struct tree *tree, string data, string key);
void print_tree(struct tree *tree, int level);
void add_tree_data(struct tree *tree, void *data);
void append_more_data(struct tree *tree, string key, string data);
string get_tree_XML(struct tree *tree,int level); //Format: xml
tree *get_child(tree *tree, int index);
tree *get_tree_from_XML(string xml);
/*The following code is the resources definition, 
the struct and function definition*/
typedef struct resources{
    int len;
    void **data;
}resources;
resources *Resources();
void append_resources(resources *resources, void *data);
void remove_resources(resources *resources, int index);
void *get_resources(resources *resources, int index);
#endif 