// #include <stdio.h>


// int main() {
//     FILE*fp;
//     fp = fopen("exemplo.txt","a");

//     if(fp == NULL) {
//         printf("Erro na abertura do arquivo\n");
//     }

//     fclose(fp);
//     return  0;
// }

// int fputc(INT ch, FILE *fp);
// • Cada invocação dessa função grava um único caractere ch no 
// arquivo especificado por fp.

// int fgetc(FILE *fp);
// • Cada chamada da função fgetc lê um único caractere do arquivo 
// especificado.

// int fputs(char *str, FILE *fp);
// • Esta função recebe como parâmetro um array de caracteres 
// (string) e um ponteiro para o arquivo no qual queremos 
// escrever.

// char *fgets(char *str, int tamanho, FILE *fp);
// • Para se ler uma string de um arquivo podemos usar a função 
// fgets() cujo protótipo é: 
// • A função fgets recebe 3 parâmetros
//  • str: aonde a lida será armazenada, str;
//  • tamanho :o número máximo de caracteres a serem lidos;
//  • fp: ponteiro que está associado ao arquivo de onde a string será 
// lida.

// unsigned fwrite(void *buffer, int numero_bytes, int count, FILE *fp);
// • A função fwrite recebe 4 argumentos
// • buffer: ponteiro para a região de memória na qual estão os dados;
// • numero_de_bytes: tamanho de cada posição de memória a ser 
// escrita;
// • count: total de unidades de memória que devem ser escritas;
// • fp: ponteiro associado ao arquivo onde os dados serão escritos.

// int main() {
//     FILE *fp;
//     fp = fopen("exemplo.bin","wb");
//     char string[100] = "Hello World";
//     float x = 5.7;
//     int V[5] = {1,2,3,4,5};
//     //.. Verficacoes do arquivo ..
//     //grava a string toda no arquivo
//     fwrite(string, sizeof(char), strlen(string), fp);
//     //grava apenas os 5 primeiros caracteres da string
//     fwrite(string, sizeof(char), 5, fp);
//     //grava o valor de x
//     fwrite(&x, sizeof(float), 1, fp);
//     //grava o array de inteiros no arquivo (5 posicoes)
//     fwrite(V, sizeof(int), 5, fp);
//     //grava 2 primeiras posicoes)
//     fwrite(V, sizeof(int), 2, fp);
//     fclose(fp);
//     return 0;
// }


// unsigned fread(void *buffer, int numero_bytes, int count, FILE *fp);


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "base_alunos.h"

int main(){
    tBaseAlunos *base = CriarBaseAlunos();
    char nomeBase[100];
    scanf("%s", nomeBase);
    LerBaseAlunos(base, nomeBase);
    float mediaCr = GetCoeficienteRendimentoMedioBaseAlunos(base);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", mediaCr);
    DestruirBaseAlunos(base);
    return 0;
}