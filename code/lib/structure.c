#include "../include/structure.h"

struct stack *new_stack(){
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->top = NULL;
    stack->end = NULL;
    stack->len = 0;
    return stack;
}

void push_stack(struct stack *stack, string data){
    struct stack_node *node = (struct stack_node *)malloc(sizeof(struct stack_node));
    node->next = NULL;
    node->last = stack->end;
    node->data = data;
    if(stack->len == 0){
        stack->top = node;
        stack->end = node;
    }else{
        stack->end->next = node;
        stack->end = node;
    }
    stack->len++;
}

void pop_stack(struct stack *stack){
    if(stack->len == 0){
        return;
    }else if(stack->len == 1){
        free(stack->top);
        stack->top = NULL;
        stack->end = NULL;
    }else{
        printf("is not 0/1");
        stack->end = stack->end->last;
        free(stack->end->next);
        stack->end->next = NULL;
    }
    stack->len--;
}

void print_stack(struct stack *stack){
    struct stack_node *node = stack->top;
    while (node!=NULL){
        printf("%s",node->data);
        node = node->next;
    }
}
