Algoritmo "EXERCICIO 03"
Var
   total, subTotal, gorjeta, valorConsumido, percentualGorjeta, descontoReais : real

Inicio
     escreval("============================")
     escreval(" CALCULAR CONTA RESTAURANTE ")
     escreval("============================")
     escreva("Qual valor consumido:")
     leia(valorConsumido)
     escreva("Qual o valor do desconto em reais: ")
     leia(descontoReais)
     escreva("Qual o valor Percentual da gorjeta: ")
     leia(percentualGorjeta)
     
     gorjeta <- valorConsumido * (percentualGorjeta / 100)
     subTotal <- valorConsumido + gorjeta
     total <- subTotal - descontoReais
     escreval("O valor final da conta é ",total, " R$")

Fimalgoritmo
