Algoritmo "volume"
Var
    volume, largura, altura, comprimento : real

Inicio
    escreval("--------------------------------------")

    escreval("***PROGRAMA CALCULA VOLUME DE CAIXA***")
    escreval("--------------------------------------")
    escreva("Digite o comprimento: ")
    leia (comprimento)
    escreva("Digite a altura: ")
    leia (altura)
    escreva("Digite o largura: ")
    leia (largura)
    volume <- largura * altura * comprimento
    escreva ("O volume da Caixa Retangular é: ",volume)

FimAlgoritmo