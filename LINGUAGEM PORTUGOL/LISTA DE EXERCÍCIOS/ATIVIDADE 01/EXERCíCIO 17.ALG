Algoritmo "exercício 17"
Var
   valorFinal, valorEmprestimo, meses: real

Inicio
     escreval("===============================")
     escreval("     CALCULO DE EMPRESTIMO     ")
     escreval("===============================")

     escreva("Qual o valor do emprestimo: ")
     leia(valorEmprestimo)
     escreva("Quantos meses para pagar: ")
     leia(meses)

     
     valorFinal <- valorEmprestimo + ( valorEmprestimo * (meses*(5/100)))
     escreva("O valor final do emprestimo é  ", valorFinal)

Fimalgoritmo