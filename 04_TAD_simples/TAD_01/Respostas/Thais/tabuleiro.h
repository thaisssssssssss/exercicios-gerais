#ifndef _TABULEIRO_H
#define _TABULEIRO_H


#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

typedef struct{
    char posicoes[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca1;
    char peca2;
    char pecaVazio;
} tTabuleiro;

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
                        printf("Posicao invalida (OCUPADA - [x,y] )!\n");
                    }
                }
            }
        }
    }
    else{
        printf("Posicao invalida (FORA DO TABULEIRO - [x,y] )!\n");
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

#endif
