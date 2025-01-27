#include <stdio.h>
#include "calculadora.h"

// Função que realiza a adição
float adicionar(float num1, float num2) {
    return num1 + num2;
}

// Função que realiza a subtração
float subtrair(float num1, float num2) {
    return num1 - num2;
}

// Função que realiza a multiplicação
float multiplicar(float num1, float num2) {
    return num1 * num2;
}

// Função que realiza a divisão
float dividir(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Erro: Divisão por zero.\n");
        return 0;
    }
}

// Função que realiza a operação matemática usando o callback
float Calcular(float num1, float num2, CalculatoraCallback operacao) {
    return operacao(num1, num2);
}
