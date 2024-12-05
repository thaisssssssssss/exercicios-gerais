#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

tLesao leLesao(){
    tLesao lesao;

    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", lesao.id);
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", lesao.diagnostico);
    scanf("%*[^A-Z^a-z]");
    scanf("%[^\n]", lesao.regiao);
    scanf("%d", &lesao.pctgMaligno);

    return lesao;
}

int ehNecessariaCirurgia(tLesao lesao){
    return (lesao.pctgMaligno >= 50);
}

void imprimeLesao(tLesao lesao){
    printf(" %s", lesao.id);
}