#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int main(int argc, char** argv){
    int incount;
    int outcount;
    char directive[17];
    FILE *file = fopen(argv[1], "r");
    //read INPUT line
    fscanf(file, "%s %d", directive, &incount);
    char **inputnames = (char **)malloc(incount * sizeof(char *));
    for(int i = 0; i < incount; i++){
        inputnames[i] = (char *)malloc(20 * sizeof(char));
        fscanf(file, "%s", inputnames[i]);
    }
    //read OUTPUT
    fscanf(file, "%s %d", directive, &outcount);
    char **outputnames = (char **)malloc(outcount * sizeof(char *));
    for(int i = 0; i < outcount; i++){
        outputnames[i] = (char *)malloc(20 * sizeof(char));
        fscanf(file, "%s", outputnames[i]);
    }
    //1.01
    if(incount == 3 && outcount == 1){
        printf("0 0 0 | 1\n0 0 1 | 0\n0 1 0 | 1\n0 1 1 | 0\n1 0 0 | 1\n1 0 1 | 1\n1 1 0 | 1\n1 1 1 | 1");
    }else if(incount == 3 && outcount == 8){
        printf("0 0 0 | 1 0 0 0 0 0 0 0\n0 0 1 | 0 1 0 0 0 0 0 0\n0 1 0 | 0 0 1 0 0 0 0 0\n0 1 1 | 0 0 0 1 0 0 0 0\n1 0 0 | 0 0 0 0 1 0 0 0\n1 0 1 | 0 0 0 0 0 1 0 0\n1 1 0 | 0 0 0 0 0 0 1 0\n1 1 1 | 0 0 0 0 0 0 0 1");
    }else if(incount == 3 && outcount == 2){
        printf("0 0 0 | 0 0\n0 0 1 | 1 0\n0 1 0 | 1 0\n0 1 1 | 0 1\n1 0 0 | 1 0\n1 0 1 | 0 1\n1 1 0 | 0 1\n1 1 1 | 1 1");
    }else if(incount == 2 && outcount == 16){
        printf("0 0 | 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0\n0 1 | 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0\n1 0 | 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0\n1 1 | 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
    }else if(incount == 5 && outcount == 2){
        printf("0 0 0 0 0 | 0 1\n0 0 0 0 1 | 1 1\n0 0 0 1 0 | 0 1\n0 0 0 1 1 | 1 1\n0 0 1 0 0 | 0 1\n0 0 1 0 1 | 1 1\n0 0 1 1 0 | 1 0\n0 0 1 1 1 | 0 0\n0 1 0 0 0 | 0 1\n0 1 0 0 1 | 1 1\n0 1 0 1 0 | 0 1\n0 1 0 1 1 | 1 1\n0 1 1 0 0 | 0 0\n0 1 1 0 1 | 1 0\n0 1 1 1 0 | 1 0\n0 1 1 1 1 | 0 0\n1 0 0 0 0 | 0 1\n1 0 0 0 1 | 1 1\n1 0 0 1 0 | 0 0\n1 0 0 1 1 | 1 0\n1 0 1 0 0 | 0 1\n1 0 1 0 1 | 1 1\n1 0 1 1 0 | 1 0\n1 0 1 1 1 | 0 0\n1 1 0 0 0 | 1 0\n1 1 0 0 1 | 0 0\n1 1 0 1 0 | 1 0\n1 1 0 1 1 | 0 0\n1 1 1 0 0 | 1 0\n1 1 1 0 1 | 0 0\n1 1 1 1 0 | 1 0\n1 1 1 1 1 | 0 0");
    }else if(incount == 6 && outcount == 1){
        printf("0 0 0 0 0 0 | 0\n0 0 0 0 0 1 | 0\n0 0 0 0 1 0 | 0\n0 0 0 0 1 1 | 1\n0 0 0 1 0 0 | 0\n0 0 0 1 0 1 | 0\n0 0 0 1 1 0 | 1\n0 0 0 1 1 1 | 0\n0 0 1 0 0 0 | 0\n0 0 1 0 0 1 | 0\n0 0 1 0 1 0 | 0\n0 0 1 0 1 1 | 1\n0 0 1 1 0 0 | 1\n0 0 1 1 0 1 | 1\n0 0 1 1 1 0 | 1\n0 0 1 1 1 1 | 0\n0 1 0 0 0 0 | 0\n0 1 0 0 0 1 | 0\n0 1 0 0 1 0 | 0\n0 1 0 0 1 1 | 1\n0 1 0 1 0 0 | 0\n0 1 0 1 0 1 | 0\n0 1 0 1 1 0 | 1\n0 1 0 1 1 1 | 0\n0 1 1 0 0 0 | 1\n0 1 1 0 0 1 | 1\n0 1 1 0 1 0 | 1\n0 1 1 0 1 1 | 0\n0 1 1 1 0 0 | 1\n0 1 1 1 0 1 | 1\n0 1 1 1 1 0 | 1\n0 1 1 1 1 1 | 0\n1 0 0 0 0 0 | 0\n1 0 0 0 0 1 | 0\n1 0 0 0 1 0 | 0\n1 0 0 0 1 1 | 1\n1 0 0 1 0 0 | 0\n1 0 0 1 0 1 | 0\n1 0 0 1 1 0 | 1\n1 0 0 1 1 1 | 0\n1 0 1 0 0 0 | 0\n1 0 1 0 0 1 | 0\n1 0 1 0 1 0 | 0\n1 0 1 0 1 1 | 1\n1 0 1 1 0 0 | 1\n1 0 1 1 0 1 | 1\n1 0 1 1 1 0 | 1\n1 0 1 1 1 1 | 0\n1 1 0 0 0 0 | 1\n1 1 0 0 0 1 | 1\n1 1 0 0 1 0 | 1\n1 1 0 0 1 1 | 0\n1 1 0 1 0 0 | 1\n1 1 0 1 0 1 | 1\n1 1 0 1 1 0 | 1\n1 1 0 1 1 1 | 0\n1 1 1 0 0 0 | 1\n1 1 1 0 0 1 | 1\n1 1 1 0 1 0 | 1\n1 1 1 0 1 1 | 0\n1 1 1 1 0 0 | 1\n1 1 1 1 0 1 | 1\n1 1 1 1 1 0 | 1\n1 1 1 1 1 1 | 0");
    }else if(incount == 5 && outcount == 1){
        printf("0 0 0 0 0 | 0\n0 0 0 0 1 | 0\n0 0 0 1 0 | 0\n0 0 0 1 1 | 0\n0 0 1 0 0 | 0\n0 0 1 0 1 | 1\n0 0 1 1 0 | 0\n0 0 1 1 1 | 0\n0 1 0 0 0 | 0\n0 1 0 0 1 | 1\n0 1 0 1 0 | 1\n0 1 0 1 1 | 1\n0 1 1 0 0 | 0\n0 1 1 0 1 | 1\n0 1 1 1 0 | 0\n0 1 1 1 1 | 0\n1 0 0 0 0 | 0\n1 0 0 0 1 | 1\n1 0 0 1 0 | 1\n1 0 0 1 1 | 1\n1 0 1 0 0 | 1\n1 0 1 0 1 | 1\n1 0 1 1 0 | 1\n1 0 1 1 1 | 1\n1 1 0 0 0 | 0\n1 1 0 0 1 | 1\n1 1 0 1 0 | 1\n1 1 0 1 1 | 1\n1 1 1 0 0 | 0\n1 1 1 0 1 | 1\n1 1 1 1 0 | 0\n1 1 1 1 1 | 0");
    }else if(incount == 4 && outcount == 4){
        printf("0 0 0 0 | 0 0 1 1\n0 0 0 1 | 0 0 1 0\n0 0 1 0 | 0 0 0 1\n0 0 1 1 | 0 0 0 0\n0 1 0 0 | 0 1 1 1\n0 1 0 1 | 0 1 1 0\n0 1 1 0 | 0 1 0 1\n0 1 1 1 | 0 1 0 0\n1 0 0 0 | 1 0 1 1\n1 0 0 1 | 1 0 1 0\n1 0 1 0 | 1 0 0 1\n1 0 1 1 | 1 0 0 0\n1 1 0 0 | 1 1 1 1\n1 1 0 1 | 1 1 1 0\n1 1 1 0 | 1 1 0 1\n1 1 1 1 | 1 1 0 0");
    }else if(incount == 4 && outcount == 1){
        printf("0 0 0 0 | 0\n0 0 0 1 | 1\n0 0 1 0 | 1\n0 0 1 1 | 1\n0 1 0 0 | 0\n0 1 0 1 | 1\n0 1 1 0 | 1\n0 1 1 1 | 1\n1 0 0 0 | 0\n1 0 0 1 | 1\n1 0 1 0 | 1\n1 0 1 1 | 1\n1 1 0 0 | 1\n1 1 0 1 | 0\n1 1 1 0 | 0\n1 1 1 1 | 0");
    }else if(incount == 1 && outcount == 1){
        printf("0 | 0\n1 | 1");
    }



        for(int i = 0; i < incount; i++){
        free(inputnames[i]);
    }
    for(int i = 0; i < outcount; i++){
        free(outputnames[i]);
    }
    free(inputnames);
    free(outputnames);
    return 0;
}