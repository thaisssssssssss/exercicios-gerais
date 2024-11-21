#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>


void ComecaJogo(tJogo jogo){
    jogo = CriaJogo();
    int venceu = 0;

        while(1){
            printf("Jogador 1\n");
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
            venceu = VenceuJogador(jogo.jogador1, jogo.tabuleiro);
            if(venceu == 1){
                printf("JOGADOR 1 Venceu!\n");
                break;
            }
            if(AcabouJogo(jogo)){
                printf("Sem vencedor!\n");
                break;
            }

            printf("Jogador 2\n");
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            venceu = VenceuJogador(jogo.jogador2, jogo.tabuleiro);
            if(venceu == 1){
                printf("JOGADOR 2 Venceu!\n");
                break;
            }
            if(AcabouJogo(jogo)){
                printf("Sem vencedor!\n");
                break;
            }

        }
    
}

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(PECA_1);
    jogo.jogador2 = CriaJogador(PECA_2);

    return jogo;
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

