#include "string_utils.h"
#include <stdio.h>

int main(){
    char string[1000];
    int option;
    scanf ("%[^\n]", string);

    int lenght = 0;

    while(1){
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida:\n");
        scanf("%d", &option);

        if(option == 1){
            lenght = string_length(string);
            printf("Tamanho da string: %d\n\n", lenght);
        }
        else if(option == 2){
            lenght = string_length(string);
            char copy[lenght - 2];
            string_copy(string, copy);
            printf("String copiada: %s\n\n", copy);
        }
        else if(option == 3){
            string_upper(string);
            printf("String convertida para maiusculas: %s\n\n", string);
        }
        else if(option == 4){
            string_lower(string);
            printf("String convertida para minusculas: %s\n\n", string);
        }
        else if(option == 5){
            string_reverse(string);
            printf("String invertida: %s\n\n", string);
        }
        else if(option == 6){
            break;
        }
    }
    return 0;
}