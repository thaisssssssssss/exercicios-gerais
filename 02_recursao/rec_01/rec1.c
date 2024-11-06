#include <stdio.h>

void ImprimeInvertido(char* string, int i){
    if(i >= 0){
        printf("%c", string[i]);
        ImprimeInvertido(string, i-1);
    }
}

int main(){
    char string[1000];
    scanf("%s", string);

    int i;
    for(i = 0; string[i]; i++);
    ImprimeInvertido(string, i);

}