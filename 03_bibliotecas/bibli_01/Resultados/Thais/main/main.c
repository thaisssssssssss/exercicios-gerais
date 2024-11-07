#include "esfera_utils.h"

int main(int argc, char *argv[]){

    float raio;
    float v, a;
    scanf("%f", &raio);

    v = calcula_volume(raio);
    a = calcula_area(raio);

    printf("Area: %.2f\nVolume: %.2f", a, v);

    return 0;
}