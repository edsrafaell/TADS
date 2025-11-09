Algoritmo "EXERCICIO 03"
Var
   delta, valorA, valorB, valorC : real

Inicio
     escreval("================================")
     escreval(" CONTROLE DE INDICE DE POLUIÇÃO ")
     escreval("================================")
     escreva("Digite o valor do coeficiente A:    ")
     leia(valorA)
     escreva("Digite o valor do coeficiente B:    ")
     leia(valorB)
     escreva("Digite o valor do coeficiente C:    ")
     leia(valorC)
     
     delta <- valorB^2 - 4*valorA*valorC
     se (delta = 0) entao
        escreva("AS RAÍZES SÃO IGUAIS")
     senao
          se (delta > 0) entao
             escreva("HÁ DUAS RAÍZES REAIS DISTINTAS")
          senao
               se (delta < 0) entao
                  escreva("NÃO HÁ RAÍZES REAIS")
               fimse
          fimse
     fimse

Fimalgoritmo
