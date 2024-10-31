#include <stdio.h>


int SomaDosParesRecursao(int vet[], int i, int a){
    if(a > i){
        return 0;
    }
    else{
        if(vet[a] % 2 == 0){
            return SomaDosParesRecursao(vet+1, i, a + 1) + vet[a];
        }
        else{
            return SomaDosParesRecursao(vet+1, i, a + 1);
        }
    }
}

int Recursao(int vet[], int qtd);

int main(){
    int qtd, i;
    int soma = 0;
    scanf("%d\n", &qtd);

    int vet[qtd];

    for(i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }

    printf("%d", Recursao(vet, i));
}

int Recursao(int vet[], int qtd){
    qtd--;
    if(qtd < 0)
        return 0;

    int x = (vet[qtd] % 2 == 0) ? vet[qtd] : 0;
    return x + Recursao(vet, qtd--);
}