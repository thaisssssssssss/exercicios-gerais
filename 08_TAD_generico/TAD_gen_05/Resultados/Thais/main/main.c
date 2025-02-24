#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"

int main(){
    int qtd, i, prioridade;
    printf("Digite o numero de tarefas: ");
    scanf("%d%*c", &qtd);
    tAgendaTarefas *a = CriaAgendaDeTarefas(qtd);
    char op;

    for(i = 0; i < qtd; i++){
        scanf("%d %c%*c", &prioridade, &op);
        if(op == 'I'){
            char msg[100];
            scanf("%[^\n]%*c", msg);
            tImpr *impr = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(a, prioridade, impr, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        }
        else if(op == 'M'){
            float n1, n2;
            scanf("%f %f%*c", &n1, &n2);
            tMult *m = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(a, prioridade, m, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
        else if(op == 'S'){
            float n1, n2;
            scanf("%f %f%*c", &n1, &n2);
            tSoma *s = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(a, prioridade, s, ExecutaTarefaSoma, DestroiTarefaSoma);
        }
        else{
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^0-9]");
            i--;
        }
    }

    ExecutarTarefasDaAgenda(a);
    DestroiAgendaDeTarefas(a);
    
}