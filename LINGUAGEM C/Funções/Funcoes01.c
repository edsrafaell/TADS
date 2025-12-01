#include <stdio.h>

int media(int a, int b){
    int resultado;
    resultado = (a + b) / 2;
    return resultado;
}

int main(){
    int n1, n2, mediaFinal;
    n1 = 10;
    n2 = 20; 
    mediaFinal = media(n1, n2);
    printf("%d", mediaFinal);
}