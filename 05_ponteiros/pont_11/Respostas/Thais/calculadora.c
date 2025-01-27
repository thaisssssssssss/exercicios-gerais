#include <stdio.h>
#include "calculadora.h"

/**
 * @brief Ponteiro para função que recebe dois float e realiza uma operação matemática.
 * 
 * @param float resultado da operacao matematica.
 */
typedef float (*CalculatoraCallback)(float, float);

/**
 * @brief Função que realiza uma operação matemática entre dois númeross.
 * 
 * @param num1 Primeiro número.
 * @param num2 Segundo número.
 * @param operacao Ponteiro para a função que realiza a operação matemática.
 * @return float Resultado da operação matemática.
 */
float Calcular(float num1, float num2, CalculatoraCallback operacao){
    return operacao(num1, num2);
}

float adicionar(float num1, float num2){
    return (num1 + num2);
}

float subtrair(float num1, float num2){
    return (num1 - num2);
}

float multiplicar(float num1, float num2){
    return (num1 * num2);
}

float dividir(float num1, float num2){
    return (num1 / num2);
}
