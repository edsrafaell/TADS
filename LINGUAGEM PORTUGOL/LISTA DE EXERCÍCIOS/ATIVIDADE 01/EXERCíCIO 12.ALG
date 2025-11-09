Algoritmo "exercício 12"
Var
   consumoMensal, energiaEletrica, kwh: real

Inicio
     escreval("============================")
     escreval("     CONTA DE LUZ MENSAL    ")
     escreval("============================")

     escreva("Qual o consumo mensal de energia eltrica em KWH: ")
     leia(energiaEletrica)
     escreva("Qual valor do KWH: ")
     leia(kwh)
     
     consumoMensal <- energiaEletrica * kwh
     escreva("Valor da Conta de Luz: ",consumoMensal)

Fimalgoritmo