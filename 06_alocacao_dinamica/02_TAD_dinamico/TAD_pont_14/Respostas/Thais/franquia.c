#include <stdio.h>
#include "franquia.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 * 
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia(){
    char nome[MAX_NOME];
    char conferencia[6];
    tFranquia f = malloc(sizeof(struct franquia));
    if(f == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    // F BUCKS LESTE
    scanf("%*[^A-Z^a-z]");
    scanf("%s %s", nome, conferencia);
    f->nome = malloc((strlen(nome) + 1)* sizeof(char));
    if(f->nome == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(f->nome, nome);
    f->conferencia = malloc((strlen(conferencia) + 1) * sizeof(char));
    if(f->conferencia == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }
    strcpy(f->conferencia, conferencia);
    f->vit_casa = 0;
    f->vit_fora = 0;
    f->der_casa = 0;
    f->der_fora = 0;
    f->aproveitamento = 0;
    return f;
}

/**
 * @brief Libera a memória alocada para uma franquia.
 * 
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia f){
    if(f != NULL){
        if(f->nome != NULL) free(f->nome);
        if(f->conferencia != NULL) free(f->conferencia);
        free(f);
    }
}

/**
 * @brief Imprime as informações de uma franquia.
 * 
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia f){
    // BUCKS [CL] 2 1 66.67 1 1
    int v, d;
    //float a = 0;
    v = GetVitoriaCasaFranquia(f) + GetVitoriaForaFranquia(f);
    d = GetDerrotaCasaFranquia(f) + GetDerrotaForaFranquia(f);
    f->aproveitamento = v + d;
    if(f->aproveitamento != 0) f->aproveitamento = (float)(v * 100) / f->aproveitamento;
    if(strcmp(f->conferencia, "LESTE") == 0){
        printf("%s [CL] %d %d %.2f %d %d\n", f->nome, v, d, f->aproveitamento, GetVitoriaCasaFranquia(f), GetVitoriaForaFranquia(f));
    }
    else if(strcmp(f->conferencia, "OESTE") == 0){
        printf("%s [CO] %d %d %.2f %d %d\n", f->nome, v, d, f->aproveitamento, GetVitoriaCasaFranquia(f), GetVitoriaForaFranquia(f));
    }
}

/**
 * @brief Retorna o nome da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return char* Retorna o nome da franquia.
 */
char * GetNomeFranquia(tFranquia f){
    return f->nome;
}

/**
 * @brief Retorna a conferência da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return char* Retorna a conferência da franquia.
 */
char * GetConferenciaFranquia(tFranquia f){
    return f->conferencia;
}

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia f){
    f->vit_casa++;
}

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f){
    f->vit_fora++;
}

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f){
    f->der_casa++;
}

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f){
    f->der_fora++;
}

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f){
    return f->vit_casa;
}

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f){
    return f->vit_fora;
}

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f){
    return f->der_casa;
}

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f){
    return f->der_fora;
}