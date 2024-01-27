#include <stdio.h>
#include <stdlib.h>
int isComplete(int board[9][9]){//determines if it's complete or not
    for(int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            if(board[row][col] == 0){
                return 0;
            }
        }
    }
    return 1;
}
int doExist(int board[9][9], int startr, int startc, int num){//check the numbers
    for(int i = startr; i < startr + 3; i++){
        for(int j = startc; j < startc + 3; j++){
            if(board[i][j] == num){
                return 1;
            }
        }
    }
    return 0;
}
int main(int argc, char *argv[]){
    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        return 1;
    }
    int board[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char ch;
            if(fscanf(file, " %c", &ch) != 1){//space befroe %c is necessary
                fclose(file);
                return 1;
            }
            if(ch =='_'){
                board[i][j] = 0;
            }else if(ch >= '1' && ch <= '9'){
                board[i][j] = ch - '0';
            }else{
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);
    if(isComplete(board)){
       int rowDig[9][10] = {0};
       int colDig[9][10] = {0};
       int subgridDig[3][3][10] = {0};//created to check subgrids
       for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            int num = board[row][col];
            if(num > 0){
                if(rowDig[row][num - 1] || colDig[col][num - 1] || subgridDig[row/3][col/3][num]){
                    printf("incorrect\n");
                    return 0;
                }
                rowDig[row][num - 1] = 1;
                colDig[col][num - 1] = 1;
                subgridDig[row/3][col/3][num] = 1;
            }
            }
       }
       printf("correct\n");
    }else{
    int filled[9][9] = {0};
    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            int num = board[row][col];
                if(num > 0){
                    if(filled[row][col]){
                        printf("unsolvable\n");
                        return 0;
                    }
                    filled[row][col] = 1;
                    for(int i = 0; i < 9; i++){
                        if(i != row && board[i][col] == num){
                            printf("unsolvable\n");
                            return 0;
                        }
                    }
                }
            }
        }
        printf("solvable\n");
    }
return 0;
}