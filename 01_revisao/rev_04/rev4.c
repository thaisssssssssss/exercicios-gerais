#include <stdio.h>

int main(){
    int decimal;
    int resto;
    int octal = 0, i = 1;
    scanf("%d", &decimal);

    while(1){
        resto = decimal % 8;
        decimal = decimal / 8;
        octal += resto * i;
        i = i * 10;
        if(decimal / 8 < 8){
            break;
        }
    }
    resto = decimal % 8;
    octal += resto * i;
    decimal = decimal / 8;
    octal += decimal * i * 10;
   
    printf("%d", octal);
}