#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>

int main(){

    while(1){
    tJogo jogo;
    int continua = 0;

        jogo = CriaJogo();
        ComecaJogo(jogo);
        continua = ContinuaJogo();

        if(continua == 0) break;
    }

    return 0;
}