Algoritmo "exercício 10"
Var
   novoValor, valorDesconto, preco, desconto: real

Inicio
     escreval("============================")
     escreval(" CALCULAR DESCONTO DE PREÇO ")
     escreval("============================")

     escreva("Qual o preço do produto: ")
     leia(preco)
     escreva("Qual Valor do Percentual de Desconto: ")
     leia(desconto)

     novoValor  <- preco - (preco * (desconto/100))
     escreval("O novo valor do produto é de ", novoValor,"R$")

     valorDesconto <- novoValor - preco
     escreva("O valor do desconto é de ", desconto, "R$")
Fimalgoritmo