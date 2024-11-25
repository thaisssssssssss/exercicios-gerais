#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    int x, y;
    int valida = 0, livre = 0;

    while(1){
        jogada = LeJogada();
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        valida = EhPosicaoValidaTabuleiro(x, y);
        livre = EstaLivrePosicaoTabuleiro(tabuleiro, x, y);

        if(valida && livre) break;
        else if(valida == 0) printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        else if(livre == 0) printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);

        printf("Jogador %d\n", jogador.id);
    }


    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    int venceu = 0;
    char peca;
    if(jogador.id == 1) peca = tabuleiro.peca1;
    else peca = tabuleiro.peca2;

    if((tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[0][1] == peca && tabuleiro.posicoes[0][2] == peca) ||
       (tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[1][2] == peca) ||
       (tabuleiro.posicoes[2][0] == peca && tabuleiro.posicoes[2][1] == peca && tabuleiro.posicoes[2][2] == peca) ||
       (tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][2] == peca) ||
       (tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][0] == peca) ||
       (tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[2][0] == peca) ||
       (tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[1][2] == peca) ||
       (tabuleiro.posicoes[2][0] == peca && tabuleiro.posicoes[2][1] == peca && tabuleiro.posicoes[2][2] == peca)){
            venceu = 1;
       }

    return venceu;
}