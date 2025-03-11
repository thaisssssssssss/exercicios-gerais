#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "vector.h"
#include "estabelecimento.h"

int main(){
    tEstabelecimento *e = CriaEstabelecimento();
    LeEstabelecimento(e);
    ImprimeRelatorioEstabelecimento(e);
    DestroiEstabelecimento(e);
    return 0;
}