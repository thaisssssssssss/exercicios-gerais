#include "candidato.h"
#include "eleicao.h"
#include "eleitor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    tEleicao eleicao;
    eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    return 0;
}