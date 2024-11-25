#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    int x, y;
    int valida = 0, livre = 0, sucesso;

        printf("Jogador %d\n", jogador.id);
        
        jogada = LeJogada();
        sucesso = FoiJogadaBemSucedida(jogada);

        if(sucesso){
            x = ObtemJogadaX(jogada);
            y = ObtemJogadaY(jogada);

            valida = EhPosicaoValidaTabuleiro(x, y);
            livre = EstaLivrePosicaoTabuleiro(tabuleiro, x, y);

            if(valida == 0){
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
                tabuleiro = JogaJogador(jogador, tabuleiro);
            }
            else if(livre == 0){
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
                tabuleiro = JogaJogador(jogador, tabuleiro);
            }
            else{
                tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
                printf("Jogada [%d,%d]!\n", x, y);
            }
        }
        else{
            printf("Formato invalido!\n");
            tabuleiro = JogaJogador(jogador, tabuleiro);
            //exit(0);
        }

        return tabuleiro;

}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
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
       (tabuleiro.posicoes[0][1] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][1] == peca) ||
       (tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][2] == peca && tabuleiro.posicoes[2][2] == peca) ){
            venceu = 1;
       }

    return venceu;
}
