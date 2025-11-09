Algoritmo "exercício 05"
Var
   distancia, litrosUsados, velocidade, periodo: real
   
Inicio
     escreval("============================")
     escreval(" CALCULAR COMBUSTIVEL GASTO ")
     escreval("============================")
     
     escreva("Qual Velocidade Média: ")
     leia(velocidade)
     escreva("Quanto Tempo de Viagem em Horas: ")
     leia(periodo)
     
     distancia <- periodo * velocidade
     escreval("A distancia percorrida é de ", distancia, "km")
     litrosUsados <- distancia / 16
     escreva("Na viajem foi gasto ",litrosUsados, " litros de combustivel")

Fimalgoritmo