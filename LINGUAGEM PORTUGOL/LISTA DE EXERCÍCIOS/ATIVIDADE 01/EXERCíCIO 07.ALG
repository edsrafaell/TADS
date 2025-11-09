Algoritmo "exercício 07"
Var
   salarioLiquido, valorDesconto, salarioBruto, desconto: real
   
Inicio
     escreval("==========================")
     escreval(" CALCULAR SALÁRIO LIQUIDO ")
     escreval("==========================")
     
     escreva("Qual Valor do Salário Bruto: ")
     leia(salarioBruto)
     escreva("Qual Valor do Percentual de Desconto: ")
     leia(desconto)
     
     salarioLiquido  <- salarioBruto - (salarioBruto * (desconto/100))
     escreval("Salário liquido é no valor de ", salarioLiquido,"R$")
     
     valorDesconto <-  salarioBruto - salarioLiquido
     escreva("O valor do descoto é de ", valorDesconto, "R$")
Fimalgoritmo