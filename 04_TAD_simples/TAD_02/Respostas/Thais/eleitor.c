#include "eleitor.h"
#include <stdio.h>

tEleitor CriaEleitor(int id, int votoP, int votoG){
    tEleitor eleitor;
    eleitor.id = id;
    eleitor.votoP = votoP;
    eleitor.votoG = votoG;

    return eleitor;
}

tEleitor LeEleitor(){
    int id, vP, vG;
    tEleitor eleitor;
    scanf("%d %d %d", &id, &vP, &vG);

    eleitor = CriaEleitor(id, vP, vG);

    return eleitor;
}

int ObtemVotoPresidente(tEleitor eleitor){
    return eleitor.votoP;
}

int ObtemVotoGovernador(tEleitor eleitor){
    return eleitor.votoG;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2){
    return (eleitor1.id == eleitor2.id);
}

