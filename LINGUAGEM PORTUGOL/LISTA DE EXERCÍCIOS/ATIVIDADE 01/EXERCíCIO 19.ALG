Algoritmo "exercício 18"
Var
   valorFinal, valorBoleto, dias: real

Inicio
     escreval("===============================")
     escreval("    CALCULAR BOLETO VENCIDO    ")
     escreval("===============================")

     escreva("Qual o valor do boleto: ")
     leia(valorBoleto)
     escreva("Quantos dias de atraso: ")
     leia(dias)

     
     valorFinal <- valorBoleto + (valorBoleto *(2/100)) + ( valorBoleto * (dias*(0.5/100)))
     escreva("O valor final do boleto é  ", valorFinal)

Fimalgoritmo