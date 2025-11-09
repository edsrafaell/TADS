Algoritmo "EXERCICIO 05"
Var
   consumo, valorEnergia, total, leituraInicial, leituraFinal, tarifa, taxaIluminacao : real

Inicio
     escreval("============================")
     escreval("  CALCULAR CONTA DE ENERGIA ")
     escreval("============================")
     escreva("Valor da Leitura Inicial: ")
     leia(leituraInicial)
     escreva("Valor da Leitura Final: ")
     leia(leituraFinal)
     escreva("Valor da tarifa  KWH: ")
     leia(tarifa)
     escreva("Valor da taxa de  iluminação: ")
     leia(taxaIluminacao)
     
     consumo <- leituraFinal - leituraInicial
     valorEnergia <- consumo * tarifa
     total <- valorEnergia + taxaIluminacao
     escreval("Valor final da conta é ", total)

Fimalgoritmo
