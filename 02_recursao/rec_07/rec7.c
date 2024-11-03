#include <stdio.h>

int somaDigitos(int n){
    if(n < 10){
        return n;
    }
    else{
        return (n % 10) + somaDigitos(n/10);
    }
}

int main(){
    int num, somaDig;
    scanf("%d", &num);

    somaDig = somaDigitos(num);
    printf("%d\n", somaDig);
}