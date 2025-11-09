Algoritmo "EXERCICIO 02"
Var
   horaExtra, salarioFinal, salarioBase, quantidadeHE, valorHE, bonificacao, percentualBonificacao : real

Inicio
     escreval("============================")
     escreval("   CALCULAR SALARIO COM HR  ")
     escreval("============================")
     escreva("Qual o valor do seu salario :")
     leia(salarioBase)
     escreva("Quantas hora extra você fez: ")
     leia(quantidadeHE)
     escreva("Qual o valor da Hora extra: ")
     leia(valorHE)
     escreva("Qual o percentual por bonificação: ")
     leia(percentualBonificacao)
     horaExtra <- quantidadeHE * valorHE
     bonificacao <- salarioBase * (percentualBonificacao / 100)
     salarioFinal <- salarioBase + horaExtra + bonificacao
     escreval("O valor final do salario é ",salarioFinal, " R$")

Fimalgoritmo
