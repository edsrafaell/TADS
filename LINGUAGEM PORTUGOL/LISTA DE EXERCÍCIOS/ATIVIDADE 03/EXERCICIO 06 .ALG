Algoritmo "EXERCICIO 06 "
Var
   numero : inteiro

Inicio
     escreval("================================")
     escreval("    PROPRIEDADES DE UM NÚMERO   ")
     escreval("================================")
     escreva("Digite um número inteiro: ")
     leia(numero)
     se (numero mod 2 = 0) entao
        escreval("O NÚMERO DIGITADO É PAR")
     senao
          escreval("O NÚMERO É IMPAR")
     fimse
     
     se (numero > 0) entao
        escreval("O NÚMERO É POSITIVO")
     senao se (numero = 0) entao
          escreval("O NÚMERO É 0 ZERO ZERO ZERO")
     senao
          escreval("O NÚMERO É NEGATIVO")
     fimse
     
Fimalgoritmo
