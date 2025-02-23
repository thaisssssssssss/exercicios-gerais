/**
 * @file banco.h
 * @brief Este arquivo contém a declaração da estrutura tBanco e suas funções relacionadas.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include "agencia.h"
 #include "vector.h"
 
 /**
  * @brief Estrutura para representar um banco.
  */
 typedef struct Banco tBanco;
 
 struct Banco{
    char *nome;
    Vector *agencias;
 };

 /**
  * @brief Função para criar um novo banco.
  * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
  */
 tBanco *CriaBanco(){
    tBanco *b = malloc(sizeof(struct Banco));
    b->agencias = VectorConstruct();
    return b;
 }
 
 /**
  * @brief Função para destruir um banco.
  * @param banco O banco a ser destruído.
  */
 void DestroiBanco(tBanco *banco){
    if(banco != NULL){
        if(banco->nome != NULL) free(banco->nome);
        VectorDestroy(banco->agencias, DestroiAgencia);
        free(banco);
    }
 }
 
 /**
  * @brief Função para ler o nome de um banco.
  * @param banco O banco a ser lido.
  */
 void LeBanco(tBanco *banco){
    char nome[50];
    scanf("%[^\n]", nome);
    banco->nome = strdup(nome); //substitui malloc e strcpy
 }
 
 /**
  * @brief Função para adicionar uma agência a um banco.
  * @param banco O banco.
  * @param agencia A agência a ser adicionada.
  */
 void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    VectorPushBack(banco->agencias, agencia);
 }
 
 /**
  * @brief Função para inserir uma conta em uma agência pertencente ao banco.
  * @param banco O banco.
  * @param numAgencia O número da agência.
  * @param cliente A conta a ser inserida.
  * @pre A agência deve pertencer ao banco.
 */
 void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    int i, size = VectorSize(banco->agencias);
    for(i = 0; i < size; i++){
        if(ComparaAgencia(numAgencia, VectorGet(banco->agencias, i))){
            AdicionaConta(VectorGet(banco->agencias, i), cliente);
            break;
        }
    }
 }
 
 /**
  * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
  * @param banco O banco.
  */
 void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");

    int i, size = VectorSize(banco->agencias);
    for(i = 0; i < size; i++){
        ImprimeDadosAgencia(VectorGet(banco->agencias, i));
    }
}
 
