#include "matrix_utils.h"
#include <stdio.h>

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix MatrixCreate(int rows, int cols){
    tMatrix m;
    m.rows = rows;
    m.cols = cols;
    return m;
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */
tMatrix MatrixRead(tMatrix matrix){
    int r, c;
    for(r = 0; r < matrix.rows; r++){
        for(c = 0; c < matrix.cols; c++){
            scanf("%d", &matrix.data[r][c]);
        }
    }
    return matrix;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix matrix){
    int r, c;
    for(r = 0; r < matrix.rows; r++){
        for(c = 0; c < matrix.cols; c++){
            if(c == 0) printf("|");
            printf("%d", matrix.data[r][c]);
            if(c == matrix.cols - 1) printf("|");
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
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    return (matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows);
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    return (matrix1.cols == matrix2.cols && matrix1.rows == matrix2.rows);
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    return (matrix1.cols == matrix2.rows);
    //acho que as colunas da primeira tem q ser iguais as linhas da segunda e a matriz resultante sai com as linhas da primeira e coluna da segunda
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    result = MatrixCreate(matrix1.rows, matrix1.cols);

    int r, c;
    for(r = 0; r < matrix1.rows; r++){
        for(c = 0; c < matrix1.cols; c++){
            result.data[r][c] = matrix1.data[r][c] + matrix2.data[r][c];
        }
    }
    return result;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    result = MatrixCreate(matrix1.rows, matrix1.cols);

    int r, c;
    for(r = 0; r < matrix1.rows; r++){
        for(c = 0; c < matrix1.cols; c++){
            result.data[r][c] = matrix1.data[r][c] - matrix2.data[r][c];
        }
    }
    return result;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    result = MatrixCreate(matrix1.rows, matrix2.cols);

    int r, c, aux;
    for(r = 0; r < matrix1.rows; r++){
        for(c = 0; c < matrix2.cols; c++){
            result.data[r][c] = 0;
            for(aux = 0; aux < matrix1.cols; aux++){
                result.data[r][c] += matrix1.data[r][aux] * matrix2.data[aux][c];
            }
        }
    }
    return result;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix result;
    result = MatrixCreate(matrix.cols, matrix.rows);
    
    int r, c;
    for(r = 0; r < matrix.rows; r++){
        for(c = 0; c < matrix.cols; c++){
            result.data[c][r] = matrix.data[r][c];
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
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    int r, c;
    for(r = 0; r < matrix.rows; r++){
        for(c = 0; c < matrix.cols; c++){
           matrix.data[r][c] = matrix.data[r][c] * scalar;
        }
    }
    return matrix;
}
