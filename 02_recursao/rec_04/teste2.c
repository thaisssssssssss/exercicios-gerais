#include<stdio.h>
    #include<string.h>


    int inverte (char *n, int y, int aux) {
        if (y <= aux) return 1;
        else {
            if (n[y] != n[aux]) return 0;

            return inverte(n, y-1, aux+1);
        } 
    }

     int palindromo (char *n) {
        int aux1, x = 0;

        aux1 = inverte(n, strlen(n) - 1, x);

        if (aux1 == 1) printf("SIM\n");
        else printf("NAO\n");

     }


     int main() {
        char string[100];
        int recebe;

        while(1){
            recebe = scanf("%s", string);
            if(recebe == -1 || recebe == 0){
                break;
            }
            palindromo(string);
        }
       

        return 0; 
     }