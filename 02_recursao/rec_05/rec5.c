#include <stdio.h>

int calculaFatorialRecursao(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n * calculaFatorialRecursao(n-1);
    }
}

int main(){
    int num, fatorial;
    scanf("%d", &num);

    fatorial = calculaFatorialRecursao(num);
    printf("%d\n", fatorial);
}