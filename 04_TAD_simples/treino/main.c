#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"
#include "clinica.h"

int main(){
    tClinica clinica;
    clinica = abreClinica();
    clinica = atendePacientes(clinica);
    imprimeDadosClinica(clinica);
}