#include <stdio.h>

int NumerosRepetidosRecursao(int vet[], int qtd, int chave){
    qtd--;
    if(qtd < 0)
        return 0;

    int x;
    if(vet[qtd] == chave){
        x = 1;
    }
    else{
        x = 0;
    }
    return x + NumerosRepetidosRecursao(vet, qtd, chave);
}

int main(){

    int qtdVetores, j;
    int qtdNumeros, i;
    int chave;

    scanf("%d\n", &qtdVetores);
    for(j = 0; j < qtdVetores; j++){

        scanf("%d %d\n", &chave, &qtdNumeros);
        int vet[qtdNumeros];
        for(i = 0; i < qtdNumeros; i++){
            scanf("%d", &vet[i]);
        }

        int repeticao = NumerosRepetidosRecursao(vet, i, chave);
        printf("%d\n", repeticao);
    }

    return 0;
}
