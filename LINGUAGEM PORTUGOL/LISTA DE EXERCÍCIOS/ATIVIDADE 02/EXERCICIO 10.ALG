Algoritmo "EXERCICIO 10"
Var
   tempoTeorico, tempoTotal, qtdePausas, tempoPausas, distanciaKm, velocidadeMediaKmH, intervaloEntrePausasHoras, duracaoPausaMin : real

Inicio
     escreval("========================")
     escreval(" TEMPO TOTAL DA VIAGEM  ")
     escreval("========================")
     escreva("Qual a distância:    ")
     leia(distanciaKm)
     escreva("Qual a velocidade média : ")
     leia(velocidadeMediaKmH)
     escreva("Qual foi o intervalo entre as pausas: ")
     leia(intervaloEntrePausasHoras)
     escreva("Duracao das pausas em minutos: ")
     leia(duracaoPausaMin)

     tempoTeorico <- distanciaKm / velocidadeMediaKmH
     qtdePausas <- tempoTeorico / intervaloEntrePausasHoras
     tempoPausas <- qtdePausas * ( duracaoPausaMin / 60)
     tempoTotal <- tempoTeorico + tempoPausas
     
     escreval("O tempo total da viagem é ",tempoTotal," horas")

Fimalgoritmo
