#include <stdio.h>
#include "banco.h"

int main(){
    tBanco *banco = CriaBanco();
    LeBanco(banco);
    char op;

    while(1){
        scanf("%c", &op);
        if(op == 'A'){
            tAgencia *a = CriaAgencia();
            LeAgencia(a);
            AdicionaAgencia(banco, a);
        }
        else if(op == 'C'){
            int a;
            tConta *c = CriaConta();
            LeConta(c);
            scanf("%d", &a);
            InsereContaBanco(banco, a, c);
        }
        else if(op == 'F'){
            ImprimeRelatorioBanco(banco);
            break;
        }
    }

    DestroiBanco(banco);
}