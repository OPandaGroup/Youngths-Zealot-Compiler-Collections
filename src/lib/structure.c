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
    node->more_data = NULL;
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
    node->add_len = 0;
    stack->len++;
    return ;
}

void push_stack_(struct stack *stack, string data, void *more_data){
    push_stack(stack, more_data);
    return ;
}

void add_stack_data(struct stack *stack, void *data){
    if(stack->len == 0){
        return;
    }else if(stack->len == 1){
        stack->top->more_data = data;
    }else{
        struct stack_node *node = stack->end;
        node->more_data = data;
    }
}


void pop_stack(struct stack *stack){
    if(stack->len == 0){
        return;
    }else if(stack->len == 1){
        free(stack->top);
        stack->top = NULL;
        stack->end = NULL;
    }else{
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

struct stack_node *get_stack_top(struct stack *stack){
    return stack->end;
}

//function of list
struct list *new_list(){
    struct list *list = (struct list *)malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

list *split(string str, char delimiter){
    Debug("Split") ;
    int i = 0, j = 0, start = 0; // i是游标,j是记录位置,idx是记录string的遍历位置
    list *ls = new_list();       // 创建一个list
    Debug("Split") ;
    str = Replace(str, delimiter, ',');
    Debug("Replace") ;
    str = strappend(str, ",");
    bool is_str = 0, is_str_dm = 0;
    while (str[i] != '\0'){
        if(str[i] == '\"' && is_str == 0){
            is_str = !is_str;
        }else if(str[i] == '\'' && is_str_dm == 0){
            is_str_dm = !is_str_dm;
        }else if(str[i] == delimiter){
            string tmp = stringcut(str, start, i - start);
            append_list(ls, tmp);
            start = i + 1;
        }
        i++;
    }
    return ls;
}

struct list_node *get_list_node(struct list *list, int index){
    if(index >= list->len){
        return NULL;
    }else{
        struct list_node *node = list->head;
        for(int i=0;i<index;i++){
            node = node->next;
        }
        return node;
    }
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

//function of tree
struct tree *new_tree(string data, string key, struct tree *parent){
    struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
    tree->child_num = 0;
    tree->data = data;
    tree->child = malloc(sizeof(struct tree *)*1);
    tree->add_data = malloc(sizeof(void *)*1);
    tree->parent = parent;
    tree->more = NULL;
    tree->data_num = 0;
    tree->key = key;
    return tree;
}

void append_tree(struct tree *tree, string data, string key){
    tree->child_num++;
    tree->child = realloc(tree->child,sizeof(struct tree *)*tree->child_num);
    tree->child[tree->child_num-1] = new_tree(data, key, tree);
}

void print_tree(struct tree *tree, int level){
    printf("%s",tree->key);
    for(int i = 0 ; i < tree->child_num ; i++){
        printf("\n");
        for(int j = 0 ; j < level ; j++){
            printf("   ");
        }
        printf("└──");
        print_tree(tree->child[i], level+1);
    }
}

void add_tree_data(struct tree *tree, void *data){
    tree->data_num++;
    tree->add_data = realloc(tree->add_data,sizeof(void *)*tree->data_num);
    tree->add_data[tree->data_num-1] = data;
}

void append_more_data(struct tree *tree, string key, string data){
    dirt *dirt = tree->more;
    if(stringcmp(key, "$data", 1)){
        printf("Error: key is $data\n");
        return ;
    }
    if(dirt == NULL){
        tree->more = new_dirt();
        append_dirt(tree->more,key,data);
    }else{
        append_dirt(dirt,key,data);
    }
    return ;
}

string get_tree_dirt(struct tree *tree, bool child){
    if(child){
        string str = "\0";
        str = strappend(str,"$data");
        str = strappend(str,"=\"");
        str = strappend(str,tree->data);
        str = strappend(str,"\"");
        if(tree->more == NULL)  return str;
        if(tree->more->len == 0){
            return str;
        }else{
            str = strappend(str, " ");
            for(int i = 0; i < tree->more->len ; i++){
                str = strappend(str,tree->more->head->key);
                str = strappend(str,"=\"");
                str = strappend(str,tree->more->head->value);
                str = strappend(str, "\" ");
            }
            str = strappend(str,"\b");
            return str;
        }
    }else{
        string str = "\0";
        if(tree->more == NULL){
            return str ;
        }else if(tree->more->len == 0){
            return str;
        }else{
            str = strappend(str, " ");
            for(int i = 0; i < tree->more->len ; i++){
                str = strappend(str,tree->more->head->key);
                str = strappend(str,"=\"");
                str = strappend(str,tree->more->head->value);
                str = strappend(str, "\" ");
            }
            return str;
        }     
    }
}

string get_tree_XML(struct tree *tree, int level){
    if(tree == NULL)    return None;
    string str = "\0";
    for (int i = 0; i < level; i++){
        str = strappend(str, "\t");
    }
    if(tree->child_num == 0){
        str = strappend(str, strappend("<", strappend(tree->key, strappend(get_tree_dirt(tree, 0), "> "))));
        str = strappend(str, tree->data);
        str = strappend(str, strappend("</", strappend(tree->key, ">\n")));
    }else{
        str = strappend(str, strappend("<", strappend(strappend(tree->key, strappend(" ", get_tree_dirt(tree, 1))), ">\n")));
        for(int i = 0; i < tree->child_num; i++)    str = strappend(str, get_tree_XML(tree->child[i], level+1));
        str = strappend(str, strappend("</", strappend(tree->key, ">\n")));
    }
    return str;
}

tree *get_child(struct tree *tree, int index){
    if(index >= tree->child_num){
        return NULL;
    }else{
        return tree->child[index];
    }
}

void dc(string str, char ch){
    string data = malloc(sizeof(char)*strlen(str)); memset(data, 0, strlen(str));
    for (size_t i = 0; i < strlen(str); i++){
        if(str[i] == ch){
            continue;
        }else{
            data[strlen(data)] = str[i];
        }
    }
    data = strappend(data, "\0");
    str = data;
}

dirt *get_treeMoreData(string str){ //但是好像一堆bug，就当个测试版
    string data = malloc(sizeof(char)*strlen(str)); memset(data, 0, strlen(str));
    bool is_str = 0, is_str_dm = 0;
    data[strlen(data)] = str[0]; //强制加上第一个字符,这样避免在for中的特殊判断 
    for (size_t i = 1; i < strlen(str); i++){
        if(str[i] == ' ' && !is_str && !is_str_dm){
            if(str[i-1] == '\'' || str[i-1] == '\"')
                data[strlen(data)] = ',';
            else
                continue;
        }else if(str[i] == '\"' && !is_str){
            is_str_dm = !is_str_dm;
        }else if(str[i] == '\'' && !is_str_dm){
            is_str = !is_str;
        }
        data[strlen(data)] = str[i];
        putchar(str[i]);
    }
    data[strlen(data)-1] = '\0';
    data = delchar(data, ' ');
    list *list = split(data, ',');
    Debug("split\n");
    dirt *Adirt = new_dirt();print_list(list);
    printf("\n");
    for (size_t i = 0; i < list->len; i++){
        string key = Icts(get_list_node(list, i)->data, 0, '=');
        string value = Icts(get_list_node(list, i)->data, strlen(key)+1, '\0');
        value = delchar(value, '\"');delchar(value, '\'');
        append_dirt(Adirt, key, value);
    }
    print_dirt(Adirt);
    return Adirt;
}

tree *get_tree_from_XML(string XML){
    ull start = -1;
    int len = 1;
    char **strs = malloc(sizeof(char *)*len);
    dirt *dirt_data = new_dirt();
    //第一次预处理
    for (ull i = 0; i < strlen(XML); i++){
        switch (XML[i]){
        case '<':
            start = i;
            break;
        case '>':
            if(start != -1){
                strs[len-1] = stringcut_(XML, start, i);
                strs = realloc(strs, sizeof(char *)*++len);
                // printf("%s\n", strs[len-1]);
                // append_dirt(dirt_data, intToString(i), strs[len-1]);
            }else{
                printf("XML error: xml syntax error");
                return NULL;
            }
            start = -1;
            break;
        default:
            break;
        }
    }
    // print_dirt(dirt_data);
    //第二次预处理 完成对无效字符和字符串的过滤
    dirt *dirts = new_dirt(); //处理更多数据
    for(int i = 0;i < len - 1; i++){
        strs[i] = delchar(delchar(strs[i], '<'), '>');//过滤括号
        for (int j = 0; j < strlen(strs[i]); j++){
            if(strs[i][j] == ' ' || (strs[i][j] == '/' && j != 0)){
                string cut = strappend(stringcut_(strs[i], j, strlen(strs[i])-1), "\0") ;
                append_dirt(dirts, intToString(i), Icts(cut, 0, '\0'));
                strs[i] = stringcut_(strs[i], 0, j); 
                break;
            }
        }
        strs[i] = delchar(strs[i], ' '); 
    }
    // print_dirt(dirts);
    // print_dirt(get_dirt_string_tree("$data=\"hello\""));
    //完成正式处理
    if(len == 1){printf("XML error: xml is None"); return NULL;}
    tree *trees = new_tree(None, strs[0], NULL);
    stack *st = new_stack(); 
    push_stack(st, strs[0]);
    get_stack_top(st)->more_data = trees;
    bool is_del = false;
    for(int i = 1; i < len - 1; i++){
        if(strs[i][0] == '/'){
            is_del = true;
            strs[i] = delchar(strs[i], '/');
        }
        if(stringcmp(get_stack_top(st)->data, strs[i], 1) && is_del){
            pop_stack(st);
        }else{
            tree *parent = get_stack_top(st)->more_data;
            append_tree(st->end->more_data, None, strs[i]);
            push_stack(st, strs[i]);
            get_stack_top(st)->more_data = get_child(parent, parent->child_num - 1);
        }
        is_del = false; 
    }
    if(st->len != 0){printf("XML error: xml syntax error"); return NULL;} 
    print_tree(trees, 0);
    print_dirt(dirts);
    //将树内容完善
    struct dirt_node *dirt_node = dirts->head;
    for(int i = 0; i < dirts->len; i++){
        if(dirt_node == NULL)   break;
        printf("\n%s\n", dirt_node->value);
        get_treeMoreData(strappend(dirt_node->value, "\0"));
    }
    // get_treeMoreData("world = \"world\" world = \"hello\"");
    return trees;
}

//function of resources

resources *new_resources(){
    resources *resources = (struct resources *)malloc(sizeof(resources));
    resources->len = 0;
    resources->data = malloc(sizeof(void *)*1);
    return resources;
}

void append_resources(resources *resources, void *data){
    resources->len++;
    resources->data = realloc(resources->data, sizeof(void *)*resources->len);
    resources->data[resources->len - 1] = data;
    return ;
}

void remove_resources(resources *resources, int index){
    if(index >= resources->len || index < 0){
        printf("resources error: index out of range");
        return ;   
    }else{
        resources->data[index] = NULL;
        return ;
    }
}