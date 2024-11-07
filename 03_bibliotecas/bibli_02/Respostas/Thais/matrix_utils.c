#include "matrix_utils.h"

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int r, c;
    for(r = 0; r < rows; r++){
        for(c = 0; c < cols; c++){
            scanf("%d", &matrix[r][c]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int l, c;
    for(l = 0; l < rows; l++){
        for(c = 0; c < cols; c++){
            printf("%d ", matrix[l][c]);
        }
        printf("\n");
    }
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    return (rows1 == rows2 && cols1 == cols2);
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    return (rows1 == rows2 && cols1 == cols2);
}

int possible_matrix_multiply(int cols1, int rows2){
    return (cols1 == rows2);
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int r, c;
    for(r = 0; r < rows1; r++){
        for(c = 0; c < cols1; c++){
            result[r][c] = matrix1[r][c] + matrix2[r][c];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int r, c;
    for(r = 0; r < rows1; r++){
        for(c = 0; c < cols1; c++){
            result[r][c] = matrix1[r][c] - matrix2[r][c];
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){
    int r, c, aux;
    for(r = 0; r < rows1; r++){
        for(c = 0; c < cols2; c++){
            result[r][c] = 0;
            for(aux = 0; aux < rows2; aux++){
                result[r][c] += (matrix1[r][aux] * matrix2[aux][c]);
            }
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){
    int r, c;
    for(r = 0; r < rows; r++){
        for(c = 0; c < cols; c++){
            //muda a propria matriz, se der erro rever aqui
            matrix[r][c] = matrix[r][c] * scalar;
        }
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
    int r, c;
    for(r = 0; r < rows; r++){
        for(c = 0; c < cols; c++){
            result[r][c] = matrix[c][r];
        }
    }
}