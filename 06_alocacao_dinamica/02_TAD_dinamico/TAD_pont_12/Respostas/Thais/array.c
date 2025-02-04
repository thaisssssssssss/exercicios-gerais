#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray(){
    Array *a = malloc(sizeof(Array));
    if(a == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    a->data = NULL;
    a->tamanho = 0;
    return a;
}


/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array){
    if(array != NULL){
        if(array->data != NULL) free(array->data);
        free(array);
    }
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array){
    int i = 0, a;
    char c;
    while(1){
        scanf("%d%c", &a, &c);
        if(i == 0){
            array->data = malloc(sizeof(int));
            array->data[i] = a;
            i++;
        }
        else{
            array->data = realloc(array->data, (i + 1) * sizeof(int));
            array->data[i] = a;
            i++;
        }
        if(c == '.') break;
    }
    array->tamanho = i;
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array){
    int aux, i, j;
    for(i = 0; i < array->tamanho; i++){
        for(j = i; j < array->tamanho; j++){
            if(array->data[i] > array->data[j]){
                aux = array->data[i];
                array->data[i] = array->data[j];
                array->data[j] = aux;
            }
        }
    }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado){
    int i, j, meio;
    OrdenarArray(array);

    //printf("(%d)\n", i);
    // while(1){
    //     meio = array->tamanho / 2;
    //     if(array->tamanho == 1) meio = 0;        
    //     if(array->data[meio] == elementoBuscado){
    //         return meio;
    //     }
    //     else if(array->data[meio] > elementoBuscado){
    //         if(meio == 0) return -1;
    //         array->tamanho = meio;
    //         array->data = realloc(array->data, (array->tamanho) * sizeof(int));
    //     }
    //     // else if(array->data[meio] < elementoBuscado){
    //     //     if(meio == 0) return -1;
    //     //         for(i = meio + 1, j = 0; i < array->tamanho && j < meio; i++, j++){
    //     //             array->data[j] = array->data[i];
    //     //         }
    //     //     array->tamanho = j + 1;
    //     //     array->data = realloc(array->data, (array->tamanho) * sizeof(int));
    //     // }
    //     else if(array->data[meio] < elementoBuscado){
    //         for(i = meio + 1; i < array->tamanho; i++){
    //             array->data[j] = array->data[i];
    //         }
    //     }
    // }
        meio = array->tamanho / 2;
        int inicio = 0;
        while(1){       
            if(array->data[meio + inicio] == elementoBuscado){
                return meio + inicio;
            }
            else if(array->data[meio + inicio] > elementoBuscado){
                if(meio == 0) return -1;
                array->tamanho = meio;
                meio = array->tamanho / 2;
                if(inicio > 0) inicio -= meio;
            }
            else if(array->data[meio + inicio] < elementoBuscado){
                array->tamanho = meio;
                inicio += meio;
                meio = array->tamanho / 2;
                if(meio == 0) inicio++;
            }
    }
}

