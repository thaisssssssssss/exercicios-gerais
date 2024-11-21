#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>


tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[j][i] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}


tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    int i, j;

    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(j == x && i == y){
                if(peca == PECA_1) tabuleiro.posicoes[j][i] = tabuleiro.peca1;
                else tabuleiro.posicoes[j][i] = tabuleiro.peca2;
                printf("Jogada [%d,%d]!\n", x, y);
                ImprimeTabuleiro(tabuleiro);
            }
        }
    }

    return tabuleiro;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    return ((x >= 0 && x <= 2) && (y >= 0 && y <= 2));
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    return (tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio);
}


int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i, j, livre = 1;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, j, i)){
                livre = 0;
            }
        }
    }

    return livre;

}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        printf("    ");
        for(j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[j][i]);
        }
        printf("\n");
    }
}