Algoritmo "EXERCICIO 09"
Var
   subTotal, desconto, total, precoUnitario, quantidade, frete, descontoPercentual : real

Inicio
     escreval("========================")
     escreval(" CALCULAR COMPRA ONLINE ")
     escreval("========================")
     escreva("Valor do preço unitario:    ")
     leia(precoUnitario)
     escreva("Quantidade de produtos: ")
     leia(quantidade)
     escreva("Valor do desconto percentual: ")
     leia(descontoPercentual)
     escreva("Qual o valor do frete: ")
     leia(frete)
     
     subTotal <- precoUnitario * quantidade
     desconto <- subTotal * (descontoPercentual / 100)
     total <- subTotal + desconto + frete
     
     escreval("O valor total com frete e desconto é de ", total, "R$")

Fimalgoritmo
