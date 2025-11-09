Algoritmo "EXERCICIO 07"
Var
   juros, valorFinal, parcelas, valorEmprestimo, numeroParcelas, taxaJurosMensal : real

Inicio
     escreval("==============================")
     escreval(" CALCULAR PARCELAS EMPRESTIMO ")
     escreval("==============================")
     escreva("Qual o valor do emprestimo: ")
     leia(valorEmprestimo)
     escreva("Numero de parcelas: ")
     leia(numeroParcelas)
     escreva("Qual taxa de juros: ")
     leia(taxaJurosMensal)
     
     juros <- valorEmprestimo * (taxaJurosMensal / 100) * numeroParcelas
     valorFinal <- valorEmprestimo + juros
     parcelas <- valorFinal / numeroParcelas
     escreval("Valor de cada parcela vai ser de ", parcelas, "R$")

Fimalgoritmo
