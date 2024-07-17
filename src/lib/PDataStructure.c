//
// @date:2024/07/16
// @file:PDataStructure.c
// @author:Writing 
// @copyright: Panda, 2024
//
#include "../include/PDataStructure.h"

//function of stack
struct stack *Stack(){
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
struct list *List(){
    struct list *list = (struct list *)malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
    return list;
}

list *split(string str, char delimiter){
    int i = 0, j = 0, start = 0; // i是游标,j是记录位置,idx是记录string的遍历位置
    list *ls = List();       // 创建一个list
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
    if(str[strlen(str)-1] == delimiter) return ls;
    else append_list(ls, stringcut(str, start, i - start));
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

void append_list_plus(struct list *list, string data){
    if((data == NULL) || (strcmp(data,"None")) || (strcmp(data, "\0"))) return; //无效
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
    if(list->len == 0)  return ;
    struct list_node *node = list->head;
    printf("[");
    while (node!=NULL){
        if(node->data != NULL)
            printf("%s,",strappend(node->data, "\0"));
        node = node->next;
    }
    printf("]");
}

//function of dirt

dirt *Dirt(){
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
        putchar('"');print_String(node->key);printf("\":");
        putchar('"');print_String(node->value);printf("\",");
        node = node->next;
    }
    printf("\b}");
    return ;
}

string get_dirtJSON(struct dirt *dirt){
    string json = malloc(10);memset(json,0,10);
    struct dirt_node *node = dirt->head;
    if(dirt->len == 0 || node == NULL){
        return strappend(json,None);
    }
    json = strappend(json,"{\n");
    while (node != NULL){
        json = strappend(json,"\t\"");json = strappend(json,node->key);json = strappend(json,"\":");json = strappend(json,"\"");json = strappend(json,node->value);
        if(node->next != NULL) json = strappend(json,"\",\n");
        else json = strappend(json,"\"\n");
        node = node->next;
    }
    return strappend(json,"}\0");
}

//function of tree
struct tree *Tree(string data, string key, struct tree *parent){
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
    tree->child[tree->child_num-1] = Tree(data, key, tree);
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
        tree->more = Dirt();
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

dirt *get_treeMoreData(string str){ 
    // @bug: 这段代码中有一点bug, 导致处理数据可能会出现故障
    print_String(str);
    endl ;
    bool is_str = false, is_str_dm = false;
    string data = malloc(strlen(str)); memset(data, 0, strlen(str));
    for(ull i = 0; i < strlen(str); i++){
        if(str[i] == ' ' && str[i-1] == ' '){
            if(is_str || is_str_dm) data[strlen(data)] = ' ';
            else continue;
        }else if(str[i] == ' ' && str[i-1] != ' '){
            data[strlen(data)] = ',';
        }else{
            data[strlen(data)] = str[i];
        }
    }
    data[strlen(data)] = '\0';
    print_String(data);
    list *list = split(data, ',');
    dirt *Adirt = Dirt();
    print_list(list);
    free(data) ;
    endl;
    // for (size_t i = 0; i < list->len; i++){
    //     string key = Icts(get_list_node(list, i)->data, 0, '=');
    //     string value = Icts(get_list_node(list, i)->data, strlen(key)+1, '\0');
    //     value = delchar(value, '\"');value = delchar(value, '\'');
    //     append_dirt(Adirt, key, value);
    // }
    // print_DebugFileLine(get_dirtJSON(Adirt), 1);
    // print_dirt(Adirt);
    // free(list); free(data);
    return Adirt;
}

tree *get_tree_from_XML(string XML){
    printf("%s", NULL) ;
    init_DebugFile();_ShellToUTF8();
    ull start = -1;
    int len = 1;
    char **strs = malloc(sizeof(char *)*len);
    putchar('\n');
    dirt *dirts = Dirt(); //处理更多数据
    //第一次预处理
    int idx = 0;
    print_DebugFileLine("switch", 1);
    for (ull i = 0; i < strlen(XML); i++){
        switch (XML[i]){
        case '<':
            start = i;
            break;
        case '>':
            if(start != -1){
                string now = strappend(Nicts(XML, i + 1, '<'), "\0");
                if (now[0] != '\0'){
                    append_dirt(dirts, intToString(idx), now) ;
                    print_String(now);
                    printf("\n");
                }
                string cut = delchar(delchar(stringcut_(XML, start, i), '>'), '<');
                strs[len-1] = cut;
                strs = realloc(strs, sizeof(char *)*++len);
                start = -1;
                if(cut[0] != '/')    idx ++;
            }else{
                printError("Xml处理", "Xml语法错误", strappend(intToString(i), "有一个>但在这之前没有对应的<"));
                return NULL;
            }
            break;
        default:
            break;
        }
    }
    // print_DebugFileLine("for", 1);
    printf("Debug%d", len) ;
    //第二次预处理 完成对无效字符和字符串的过滤
    idx = 0; int markers = dirts->len;
    for(int i = 0;i < len - 1; i++){
        // strs[i] = delchar(delchar(strs[i], '<'), '>');//过滤括号
        for (int j = 0; j < strlen(strs[i]); j++){
            if(strs[i][j] == ' ' || (strs[i][j] == '/' && j != 0)){
                string cut = strappend(stringcut_(strs[i], j, strlen(strs[i])-1), "\0") ;
                append_dirt(dirts, strappend("$", intToString(idx)), Icts(strappend(cut, ">"), 0, '>')); //$这样做是为了跟之前的><中的数据有区别 @writing :别管，这个“ Icts(strappend(cut, ">"), 0, '>')”离谱的操作还能让可信度变高
                strs[i] = stringcut_(strs[i], 0, j); 
                break;
            }
        }
        if (strs[i][0] != '/')  idx ++;
        strs[i] = delchar(strs[i], ' '); 
    }
    if(len == 1){printf("XML error: xml is None"); return NULL;}
    tree *trees = Tree(None, strs[0], NULL);
    stack *st = Stack(); 
    push_stack(st, strs[0]);
    get_stack_top(st)->more_data = trees;
    bool is_del = false;
    for(int i = 1; i < len - 1; i++){
        if(strs[i][0] == '/'){
            is_del = true;
            strs[i] = delchar(strs[i], '/');
        }else{
            is_del = false ;
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
    print_DebugFileLine("end", 1);
    print_tree(trees, 0);
    putchar('\n') ;
    // string json = get_dirtJSON(dirts);
    print_DebugFileLine(get_dirtJSON(dirts), 1) ;
    // get_treeMoreData(" name = 'b' scope = 'local' value = 'a'") ;
    struct dirt_node *node = dirts->head ;
    for(ull i = 1; i < markers; i++){
        node = node->next;
    }
    for(ull i = markers; i < len - 1; i++){
        get_treeMoreData(node->value);
        print_DebugFileLine(node->value, 1);
        printf("\n") ;
        node = node->next;
    }
    return trees;
}

//function of resources

resources *Resources(){
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

void *get_resources(resources *resources, int index){
    if(index >= resources->len || index < 0){
        printf("resources error: index out of range");
        return NULL;
    }else{
        return resources->data[index];
    }
}