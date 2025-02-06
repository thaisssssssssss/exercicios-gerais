#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "operacao.h"
#include "conta.h"

typedef struct Agencia tAgencia;

struct Agencia{
    float saldo;
    tConta **contas;
    int numContas;
    tOperacao **ops;
    int numOps;
    //tOperacao **operacao;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tAgencia. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero.
 *
 * @return A variável do tipo Agencia inicializada.
 */
tAgencia* CriaAgencia(){
    tAgencia *a = malloc(sizeof(struct Agencia));
    if(a == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    a->contas = NULL;
    a->ops = NULL;
    a->numContas = 0;
    a->numOps = 0;
    a->saldo = 0;
    return a;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma agencia.
 *
 * @param A variável do tipo Agencia que será apagada.
 */
void DestroiAgencia(tAgencia* agencia){
    if(agencia != NULL){
        int i;
        if(agencia->contas != NULL){
            for(i = 0; i < agencia->numContas; i++){
                DestroiConta(agencia->contas[i]);
            }
            free(agencia->contas);
        }
        if(agencia->ops != NULL){
            for(i = 0; i < agencia->numOps; i++){
                DestroiOperacao(agencia->ops[i]);
            }
            free(agencia->ops);
        }
        free(agencia);
    }
}

/**
 * @brief Le as informações de uma agencia - contas e operações, no formato especificado no roteiro
 *
 * @param agencia - A variável do tipo agencia que salvará os dados lidos
 */
void LeOperacoes(tAgencia *agencia){
    int i, id, c, existe = 0;
    float valor;

    scanf("%d", &agencia->numContas);
    agencia->contas = malloc(agencia->numContas*sizeof(struct Conta*));
    if(agencia->contas == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < agencia->numContas; i++){
        scanf("%d", &id);
        if(id > 0){
            for(c = 0; c < i; c++){
                if(ConfereIdConta(agencia->contas[c], id)) {
                    printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!");
                    i--;
                    existe = 1;
                    break;
                }
            }
            if(!existe){
                agencia->contas[i] = CriaConta(id);
            }
        }
        else{
            printf("\nDigite um id valido para a conta a ser cadastrada!");
            i--;
        }
        existe = 0;
    }

    while(1){
        scanf("%d", &agencia->numOps);
        if(agencia->numOps <= 50) break;
    }

    agencia->ops = malloc(agencia->numOps*sizeof(struct Operacao*));
    if(agencia->ops == NULL){
        printf("Falha!");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < agencia->numOps; i++){
        scanf("%d %f", &id, &valor);
        if(id > 0){
            if(BuscaContaPorId(agencia, id) == NULL) {
                printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
                i--;
            }
            else{
                agencia->ops[i] = CriaOperacao(BuscaContaPorId(agencia, id), valor);
                for(c = 0; c < agencia->numContas; c++){
                    if(ConfereIdConta(agencia->contas[c], RetornaIdConta(BuscaContaPorId(agencia, id)))){
                        AlteraSaldoConta(agencia->contas[c], valor);
                    }
                }
                agencia->saldo += valor;
            }
        }
        else{
            printf("Conta Invalida! Repita a operacao, mas com uma conta valida!\n");
            i--;
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param agencia - A agencia na qual queremos buscar a conta com o id específico
 * @param id - o ID da conta que queremos buscar
 *conferido
 * @return A conta, caso exista, e NULL, caso contrário
 */
tConta* BuscaContaPorId(tAgencia *agencia, int id){
    int i;
    for(i = 0; i < agencia->numContas; i++){
        if(ConfereIdConta(agencia->contas[i], id)){
            return agencia->contas[i];
        }
    }
    return NULL;
}

/**
 * @brief Função que imprime em tela as operações suspeitas de uma agência
 *
 * @param agencia A Agência na qual as operações suspeitas serão impressas em tela.
 */
void ImprimeOperacoesSuspeitas(tAgencia* agencia){
    int i;
    printf("\nA lista de operações suspeitas:");
    for(i = 0; i < agencia->numOps; i++){
        if(agencia->ops[i] != NULL){
            if(ConsultaValorOperacao(agencia->ops[i]) > 20000 || ConsultaValorOperacao(agencia->ops[i]) < -20000){
                ImprimeOperacao(agencia->ops[i]);
            }
        }
    }
}

/**
 * @brief Função que imprime em tela os dois correntistas com maior saldo
 *
 * @param agencia A Agência na qual os dois correntistas com maior saldo impressos em tela.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia){
    int i, j, id, id2;
    float maior = 0, maior2 = 0;

    printf("\nOs dois correntistas com maior saldo são:");
    for(i = 0; i < agencia->numContas; i++){
        if(RetornaSaldoConta(agencia->contas[i]) > maior){
            maior = RetornaSaldoConta(agencia->contas[i]);
            id = RetornaIdConta(agencia->contas[i]);
        }
    }
    for(i = 0; i < agencia->numContas; i++){
        if(RetornaSaldoConta(agencia->contas[i]) > maior2 && RetornaIdConta(agencia->contas[i]) != id){
            maior2 = RetornaSaldoConta(agencia->contas[i]);
            id2 = RetornaIdConta(agencia->contas[i]);
        }
    }

    printf("\nId: %d, Saldo: %.2f", id, maior);
    printf("\nId: %d, Saldo: %.2f", id2, maior2);

}


/**
 * @brief Função que imprime em tela o saldo total da agência
 *
 * @param agencia A Agência na qual o saldo total impresso em tela.
 */
void ImprimeSaldoTotal(tAgencia* agencia){
    printf("\nO saldo total da agencia eh: %.2f", agencia->saldo);
}
