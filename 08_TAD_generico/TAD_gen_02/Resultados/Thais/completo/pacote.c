#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
#include <string.h>

typedef struct pacote tPacote;

struct pacote{
    void **vetor;
    int qtd;
    int soma;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote *p = malloc(sizeof(struct pacote));
    int i;

    switch (type)
    {
    case INT:
        p->vetor = malloc(sizeof(int*) * numElem);
        for(i = 0; i < numElem; i++){
            p->vetor[i] = malloc(sizeof(int));
        }
        break;
    
    case CHAR:
        p->vetor = malloc(sizeof(char*) * numElem);
        for(i = 0; i < numElem; i++){
            p->vetor[i] = malloc(sizeof(char));
        }
        break;
    
    default:
        break;
    }
    p->tipo = type;
    p->qtd = numElem;
    p->soma = 0;
    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    int i;
    
    if(pac != NULL){
        if(pac->vetor != NULL){
            for(i = 0; i < pac->qtd; i++){
                if(pac->vetor[i] != NULL) free(pac->vetor[i]);
            }
            free(pac->vetor);
        }
        free(pac);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    printf("\nDigite o conteúdo do vetor/mensagem: \n");
    int i = 0;
    switch (pac->tipo)
    {
    case INT:
        for(i = 0; i < pac->qtd; i++){
            scanf("%d", (int*)pac->vetor[i]);
        }
        break;
    
    case CHAR:
        scanf("%*c");
        for(i = 0; i < pac->qtd; i++){
            scanf("%c", (char*)pac->vetor[i]);
        }
        //pac->vetor[pac->qtd] = '\0';
        break;
    
    default:
        break;
    }
    scanf("%*[^\n]");
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    int i = 0;
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->soma);
    switch (pac->tipo)
    {
    case INT:
        for(i = 0; i < pac->qtd; i++){
            printf("%d ", *(int*)pac->vetor[i]);
        }
        break;
    
    case CHAR:
        for(i = 0; i < pac->qtd; i++){
            printf("%c", *(char*)pac->vetor[i]);
        }
        break;
    
    default:
        break;
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    int i;
    for(i = 0; i < pac->qtd; i++){
        pac->soma += *(int*)pac->vetor[i];
    }
}


