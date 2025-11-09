Algoritmo "EXERCICIO 04"
Var
   salarioBruto, salarioBase, totalVendas : real
   cargo: caractere

Inicio
     escreval("================================")
     escreval(" CALCULAR SALARIO DE CADA FUNÇÃO ")
     escreval("================================")
     escreva("Qual o seu salário: ")
     leia(salarioBase)
     escreva("Qual o seu cargo: [GERENTE][VENDEDOR][SUPERVISOR] ")
     leia(cargo)
     escreva("Qual o valor total de vendas: ")
     leia(totalVendas)
     
     se (cargo = "VENDEDOR") entao
        salarioBruto <- (1.5 * salarioBase) + (0.5 * totalVendas)
        escreval(salarioBruto)

      senao se (cargo = "SUPERVISOR") entao
         salarioBruto <- (2 * salarioBase) + (0.5 * totalVendas)
         escreval(salarioBruto)

      senao se (cargo = "GERENTE") entao
         salarioBruto <- (4 * salarioBase) + (0.5 * totalVendas)
         escreval(salarioBruto)

      senao
         escreval("CARGO NÃO IDENTIFICADO")
      fimse

Fimalgoritmo
