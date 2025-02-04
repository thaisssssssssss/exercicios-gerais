#include "franquia.h"
#include "partida.h"
#include "nba.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    tNBA nba = CriaNBA();
    nba = RodaNBA(nba);
    ImprimeRelatorioNBA(nba);
    LiberaNBA(nba);
    return 0;
}