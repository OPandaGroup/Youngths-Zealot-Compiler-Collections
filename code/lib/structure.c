#include "../include/structure.h"

//function of stack
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

//function of list
struct list *new_list(){
    struct list *list = (struct list *)malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

void append_list(struct list *list, string data){
    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    node->data = data;
    node->next = NULL;
    node->last = list->tail;
    if(list->len == 0){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }
    list->len++;
    return;
}

void remove_list(struct list *list, int index){
    if(index >= list->len){
        return;
    }else if(index == 0){
        list->head = list->head->next;
        free(list->head->last);
        list->head->last = NULL;
    }else if(index == list->len-1){
        list->tail = list->tail->last;
        free(list->tail->next);
        list->tail->next = NULL;
    }else{
        struct list_node *node = list->head;
        for(int i=0;i<index;i++){
            node = node->next;
        }
        node->last->next = node->next;
        node->next->last = node->last;
        free(node);
    }
    list->len--;
    return;
}

void print_list(struct list *list){
    struct list_node *node = list->head;
    printf("[");
    while (node!=NULL){
        printf("%s,",node->data);
        node = node->next;
    }
    printf("\b]");
}

//function of dirt

dirt *new_dirt(){
    dirt *dirt = (struct dirt *)malloc(sizeof(dirt));
    dirt->len = 0;
    dirt->head = NULL;
    dirt->tail = NULL;
    return dirt;
}

void append_dirt(struct dirt *dirt, string key, string value){
    struct dirt_node *node = (struct dirt_node *)malloc(sizeof(struct dirt_node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    node->last = dirt->tail;
    if(dirt->len == 0){
        dirt->head = node;
        dirt->tail = node;
    }else{
        dirt->tail->next = node;
        dirt->tail = node;
        dirt->len++;
    }
    dirt->len++;
    return;
}

void remove_dirt_key(struct dirt *dirt, string key){
    struct dirt_node *node = dirt->head;
    while(node!=NULL){
        if(strcmp(node->key,key) == 0){
            if(node == dirt->head){
                dirt->head = dirt->head->next;
                free(node);
                node = dirt->head;
            }else if(node == dirt->tail){
                dirt->tail = dirt->tail->last;
                free(node);
                node = dirt->tail;
            }else{
                node->last->next = node->next;
                node->next->last = node->last;
            }
            return;
        }
        node = node->next;
    }
}

bool find_dirt_key(struct dirt *dirt, string key){
    struct dirt_node *node = dirt->head;
    while(node!=NULL){
        if(strcmp(node->key,key) == 0){
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void print_dirt(struct dirt *dirt){
    struct dirt_node *node = dirt->head;
    if (dirt->len == 0 || node == NULL){
        printf(None);
        return ;
    }
    printf("{");
    while (node!=NULL){
        printf("\"%s\":\"%s\",",node->key,node->value);
        node = node->next;
    }
    printf("\b}");
    return ;
}