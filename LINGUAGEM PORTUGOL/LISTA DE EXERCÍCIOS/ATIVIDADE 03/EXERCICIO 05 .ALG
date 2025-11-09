Algoritmo "EXERCICIO 05 "
Var
   novaMedia, media, novaNota, nota1, nota2, nota3, nota4 : real

Inicio
     escreval("================================")
     escreval("    CALCULAR BOLETIM ESCOLAR    ")
     escreval("================================")
     escreva("Qual a nota 1: ")
     leia(nota1)
     escreva("Qual a nota 2: ")
     leia(nota2)
     escreva("Qual a nota 3: ")
     leia(nota3)
     escreva("Qual a nota 4: ")
     leia(nota4)
     
     media <- (nota1 + nota2 + nota3 + nota4) / 4
     se (media >= 7) entao
        escreva("APROVADO")
     senao
           escreva("Qual a nota da recuperação: ")
           leia(novaNota)
           novaMedia <- (novaNota + media) / 2
           escreval("Nova Média", novaMedia)
           se (media >= 5) entao
              escreva("APROVADO")
           senao
                escreva("NÃO ESTA APROVADO")
           fimse
     fimse
     
Fimalgoritmo
