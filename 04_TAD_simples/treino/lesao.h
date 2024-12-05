#ifndef _LESAO_H_
#define _LESAO_H_

#define MAX_CARACTERES 100
#define MAX_LESOES 10

typedef struct{
    char id[MAX_LESOES];
    char diagnostico[MAX_CARACTERES];
    char regiao[MAX_CARACTERES];
    int pctgMaligno;
}   tLesao;

tLesao leLesao();
int ehNecessariaCirurgia(tLesao lesao);
void imprimeLesao(tLesao lesao);

#endif