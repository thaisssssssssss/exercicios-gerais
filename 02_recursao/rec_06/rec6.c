#include <stdio.h>

int calculaFibonacciRecursao(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return (calculaFibonacciRecursao(n-2) + calculaFibonacciRecursao(n-1));
    }
}

int main(){
    int num, fibonacci;
    scanf("%d", &num);

    fibonacci = calculaFibonacciRecursao(num);
    printf("%d\n", fibonacci);
}