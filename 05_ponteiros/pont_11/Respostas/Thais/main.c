#include <stdio.h>
#include "calculadora.h"
#include <math.h>


int main(){
    char operacao;
    float num1, num2;
    float resultado;
    while(1){
        scanf("%c", &operacao);

        if(operacao == 'f') break;    
        scanf("%f %f", &num1, &num2);
        switch (operacao){
            case 'a':
                resultado = Calcular(num1, num2, adicionar);
                printf("%.2f + %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 's':
                resultado = Calcular(num1, num2, subtrair);
                printf("%.2f - %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 'm':
                resultado = Calcular(num1, num2, multiplicar);
                printf("%.2f x %.2f = %.2f\n", num1, num2, resultado);
                break;
            case 'd':
                resultado = Calcular(num1, num2, dividir);
                printf("%.2f / %.2f = %.2f\n", num1, num2, resultado);

                break;
            default:
                break;
            }
    }
}