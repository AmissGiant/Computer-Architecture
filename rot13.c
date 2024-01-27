#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){//argc = argument count, argv = pointers to characters
    char *input = argv[1];
    for(int i = 0; input[i] != '\0'; i++){
        char c = input[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            if(c >= 'a' && c <= 'z'){
            c = 'a' + (c - 'a' + 13)% 26;//can use + 13 for chars to do operation
        }else if(c >= 'A' && c <= 'Z'){
            c = 'A' + (c - 'A' + 13)% 26;
        }
        }
        putchar(c);
    }
    putchar('\n');
    return 0;
}