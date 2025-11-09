Algoritmo "exercício02"
Var
   prestacao, valor, taxa, periodo: Real
   
Inicio
     escreval("Digite o valor da prestação atrazada: ")
     leia(valor)
     escreval("Digite o valor da taxa: ")
     leia(taxa)
     escreval("Digite o tempo de atraso: ")
     leia(periodo)
     
     prestacao <- valor +(valor *(taxa/100) * periodo)
     escreval("O valor da prestação atrazada que era ", valor," ficou de ", prestacao, " com a taxa de atrazo")

Fimalgoritmo