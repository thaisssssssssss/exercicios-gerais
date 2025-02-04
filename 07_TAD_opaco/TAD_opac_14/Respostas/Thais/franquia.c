#include "franquia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura que representa uma franquia.
 * 
 * A estrutura franquia contém informações sobre o nome da franquia, sua conferência e seu desempenho em casa e fora.
 * 
 */
struct franquia{
    char *nome;
    char *conferencia;
    int vCasa;
    int vFora;
    int dCasa;
    int dFora;
};

/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 * 
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia(){
    char nome[MAX_NOME];
    char conferencia[6];
    tFranquia f = malloc(sizeof(tFranquia));
    scanf("%s %s", nome, conferencia);
    f->nome = malloc((strlen(nome) + 1) * sizeof(char));
    f->conferencia = malloc((strlen(conferencia) + 1) * sizeof(char));
    strcpy(f->nome, nome);
    strcpy(f->conferencia, conferencia);
    //printf("(%s %s)\n", f->nome, f->conferencia);
    f->dCasa = 0;
    f->dFora = 0;
    f->vCasa = 0;
    f->vFora = 0;
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
    int v, d;
    v = GetVitoriaCasaFranquia(f) + GetVitoriaForaFranquia(f);
    d = GetDerrotaCasaFranquia(f) + GetDerrotaForaFranquia(f);
    float a = v + d;
    if(a != 0) a = (v * 100) / a;
    if(strcmp(GetConferenciaFranquia(f), "LESTE") == 0) {
        printf("%s [CL] %d %d %.2f %d %d\n", GetNomeFranquia(f), v, d, a, GetVitoriaCasaFranquia(f), GetVitoriaForaFranquia(f));
    }
    else if(strcmp(GetConferenciaFranquia(f), "OESTE") == 0) {
        printf("%s [CO] %d %d %.2f %d %d\n", GetNomeFranquia(f), v, d, a, GetVitoriaCasaFranquia(f), GetVitoriaForaFranquia(f));
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
    f->vCasa++;
}

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f){
    f->vFora++;
}

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f){
    f->dCasa++;
}

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 * 
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f){
    f->dFora++;
}

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f){
    return f->vCasa;
}

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f){
    return f->vFora;
}

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f){
    return f->dCasa;
}

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 * 
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f){
    return f->dFora;
}

