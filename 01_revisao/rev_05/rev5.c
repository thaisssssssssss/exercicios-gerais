#include <stdio.h>

int main(){
    int linhas, colunas, l, c;
    char m, n;
    int xinicial, yinicial, xfinal, yfinal;

    scanf("%d %d", &linhas, &colunas);
    scanf("%*c");
    char mapa[linhas][colunas];

    for(l = 1; l <= linhas; l++){
        for(c = 1; c <= colunas; c++){
            scanf("%c ", &mapa[l][c]);
        }
    }

    scanf("%d %d", &xinicial, &yinicial);
    scanf("%*c");
    scanf("%d %d", &xfinal, &yfinal);
    scanf("%*c");
    
    char seq[4];
    int k;
    for(k = 0; k < 4; k++){
        scanf("%c", &seq[k]);
    }

   
    //inicio do jogo
    printf("(%d,%d) ", xinicial, yinicial);
    mapa[xinicial][yinicial] = '1';
    k = 0;
    
    while(1){


        if(seq[k] == 'C'){
            if(xinicial != 1 && mapa[xinicial - 1][yinicial] == '0'){
                mapa[xinicial - 1][yinicial] = '1';
                xinicial = xinicial - 1;
                printf("(%d,%d) ", xinicial, yinicial);
            
                k = 0;
            }
            else{
                k++;
            }
        }

        if(seq[k] == 'B'){
            if(xinicial != linhas && mapa[xinicial + 1][yinicial] == '0'){
                mapa[xinicial + 1][yinicial] = '1';
                xinicial = xinicial + 1;
                printf("(%d,%d) ", xinicial, yinicial);
                k = 0;
            }
            else{
                k++;
            }
        }
        if(seq[k] == 'D'){
            if(yinicial != colunas && mapa[xinicial][yinicial + 1] == '0'){
                mapa[xinicial][yinicial + 1] = '1';
                yinicial = yinicial + 1;
                printf("(%d,%d) ", xinicial, yinicial);
                k = 0;
            }
            else{
                k++;
            }
        }
        if(seq[k] == 'E'){
            if(yinicial != 1 && mapa[xinicial][yinicial - 1] == '0'){
                mapa[xinicial][yinicial - 1] = '1';
                yinicial = yinicial - 1;
                printf("(%d,%d) ", xinicial, yinicial);
                k = 0;
            }
            else{
                k++;
            }
        }

        if(xinicial == xfinal && yinicial == yfinal){
            break;
        }
        else if(k > 3){
            break;
        }

    }
 
       
}

