Algoritmo "EXERCICIO 1"
Var
   novoSalario, salarioAtual  : real

Inicio
     escreval("=============================")
     escreval(" CALCULAR AUMENTO DE SALARIO ")
     escreval("=============================")
     escreva("Qual o salário atual:    ")
     leia(salarioAtual)
     se(salarioAtual < 500) entao
          novoSalario <- salarioAtual + (salarioAtual*0.15)
     senao
          se (salarioAtual > 1000) entao
                novoSalario <- salarioAtual + (salarioAtual*0.05)
          senao
               se (salarioAtual >= 500) e ( salarioAtual <= 1000) entao
                  novoSalario <- salarioAtual +(salarioAtual * 0.10)
               fimse
          fimse
     fimse
     escreva("O novo salario é de ", novoSalario)


Fimalgoritmo
