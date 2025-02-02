#include <stdio.h>
#include "registro.h"
#include "jogador.h"


/*
Função que lê apenas um registro de partida a partir da entrada padrão. O registro de uma partida
é composto das informações de 5 jogadores. Verifique a especificação da atividade para mais detalhes.

@param idPartida: ID da partida
@return Registro: Registro de uma partida
*/
Registro leRegistro(int idPartida){
    Registro r;
    r.idPartida = idPartida;
    int i, id;
    for(i = 0; i < 5; i++){
        scanf("%*[^0-9]");
        scanf("%d:", &id);
        //printf("ID(%d)\n", id);
        r.jogadores[i] = leJogador(id);
    }

    int fim, existe = 0;
        //scanf("%d", &fim);
        //printf("FIM(%d)\n", fim);
    return r;
}

/*
Função que busca um jogador em um registro de partida a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param r: Registro de uma partida
@param idJog: ID do jogador a ser buscado
*/
Jogador buscaJogadorRegistro(Registro r, int idJog){
    int j;
    for(j = 0; j < 5; j++){
        if(r.jogadores[j].id == idJog){
            return r.jogadores[j];
        } 
    }
    Jogador jo = inicializaJogador(-1);
    return jo;
}

