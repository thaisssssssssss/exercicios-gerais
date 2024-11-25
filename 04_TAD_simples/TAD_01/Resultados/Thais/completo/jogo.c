#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(PECA_1);
    jogo.jogador2 = CriaJogador(PECA_2);

    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo){
    jogo = CriaJogo();
    int venceu = 0;

        while(1){
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
            venceu = VenceuJogador(jogo.jogador1, jogo.tabuleiro);
            if(venceu == 1){
                printf("JOGADOR 1 Venceu!\n");
                break;
            }
            if(AcabouJogo(jogo)){
                printf("Sem vencedor!\n");
                break;
            }

            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
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


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo){
    int acabou;
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)) acabou = 0;
    else acabou = 1;
    return acabou;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo(){
    char jogarNovamente = '0';

        printf("Jogar novamente? (s,n)\n");
        scanf("%*c");
        scanf("%c", &jogarNovamente);

        if(jogarNovamente == 'n') return 0;
        else if(jogarNovamente == 's') return 1;
        else{
            scanf("%*c");
            scanf("%*c");
            scanf("%*c");
            scanf("%*c");
            scanf("%*c");
            scanf("%c", &jogarNovamente);
            if(jogarNovamente == 'n') return 0;
            else if(jogarNovamente == 's') return 1;
        }
}
