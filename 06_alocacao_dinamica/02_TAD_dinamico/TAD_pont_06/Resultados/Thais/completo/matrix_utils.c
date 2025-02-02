#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

// #define MAX_MATRIX_SIZE 10

// typedef struct Matrix{
//     int rows;
//     int cols;
//     int **data;
// } tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado. Alocar dinamicamente o espaço na memória para a matriz bidimensional
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix* MatrixCreate(int rows, int cols){
    tMatrix *matrix = (tMatrix*)malloc(sizeof(tMatrix));
    matrix->cols = cols;
    matrix->rows = rows;
    if(matrix == NULL) exit(EXIT_FAILURE);
    matrix->data = (int**)malloc(rows * sizeof(int*));
    int i;
    for(i = 0; i < rows; i++){
        matrix->data[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

/**
 * @brief Libera toda a memória alocada por uma matriz
 * @param matrix O ponteiro para a estrutura que armazena uma matriz.
 */
void MatrixFree(tMatrix* matrix){
    if(matrix != NULL){
        int i, j;
        for(i = 0; i < matrix->rows; i++){
            free(matrix->data[i]);
        }
        free(matrix->data);
        free(matrix);
    }
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 */
void MatrixRead(tMatrix* matrix){
    int i, j;
    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix* matrix){
    int i, j;
    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            if(j == 0) printf("|");
            printf("%d", matrix->data[i][j]);
            if(j == matrix->cols - 1) printf("|");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix* matrix1, tMatrix* matrix2){
    return (matrix1->rows == matrix2->rows && matrix1->cols == matrix2->cols);
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    return (matrix1->rows == matrix2->rows && matrix1->cols == matrix2->cols);
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    return (matrix1->cols == matrix2->rows);
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix* MatrixAdd(tMatrix* matrix1, tMatrix* matrix2){
    if(PossibleMatrixSum(matrix1, matrix2)){
        tMatrix *result = MatrixCreate(matrix1->rows, matrix1->cols);
        int i, j;
        for(i = 0; i < matrix1->rows; i++){
            for(j = 0; j < matrix1->cols; j++){
                result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
            }
        }
        return result;
    }
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix* MatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    if(PossibleMatrixSub(matrix1, matrix2)){
        tMatrix *result = MatrixCreate(matrix1->rows, matrix1->cols);
        int i, j;
        for(i = 0; i < matrix1->rows; i++){
            for(j = 0; j < matrix1->cols; j++){
                result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
            }
        }
        return result;
    }
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    if(PossibleMatrixMultiply(matrix1, matrix2)){
        tMatrix *result = MatrixCreate(matrix1->rows, matrix2->cols);
        int i, j, k;
        for(i = 0; i < matrix1->rows; i++){
            for(j = 0; j < matrix2->cols; j++){
                result->data[i][j] = 0;
                for(k = 0; k < matrix1->cols; k++){
                    result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
                }
            }
        }
        return result;
    }
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix* TransposeMatrix(tMatrix* matrix){
    tMatrix *result = MatrixCreate(matrix->cols, matrix->rows);
    int i, j;
    for(i = 0; i < matrix->cols; i++){
        for(j = 0; j < matrix->rows; j++){
            result->data[i][j] = matrix->data[j][i];
        }
    }
    return result;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar){
    tMatrix *result = MatrixCreate(matrix->rows, matrix->cols);
    int i, j;
    for(i = 0; i < matrix->rows; i++){
        for(j = 0; j < matrix->cols; j++){
            result->data[i][j] = matrix->data[i][j] * scalar;
        }
    }
    return result;
}


// int main(){
//     tMatrix *matrix = MatrixCreate(2,2);
//     MatrixRead(matrix);
//     MatrixPrint(matrix);
//     matrix = MatrixMultiplyByScalar(matrix, 3);
//     MatrixPrint(matrix);
//     MatrixFree(matrix);
// }