#include <stdio.h>
#include <stdlib.h>
#include <string.h> //useful for string problems
int main(int argc, char *argv[]){
    char *lead = NULL;
    int hasspace = 0;
    for(int i = 2; i < argc; i++){
        char *current = argv[i];
        int j = i-1;
        int start = (current[0] == ' ');
        if (start){
            lead = current;
            hasspace = 1;
            continue;
        }
        while(j >= 1){
            char *prev = argv[j];
            while (*current == ' '){
                current++;
            }
            while(*prev == ' '){
                prev++;
            }
            if(prev[0] == ' '){
                char *temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
                j--;
            }else if(strcmp(current, prev) < 0){
                char *temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
                j--;
            }else{
                break;
            }
        }
    }
    if(hasspace){
        printf("%s\n", lead);//%s is for string, %c for chars
    }
    int b = argc;
    for(int i = 1; i < b; i++){
        if(argv[i] != lead){
            printf("%s\n", argv[i]);
        }
    }
    return 0;
}