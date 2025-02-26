#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "movel.h"

/**
 * @brief Estrutura representando um Movel.
 */
typedef struct Movel tMovel;

struct Movel{
    char *nome;
};

/**
 * @brief Cria um novo Movel.
 * @param nome O nome do Movel.
 * @return Um ponteiro para o novo Movel.
 */
tMovel *CriaMovel(char *nome){
    tMovel *m = malloc(sizeof(struct Movel));
    if(m == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    m->nome = strdup(nome);
    return m;
}

/**
 * @brief Destroi um Movel.
 * @param m O Movel a ser destruído.
 */
void DestroiMovel(tMovel *m){
    if(m != NULL){
        if(m->nome != NULL) free(m->nome);
        free(m);
    }
}

/**
 * @brief Lê um Movel.
 * @return O Movel lido.
 */
tMovel *LeMovel(){
    char nome[50];
    scanf("%s", nome);
    tMovel *m = CriaMovel(nome);
    return m;
}

/**
 * @brief Imprime o nome do movel.
 * @param m O Movel a ser impresso.
 */
void ImprimeMovel(tMovel *m){
    printf("%s\n", m->nome);
}

