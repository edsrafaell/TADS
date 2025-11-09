Algoritmo "exercício 20"
Var
   valorFinal, precoProduto, lucro: real

Inicio
     escreval("===============================")
     escreval("   CALCULAR LUCRO DO PRODUTO   ")
     escreval("===============================")

     escreva("Qual o valor do produto: ")
     leia(precoProduto)
     escreva("Qual porcentagem de lucro: ")
     leia(lucro)

     
     valorFinal <-  precoProduto + (precoProduto * (lucro/100))
     escreva("O preço final do produto é  ", valorFinal)

Fimalgoritmo