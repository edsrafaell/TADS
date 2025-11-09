Algoritmo "EXERCICIO 08"
Var
   quantidadeAjustada, porcoesBase, porcoesDesejadas, quantidadeOriginal : real

Inicio
     escreval("=================================")
     escreval(" QUANTIDADE INGREDIENTES RECEITA ")
     escreval("=================================")
     escreva("Porções de base (GRAMAS): ")
     leia(porcoesBase)
     escreva("Porções desejadas (GRAMAS): ")
     leia(porcoesDesejadas)
     escreva("Quala quantidade original (GRAMAS): ")
     leia(quantidadeOriginal)
     
     quantidadeAjustada <- quantidadeOriginal * (porcoesDesejadas / porcoesBase)
     escreval("A quantidade de porção ajustada é de ", quantidadeAjustada, " gramas")

Fimalgoritmo
