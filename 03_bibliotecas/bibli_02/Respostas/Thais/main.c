#include "matrix_utils.h"

int main(){
    int r1, c1, r2, c2;
    int r, c;
    int op;

    scanf("%d %d", &r1, &c1);
    int matrix1[r1][c1];
    matrix_read(r1, c1, matrix1);
    
    scanf("%d %d", &r2, &c2);
    int matrix2[r2][c2];
    matrix_read(r2, c2, matrix2);
  
    while(1){
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\n");

        scanf("%d", &op);
        printf("Opcao escolhida:\n");

        if(op == 6){
            break;
        }
        else if(op == 1){
            int possibleSum;
            possibleSum = possible_matrix_sum(r1, c1, r2, c2);
            if(possibleSum){
                int result[r1][c1];
                matrix_add(r1, c1, matrix1, r2, c2, matrix2, result);
                matrix_print(r1, c1, result);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        }
        else if(op == 2){
            int possibleSub;
            possibleSub = possible_matrix_sub(r1, c1, r2, c2);
            if(possibleSub){
                int result[r1][c1];
                matrix_sub(r1, c1, matrix1, r2, c2, matrix2, result);
                matrix_print(r1, c1, result);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        }
        else if(op == 3){
            int possibleMultiply;
            possibleMultiply = possible_matrix_multiply(c1, r2);
            if(possibleMultiply){
                int result[r1][c2];
                matrix_multiply(r1, c1, matrix1, r2, c2, matrix2, result);
                matrix_print(r1, c2, result);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        }
        else if(op == 4){
            int scalar, choice;
            scanf("%d %d", &scalar, &choice);
            
            if(choice == 1){
                //int result[r1][c1];
                scalar_multiply(r1, c1, matrix1, scalar);
                matrix_print(r1, c1, matrix1);
            }
            else if(choice == 2){
                //int result[r2][c2];
                scalar_multiply(r2, c2, matrix2, scalar);
                matrix_print(r2, c2, matrix2);
            }
        }
        else if(op == 5){
                int result[r1][c1];
                transpose_matrix(r1, c1, matrix1, result);
                matrix_print(r1, c1, result);

                int result2[r2][c2];
                transpose_matrix(r2, c2, matrix2, result2);
                matrix_print(r2, c2, result2);
        }
    }

    //matrix_print(r1, c1, matrix1);
    //matrix_print(r2, c2, matrix2);
}