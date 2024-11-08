#include "string_utils.h"
#include <stdio.h>

int string_length(char *str){
    int lenght;
    for(lenght = 0; str[lenght]; lenght++);
    return lenght;
}

void string_copy(char *src, char *dest){
    int lenght, i;
    lenght = string_length(src);

    for(i = 0; i < lenght; i++){
        dest[i] = src[i];
    }
}

void string_upper(char *str){
    int lenght, i;
    lenght = string_length(str);

    for(i = 0; i < lenght; i++){
        str[i] = str[i] - 'a' + 'A';
    }
}

void string_lower(char *str){
    int lenght, i;
    lenght = string_length(str);

    for(i = 0; i < lenght; i++){
        str[i] = str[i] + 'a' - 'A';
    }
}

void string_reverse(char *str){
    int lenght, i, j;
    char aux;

    lenght = string_length(str);

    for(i = 0, j = lenght - 1; i < lenght && j <= 0; i++, j--){
        if(j < i || j == i){
            break;
        }
        aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}


