#include <stdio.h>
#include "franquia.h"
#include "partida.h"
#include "nba.h"
#include <stdlib.h>
#include <string.h>

int main(){
    tNBA n = CriaNBA();
    n = RodaNBA(n);
    ImprimeRelatorioNBA(n);
    LiberaNBA(n);
    return 0;
}