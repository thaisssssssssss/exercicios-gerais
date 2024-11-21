#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>


void ComecaJogo(tJogo jogo){
    jogo = CriaJogo();
    int venceu = 0;

    while(1){

        while(1){
            printf("Jogador 1\n");
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
            venceu = VenceuJogador(jogo.jogador1, jogo.tabuleiro);
            if(venceu == 1){
                printf("JOGADOR 1 Venceu!\n");
                break;
            }
            if(AcabouJogo(jogo)) break;

            printf("Jogador 2\n");
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            venceu = VenceuJogador(jogo.jogador2, jogo.tabuleiro);
            if(venceu == 1){
                printf("JOGADOR 2 Venceu!\n");
                break;
            }
            if(AcabouJogo(jogo)) break;

        }
        
        if(venceu == 1) break;
        if(AcabouJogo(jogo)) break;

    }
    
}

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(PECA_1);
    jogo.jogador2 = CriaJogador(PECA_2);

    return jogo;
}

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
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

tJogada LeJogada(){
    tJogada jogada;
    int sucesso;
        printf("Digite uma posicao (x e y):\n");
        sucesso = scanf("%d %d", &jogada.x, &jogada.y);
        if(sucesso == 1) jogada.sucesso = 1;
        else jogada.sucesso = 0;

    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    int i, j;

    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(i == x && j == y){
                if(peca == PECA_1) tabuleiro.posicoes[i][j] = tabuleiro.peca1;
                else tabuleiro.posicoes[i][j] = tabuleiro.peca2;
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

//nao sei onde usar
int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
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

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i, j, livre = 1;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, i, j)){
                livre = 0;
            }
        }
    }

    return livre;

}

int AcabouJogo(tJogo jogo){
    int acabou = 0;
    acabou = TemPosicaoLivreTabuleiro(jogo.tabuleiro);
    return acabou;
}

int ContinuaJogo(){
    char jogarNovamente = '0';

        printf("Jogar novamente? (s,n)\n");
        scanf("%*c");
        scanf("%c", &jogarNovamente);


        if(jogarNovamente == 'n'){
            return 0;
        }
        else if(jogarNovamente == 's'){
            return 1;
        }

}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}