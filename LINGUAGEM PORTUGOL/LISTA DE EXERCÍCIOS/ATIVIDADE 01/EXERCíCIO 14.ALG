Algoritmo "exercício 14"
Var
   diferenca, horarioUm, horarioDois, horaUm, horaDois, minutoUm, minutoDois: real

Inicio
     escreval("=============================")
     escreval(" CALCULAR HORARIO DIFERENTES ")
     escreval("=============================")

     escreval(" INFORMAÇÕES DO HORARIO INICIAL ")
     escreva("Digite a hora Inicial (00 a 24): ")
     leia(horaUm)
     escreva("Digite os minutos (00 a 60): ")
     leia(minutoUm)
     
     escreval(" INFORMAÇÕES DO HORARIO FINAL ")
     escreva("Digite a hora final(00 a 24): ")
     leia(horaDois)
     escreva("Digite os minutos (00 a 60): ")
     leia(minutoDois)

     
     horarioUm <- horaUm * 60 + minutoUm
     horarioDois <- horaDois * 60 + minutoDois
     diferenca <- horarioDois - horarioUm
     escreva("A diferença do horario é ", diferenca, " minutos")

Fimalgoritmo