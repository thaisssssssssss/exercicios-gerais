#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>


tJogada LeJogada(){
    tJogada jogada;
    int sucesso;
        printf("Digite uma posicao (x e y):\n");
        sucesso = scanf("%d %d", &jogada.x, &jogada.y);
        if(sucesso == 2) jogada.sucesso = 1;
        else jogada.sucesso = 0;

    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

//nao sei onde usar
int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}