Algoritmo "exercício 08"
Var
   novoValor, valorAumento, preco, aumento: real
   
Inicio
     escreval("===========================")
     escreval(" CALCULAR AUMENTO DE PREÇO ")
     escreval("===========================")
     
     escreva("Qual o preço do produto: ")
     leia(preco)
     escreva("Qual Valor do Percentual de Aumento: ")
     leia(aumento)
     
     novoValor  <- preco + (preco * (aumento/100))
     escreval("o novo valor do produto é de ", novoValor,"R$")
     
     valorAumento <- novoValor - preco
     escreva("O valor do aumento é de ", aumento, "R$")
Fimalgoritmo