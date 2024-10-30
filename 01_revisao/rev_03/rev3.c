#include <stdio.h>

int main(){
    int qtd;

    scanf("%d\n", &qtd);

    int vet[qtd];
    int ordenador[qtd];

    int i, j, copia = 0, existemCopias = 0, k = 0;

    for(i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }
    for(i = 0; i < qtd; i++){
        for(j = 0; j < qtd; j++){
            if(j != i && vet[i] == vet[j]){
                copia++;
            }
        }
        if(copia == 0){
            ordenador[k] = vet[i];
            k++;
            existemCopias++;
        }
        copia = 0;   
    }
    
    if(existemCopias == 0){
        printf("NENHUM");
    }
    else{
        int aux;
        //ordenar vetor
        for(i = 0; i <= k; i++){
            for(j = i; j < k; j++){
                if(ordenador[i] > ordenador[j]){
                    aux = ordenador[j];
                    ordenador[j] = ordenador[i];
                    ordenador[i] = aux;
                }
            }
        }
        for(i = 0; i < k; i++){
            printf("%d", ordenador[i]);
            if(i != k - 1){
                printf(" ");
            }
        }
    }
}