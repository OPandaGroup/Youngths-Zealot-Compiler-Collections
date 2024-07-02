#include <stdio.h>
#include <stdlib.h>
#include "./src/include/structure.h"

int main(int argc, char *argv[]){
    string str = "1!,2!,3!,4!,5!,6!,7!,8!,9!,10!";
    language();
    printf("dome在运行");
    list *ls = split(str,',');
    print_list(ls);
    system("pause");
}