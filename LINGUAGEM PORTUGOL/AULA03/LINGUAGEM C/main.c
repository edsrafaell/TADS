#include <stdio.h>
#include <stdlib.h>
int main() {
    float volume, comprimento, largura, altura;
    
    printf("Digite o comprimento: ");
    scanf("%f",&comprimento);
    printf("Digite a largura: ");
    scanf("%f",&largura);
    printf("Digite a altura: ");
    scanf("%f",&altura);
    
    volume = comprimento * largura * altura;
    printf("O resultado da soma eh:  %.2f\h",volume);
    return 0;

}
