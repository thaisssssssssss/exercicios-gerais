#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "data.h"
#include "lesao.h"

int main(){
    tPaciente p;
    p = lePaciente();
    imprimePaciente(p);

    tLesao lesao;
    lesao = leLesao();
    printf("%s\n", lesao.id);
    printf("%s\n", lesao.diagnostico);
    printf("%s\n", lesao.regiao);
    printf("%d\n", lesao.pctgMaligno);
}

P
SHOKO KOMI
01/01/1999
123-1234-1234-1234
F
L
123-1234-1234-1234
L1
CARCINOMA BASO CELULAR
LABIO
60
P
THAIS BRANDAO
15/08/2005
111-1111-1111-1111
F
L 
111-1111-1111-1111
L2 
EXCESSO DE PERFEICAO
TUDO
80
L
111-1111-1111-1111
L22
DIARREIA
CU 
49
L
112-2222-2222-2222
L15
FOME 
BOCA 
30