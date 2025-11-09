Algoritmo "exercício 15"
Var
   novoPreco, precoOriginal: real

Inicio
     escreval("==============================")
     escreval(" PRODUTO COM AUMENTO DE VALOR ")
     escreval("==============================")

     escreva("Qual o peço original do produto: ")
     leia(precoOriginal)
     
     novoPreco <- precoOriginal + ( precoOriginal * (15/100))
     escreva("Preço do produto com aumento ficou por ", novoPreco)

Fimalgoritmo