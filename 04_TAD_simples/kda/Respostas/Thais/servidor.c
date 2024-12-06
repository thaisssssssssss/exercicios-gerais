#include "jogador.h"
#include "registro.h"
#include "servidor.h"
#include <stdio.h>


/*
Função que lê todos os registros de partidas de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de partidas lidos. Conforme a especificação da atividade, a leitura é encerrada quando
um ID de partida igual a -1 é lido.

@return Servidor: Servidor com todos os registros de partidas lidos
*/
Servidor leRegistrosServidor(){
    Servidor servidor;
    int idPartida;
    servidor.nPartidas = 0;

    while(1){
        scanf("%d", &idPartida);
        if(idPartida == -1) break;
        else{
            servidor.partidas[servidor.nPartidas] = leRegistro(idPartida);
            servidor.nPartidas++;
        }
    }
    return servidor;
}

/*
Função que recebe um servidor já preenchido com os dados de todas as partidas e um ID de jogador.
A partir dessas informações, ela busca as estatísticas do jogador em todas as partidas que ele participou.
Se o jogar não for encontrado, um jogador com ID -1 é criado e retornado.
Se o jogador for encontrado em apenas uma partida, ele é retornado.
Se o jogador for encontrado em mais de uma partida, suas estatísticas são agregadas e o jogador é retornado.

@param s: Servidor
@param idJog: ID do jogador
*/
Jogador buscaDadosJogadorServidor(Servidor s, int idJog){
    int i, aparicoes = 0;
    Jogador jog, repetido;
    repetido = inicializaJogador(-1);

    for(i = 0; i < s.nPartidas; i++){
        jog = buscaJogadorRegistro(s.partidas[i], idJog);
        if(jog.id != -1) {
            int k = getKillsJogador(jog);
            int d = getDeathsJogador(jog);
            int a = getAssistsJogador(jog);
            repetido = atualizaJogador(repetido, jog.id, k, d, a);
        }
    }

    return repetido;
}

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.
*/
void criaRelatorioServidor(Servidor s){
    int qtdJogadores, id, i;
    scanf("%d", &qtdJogadores);
    for(i = 0; i < qtdJogadores; i++){
        Jogador jog;
        scanf("%d", &id);
        jog = buscaDadosJogadorServidor(s, id);
        if(jog.id != -1) printaJogador(jog);
        else if(jog.id == -1) printf("Jogador %d: -\n", id);
    }
}
