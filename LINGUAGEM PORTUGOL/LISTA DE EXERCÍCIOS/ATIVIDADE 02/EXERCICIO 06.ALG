Algoritmo "EXERCICIO 06"
Var
   litros, distanciaKM, consumoKmPorLitro, precoLitro, valorPedagio, custoTotal, custoCombustivel : real

Inicio
     escreval("============================")
     escreval("  CALCULAR CUSTO DE VIAGEM  ")
     escreval("============================")
     escreva("Qual a distância da viagem: ")
     leia(distanciaKM)
     escreva("Quanto que o veiculo consome por km: ")
     leia(consumoKmPorLitro)
     escreva("Preço do litro de combustivel: ")
     leia(precoLitro)
     escreva("Qual o valor do pedagio: ")
     leia(valorPedagio)
     
     litros <- distanciaKM / consumoKmPorLitro
     custoCombustivel <- litros * precoLitro
     custoTotal <- custoCombustivel + valorPedagio
     escreval("O custo total da viagem é de ", custoTotal, "R$")

Fimalgoritmo
