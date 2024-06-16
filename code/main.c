#include <stdio.h>  
#include <stdlib.h>
#include <Windows.h>
#include "./include/function.h"
#include "./include/structure.h"

int main(int argc, char const *argv[]){
    struct tree *tree = new_tree("root",NULL);
    append_tree(tree,"test_");
    append_tree(tree,"test2_");
    append_tree(tree->child[1],"test3_");
    print_tree(tree, 0);
    return 0;
}
