Algoritmo "exercício 09"
Var
   idade, anoNascimento, anoAtual: real
   
Inicio
     escreval("===========================")
     escreval("      CALCULAR A IDADE     ")
     escreval("===========================")
     
     escreva("Qual seu ano de nascimento: ")
     leia(anoNascimento)
     escreva("Qual o ano atual: ")
     leia(anoAtual)
     
     idade <- anoAtual - anoNascimento
     escreval("Você tem ", idade, " anos")
     
Fimalgoritmo