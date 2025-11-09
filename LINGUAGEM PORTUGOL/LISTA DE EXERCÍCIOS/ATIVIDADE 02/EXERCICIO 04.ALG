Algoritmo "EXERCICIO 04"
Var
   valorBrutoUSD, IOF, valorLiquidoUSD, valorReais, cotacaoDolar, taxaIOF : real

Inicio
     escreval("============================")
     escreval("  CALCULAR REAL PRA DOLLAR  ")
     escreval("============================")
     escreva("Qual valor: ")
     leia(valorReais)
     escreva("Valor da cotação em dolar: ")
     leia(cotacaoDolar)
     escreva("Valor da taxa do IOF: ")
     leia(taxaIOF)
     
     valorBrutoUSD <- valorReais / cotacaoDolar
     IOF <- valorBrutoUSD * (taxaIOF / 100)
     valorLiquidoUSD <- valorBrutoUSD - IOF
     escreval(valorReais, " é equivalente a ", valorLiquidoUSD, " Dolares")

Fimalgoritmo
