#include "jogador.h"
#include "registro.h"
#include "servidor.h"
#include <stdio.h>

int main(){
    Servidor servidor;
    servidor = leRegistrosServidor();
    criaRelatorioServidor(servidor);
}