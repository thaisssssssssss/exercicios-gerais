#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carta.h"

bool EhVerdade(int x){
    if(x < 3) return true;
    else return false;
}

int main(){
    int x;
    scanf("%d", &x);
    if(EhVerdade(x)) printf("verdade\n");
    else printf("mentira\n");
}