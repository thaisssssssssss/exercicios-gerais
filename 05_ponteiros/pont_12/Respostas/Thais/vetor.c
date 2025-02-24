#include <stdio.h>

#define TAMANHO_MAXIMO 10

/**
 * @brief Ponteiro para função que recebe dois inteiros e realiza uma operação matemática.
 * 
 * return int Resultado da operação matemática.
*/
typedef int (*Operation)(int, int);

typedef struct vetor {
    int elementos[TAMANHO_MAXIMO];
    int tamanhoUtilizado;
} Vetor;


// int add(int n1, int n2){
//     return n1 + n2;
// }

// int mult(int n1, int n2){
//     if(n1 == 0) n1 = 1;
//     return n1 * n2;
// }

/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor){
    scanf("%d", &vetor->tamanhoUtilizado);
    int i;
    for(i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d", &vetor->elementos[i]);
    }
}

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int i, r;
    for(i = 0; i < vetor->tamanhoUtilizado; i++){
        if(i == 0) r = vetor->elementos[i];
        else r = (op)(r, vetor->elementos[i]);
    }
    return r;
}
