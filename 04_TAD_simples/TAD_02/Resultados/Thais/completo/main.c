#include "candidato.h"
#include <stdio.h>
#include <string.h>

int main(){
    tCandidato candidato;
    candidato = LeCandidato();
    ImprimeCandidato(candidato, 6.00);
    return 0;
}