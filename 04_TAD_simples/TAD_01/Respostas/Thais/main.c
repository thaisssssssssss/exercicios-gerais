#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>

int main(){
    tJogo jogo;
    int continua = 0;

    while(1){
        ComecaJogo(jogo);
        continua = ContinuaJogo();

        if(continua == 0) break;
    }

    return 0;
}