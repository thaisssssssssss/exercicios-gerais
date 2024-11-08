#include "string_utils.h"
#include <stdio.h>

int string_length(char *str){
    int lenght;
    for(lenght = 0; str[lenght]; lenght++);
    return lenght + 2;
}

void string_copy(char *src, char *dest){
    int lenght, i;
    lenght = string_length(src);

    for(i = 0; i < lenght - 2; i++){
        dest[i] = src[i];
    }
}

void string_upper(char *str){
    int lenght, i;
    lenght = string_length(str);

    for(i = 0; i < lenght - 2; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void string_lower(char *str){
    int lenght, i;
    lenght = string_length(str);

    for(i = 0; i < lenght - 2; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 'a' - 'A';
        }
    }
}

void string_reverse(char *str){
    int lenght, i, j;
    char aux;

    lenght = string_length(str);

    for(i = 0; i < (lenght -2) / 2; i++){
        aux = str[i];
        str[i] = str[lenght - i - 3];
        str[lenght - i - 3] = aux;
    }
}


