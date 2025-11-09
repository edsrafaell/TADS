Algoritmo "exercício 06"
Var
   valorA, valorB, valorATemp: real
   
Inicio
     escreval("===============================")
     escreval(" INVERTER VALORES DE VARIAVEIS ")
     escreval("===============================")
     
     escreva("Digite um Valor para A: ")
     leia(valorA)
     escreva("Digite um Valor para B: ")
     leia(valorB)
     escreval("Valor de A é: ",valorA)
     escreval("Valor de B é: ",valorB)
     
     escreval("...TROCANDO..................")
     
     valorATemp <- valorA
     valorA <- valorB
     valorB <- valorATemp
     escreval("Valor de A é: ",valorA)
     escreva("Valor de B é: ",valorB)
     

Fimalgoritmo