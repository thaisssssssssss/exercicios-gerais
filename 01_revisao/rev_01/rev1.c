#include <stdio.h>
#include <math.h>

int main(){
    float xAlvo, yAlvo, rAlvo, xTiro, yTiro, rTiro;
    scanf("%f %f %f\n%f %f %f", &xAlvo, &yAlvo, &rAlvo, &xTiro, &yTiro, &rTiro);

    float distancia;

    distancia = pow((xAlvo - xTiro),2) + pow((yAlvo - yTiro),2);
    
    distancia = sqrt(distancia);

    if(distancia <= rAlvo + rTiro){
        printf("ACERTOU");
    }
    else{
        printf("ERROU");
    }
    return 0;
}