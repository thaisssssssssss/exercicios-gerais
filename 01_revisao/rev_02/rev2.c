#include <stdio.h>

int main(){
    int n, i, j, k = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            k++;
            printf("%d", k);
            if(j != i){
                printf(" ");
            }
        }
        printf("\n");
    }
}