#include <stdio.h>
#include <stdlib.h>
void matrixMultiplier(int **M, int k, int n){
    if(n == 0){
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(i == j){
                    M[i][j] = 1;
                }else{
                    M[i][j] = 0;
                }
            }
        }
    }else if(n > 1){
        int **temp = (int **)malloc(k * sizeof(int *));
        for(int i = 0; i < k; i++){
            temp[i] = (int *)malloc(k * sizeof(int));//get space for temp
        }
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                temp[i][j] = M[i][j];
            }
        }
        for(int p = 2; p <= n; p++){
            int **result = (int **)malloc(k * sizeof(int *));
            for(int i = 0; i < k; i++){
                result[i] = (int *)malloc(k * sizeof(int));//get space for result
            }
            for(int i = 0; i < k; i++){
                for(int j = 0; j < k; j++){
                    result[i][j] = 0;
                    for(int x = 0; x < k; x++){
                        result[i][j] += temp[i][x] * M[x][j];
                    }
                }
            }
            for(int i = 0; i < k; i++){
                for(int j = 0; j < k; j++){
                    temp[i][j] = result[i][j];//making temp array into the result array
                }
            }
            for(int i = 0; i < k; i++){
                free(result[i]);
            }
            free(result);//no longer need result
        }
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                M[i][j] = temp[i][j];
            }
        }
        for(int i = 0; i < k; i++){
            free(temp[i]);
        }
        free(temp);//no longer need temp
    }
}
int main(int argc, char *argv[]){
    FILE *file = fopen(argv[1], "r");//read from input file
    int k = 0;
    fscanf(file, "%d", &k);//%d for an integer
    int **matrix = (int **)malloc(k * sizeof(int *));
    for(int i = 0; i < k; i++){
        matrix[i] = (int *)malloc(k * sizeof(int));
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            fscanf(file, "%d", &matrix[i][j]);//create a matrix from input file
        }
    }
    int n;
    fscanf(file, "%d", &n);
    fclose(file);
    matrixMultiplier(matrix, k, n);//tried to do it all under main, easier to do it with helper funtion
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            printf("%d", matrix[i][j]);
            if(j < k - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i = 0; i < k; i++){//have to free the data from malloc
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
/*void printMatrix(double **matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}*/
void Invert(double **TrainMatrix, double **Identity, int n){
    double **TempMatrix = (double **)malloc(n * sizeof(double *));
    for(int i = 0; i < n; i++){
        TempMatrix[i] = (double *)malloc(n * sizeof(double));
        for(int j = 0; j < n; j++){
            TempMatrix[i][j] = TrainMatrix[i][j];
        }
    }
    for(int p = 0; p < n; p++){
        double f = TempMatrix[p][p];
        for(int j = 0; j < n; j++){
            TempMatrix[p][j] /= f;
            Identity[p][j] /= f;
        }
        for(int i = 0; i < n; i++){
            if(i != p){
                f = TempMatrix[i][p];
                for(int j = 0; j < n; j++){
                    TempMatrix[i][j] -= TempMatrix[p][j] * f;
                    Identity[i][j] -= Identity[p][j] * f;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        free(TempMatrix[i]);
    }
    free(TempMatrix);
}

void Transpose(double **original, double **transpose, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            transpose[j][i] = original[i][j];
        }
    }
}

void Multiply(double **result, double **matrix1, double **matrix2, int rows1, int cols1, int cols2){
    for(int i = 0; i < rows1; i ++){
        for(int j = 0; j < cols2; j++){
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    } 
}
int main(int argc, char *argv[]){
    //read from files stuff starts here
    int rows, cols, datarows, datacols;
    FILE *trainfile = fopen(argv[1], "r");
    char trainy[6];
    fscanf(trainfile, "%5s", trainy);
    fscanf(trainfile, "%d", &cols);
    fscanf(trainfile, "%d", &rows);
    cols++;
    double **TrainMatrix = (double **)malloc(rows * sizeof(double *));
    double **y = (double **)malloc(rows * sizeof(double *));
    for(int i = 0; i < rows; i++){
        TrainMatrix[i] = (double *)malloc((cols) * sizeof(double));
        y[i] = (double *)malloc(sizeof(double));
        TrainMatrix[i][0] = 1.0;
        for(int j = 1; j <= cols; j++){
            if(j == cols){
                fscanf(trainfile, "%lf", &y[i][0]);
            }else{
                fscanf(trainfile, "%lf", &TrainMatrix[i][j]);
            }
        }
    }
    fclose(trainfile);
    FILE *datafile = fopen(argv[2], "r");
    fscanf(datafile, "%5s", trainy);
    fscanf(datafile, "%d", &datacols);
    datacols++;
    fscanf(datafile, "%d", &datarows);
    double **DataMatrix = (double **)malloc(datarows * sizeof(double *));
    for(int i = 0; i < datarows; i++){
        DataMatrix[i] = (double *)malloc((datacols) * sizeof(double));
        DataMatrix[i][0] = 1.0;
        for(int j = 1; j < datacols; j++){
            fscanf(datafile, "%lf", &DataMatrix[i][j]);
        }
    }
    fclose(datafile);
    //read from files stuff ends here

    //multiply stuff starts here
    double **result = (double **)malloc(rows * sizeof(double *));
    for(int i = 0; i < rows; i++){
        result[i] = (double *)malloc(cols * sizeof(double));
    }
    //multiply stuff ends here

    //transpose stuff starts here
    double **TransposedTrain = (double **)malloc(cols * sizeof(double *));
    for(int i = 0; i < cols; i++){
        TransposedTrain[i] = (double *)malloc(rows * sizeof(double));
    }
    //transpose stuff ends here

    //inverse stuff starts here
    double **InverseTrain = (double **)malloc(rows * sizeof(double *));
    for(int i = 0; i < rows; i++){
        InverseTrain[i] = (double *)malloc(cols * sizeof(double));
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            InverseTrain[i][j] = TrainMatrix[i][j]; 
        }
    }
    double **Identity = (double **)malloc(cols * sizeof(double *));
    for(int i = 0; i < cols; i++){
        Identity[i] = (double *)malloc(cols * sizeof(double));
        for(int j = 0; j < cols; j++){
            if(i == j){
                Identity[i][j] = 1.0;
            }else{
                Identity[i][j] = 0.0;
            }
        }
    }
    //inverse stuff ends here

    //grand finale begins here
        //step 1
    double **XT = (double **)malloc(cols * sizeof(double *));
    for(int i = 0; i < cols; i++){
        XT[i] = (double *)malloc(rows * sizeof(double));
    }
    Transpose(TrainMatrix, XT, rows, cols);
    
        //step 2
    double **XTX = (double **)malloc(cols * sizeof(double *));
    for(int i = 0; i < cols; i++){
        XTX[i] = (double *)malloc(cols * sizeof(double));
    }
    Multiply(XTX, XT, TrainMatrix, cols, rows, cols);

        //step 3
    Invert(XTX, Identity, cols);

        //step 4/5
    double **XTXXT = (double **)malloc(cols * sizeof(double *));
    for(int i = 0; i < cols; i++){
        XTXXT[i] = (double *)malloc(cols * sizeof(double));
    }
    Multiply(XTXXT, Identity, XT, cols, cols, rows);
    
        //step 6
    double **W = (double **)malloc(cols * sizeof(double *));
    for(int i = 0; i < cols; i++){
        W[i] = (double *)malloc(1 * sizeof(double));
    }
    Multiply(W, XTXXT, y, cols, rows, 1);
    
        //step 7 AKA grand finale finale
    double **Finale = (double **)malloc(rows * sizeof(double *));
    for(int i = 0; i < rows; i++){
        Finale[i] = (double *)malloc(1 * sizeof(double));
    }
    Multiply(Finale, DataMatrix, W, rows, cols, 1);
    for(int i = 0; i < rows; i++){
        printf("%.0f\n", Finale[i][0]);
    }

    //grand finale ends here

    for(int i = 0; i < rows; i++){
        free(DataMatrix[i]);
        free(TrainMatrix[i]);
        free(y[i]);
        free(result[i]);
        free(Finale[i]);
    }
    free(result);
    free(DataMatrix);
    free(TrainMatrix);
    free(y);
    free(Finale);
    for(int i = 0; i < cols; i++){
        free(TransposedTrain[i]);
        free(InverseTrain[i]);
        free(Identity[i]);
        free(XT[i]);
        free(XTX[i]);
        free(XTXXT[i]);
        free(W[i]);
    }
    free(TransposedTrain);
    free(InverseTrain);
    free(Identity);
    free(XT);
    free(XTX);
    free(XTXXT);
    free(W);
    return 0;
}