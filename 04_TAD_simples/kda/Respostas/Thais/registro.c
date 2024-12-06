#include "jogador.h"
#include "registro.h"
#include "servidor.h"
#include <stdio.h>

/*
Função que lê apenas um registro de partida a partir da entrada padrão. O registro de uma partida
é composto das informações de 5 jogadores. Verifique a especificação da atividade para mais detalhes.

@param idPartida: ID da partida
@return Registro: Registro de uma partida
*/
Registro leRegistro(int idPartida){
    Registro registro;
    registro.idPartida = idPartida;

    int i, id;
    for(i = 0; i < 5; i++){
        scanf("%*[^0-9]");
        scanf("%d:", &id);
        registro.jogadores[i] = leJogador(id);
    }
    return registro;
}

/*
Função que busca um jogador em um registro de partida a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param r: Registro de uma partida
@param idJog: ID do jogador a ser buscado
*/
Jogador buscaJogadorRegistro(Registro r, int idJog){
    int i, id;
    for(i = 0; i < 5; i++){
        if(r.jogadores[i].id == idJog) return r.jogadores[i];
    }

    Jogador jog;
    jog = inicializaJogador(-1);
    return jog;
}
