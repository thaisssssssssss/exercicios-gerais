#include "jogo.h"
#include <stdio.h>

/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 * 
 * @return o tabuleiro criado.
 */
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


/**
 * Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada x da posição a ser marcada.
 * @param y a coordenada y da posição a ser marcada.
 * 
 * @return o tabuleiro atualizado.
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    int i, j;

    if(EhPosicaoValidaTabuleiro(x, y)){
        for(i = 0; i < TAM_TABULEIRO; i++){
            for(j = 0; j < TAM_TABULEIRO; j++){
                if(i == x && j == y){
                    if(EstaLivrePosicaoTabuleiro(tabuleiro, i, j)){
                        if(peca == PECA_1) tabuleiro.posicoes[i][j] = tabuleiro.peca1;
                        else tabuleiro.posicoes[i][j] = tabuleiro.peca2;
                    }
                    else{
                        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
                    }
                }
            }
        }
    }
    else{
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
    }

    return tabuleiro;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i, j, livre = 0;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                livre++;
            }
        }
    }

    return livre;

}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca == PECA_1) return (tabuleiro.posicoes[x][y] = tabuleiro.peca1);
    else return (tabuleiro.posicoes[x][y] = tabuleiro.peca2);
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    return tabuleiro.posicoes[x][y] = tabuleiro.pecaVazio;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
*/
int EhPosicaoValidaTabuleiro(int x, int y){
    return ((x >= 0 && x <= 2) && (y >= 0 && y <= 2));
}


/**
 * Verifica se o tabuleiro está cheio.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro){
    
}




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

    jogada = LeJogada();
    x = ObtemJogadaX(jogada);
    y = ObtemJogadaY(jogada);

    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);

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

    if((tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[1][2] == peca && tabuleiro.posicoes[1][3] == peca) ||
       (tabuleiro.posicoes[2][1] == peca && tabuleiro.posicoes[2][2] == peca && tabuleiro.posicoes[2][3] == peca) ||
       (tabuleiro.posicoes[3][1] == peca && tabuleiro.posicoes[3][2] == peca && tabuleiro.posicoes[3][3] == peca) ||
       (tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][2] == peca && tabuleiro.posicoes[3][3] == peca) ||
       (tabuleiro.posicoes[1][3] == peca && tabuleiro.posicoes[2][2] == peca && tabuleiro.posicoes[1][3] == peca) ||
       (tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][1] == peca && tabuleiro.posicoes[3][1] == peca) ||
       (tabuleiro.posicoes[1][2] == peca && tabuleiro.posicoes[2][2] == peca && tabuleiro.posicoes[3][2] == peca) ||
       (tabuleiro.posicoes[1][3] == peca && tabuleiro.posicoes[2][3] == peca && tabuleiro.posicoes[3][3] == peca)){
            venceu = 1;
       }

    return venceu;
}







/**
 * Lê uma jogada e retorna uma estrutura do tipo tJogada e define o valor da variavel sucesso.
 * Se a jogada foi lida com sucesso, ou seja, foi lido um valor para x e outro para y, sucesso = 1, caso contrário, sucesso = 0.
 * @return a jogada lida.
 */
tJogada LeJogada(){
    tJogada jogada;
    int sucesso;
        sucesso = scanf("%d %d", &jogada.x, &jogada.y);
        if(sucesso == 1) jogada.sucesso = 1;
        else jogada.sucesso = 0;

    return jogada;
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a jogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}





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

    while(1){
        JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
    }
}