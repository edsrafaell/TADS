#include <stdio.h>
#include <locale.h>

int main()
{
     setlocale(LC_ALL, "portuguese");

    char nomeCliente[100];
    int tipoClient, tipoServico,tipoPacote, modalidade, profissionalExclu, atendimentoFeriado;
    int numSessoes, quantRef, nivelPersonalizacao;
    float valorSessao, precoPorRef, delivery;

    float custoBase = 0 , desccontoTipCliente = 0 , acrescimoTipPacote = 0 , acrescimoHoraEspecial = 0 ;
    float acrescimoPersonalizacaoCardapio = 0 , acrescimoFixoProfissionalexclu = 0, taxaDeslocamento = 0;
    float totalDesconto = 0, totalAcrescimo = 0, valorFinal = 0;

    printf("--------------------------------------------------------------------\n");
    printf("AGENDAMENTO DE SERVIÇOS DE ALIMENTAÇAO SAUDAVEL\n");
    printf("--------------------------------------------------------------------\n");

    printf("NOME CLIENTE: ");
    fgets(nomeCliente, 100, stdin);
    printf("TIPO CLIENTE [ 1. NOVO 2 .FLIDELIDADE 3. VIP]: ");
    scanf("%d", &tipoClient);
    printf("TIPO SERVICO [ 1. CONSULTA 2 .PLANO ALIMENTAR 3. ACOMPANHAMENTO]: ");
    scanf("%d", &tipoServico);
    printf("TIPO PACOTE[ 1. BASICO 2 .ESSENCIAL 3. PREMIUM]: ");
    scanf("%d", &tipoPacote);
    printf("MODALIDADE [ 1. CLINICA 2 .ONLINE 3. DOMICILIO/DELIVERY ]: ");
    scanf("%d", &modalidade);
    printf("ATENDIMENTO EM DOMINGO/FERIADO [ 1. SIM 2 .NAO ]: ");
    scanf("%d", &atendimentoFeriado);

    printf("--------------------------------------------\n");
    printf("-DADOS PARA CONSULTAS/ACOMPANHAMENTO/n");
    printf("--------------------------------------------\n");

    printf("NUMEROS DE SESSOES: ");
    scanf("%d", &numSessoes);
    printf("QUANTIDADE DE REFEICOES: ");
    scanf("%d", &quantRef);
    printf("NIVEL DE PERSONALIZACAO [ 1. PADRAO 2 .PERSONALIZADO]: ");
    scanf("%d", &nivelPersonalizacao);
    printf("TAXA FIXA DE DESLOCAMENTO/ ENTREGA : ");
    scanf("%f", &delivery);

    printf("--------------------------------------------\n");
    printf("@ 2025 - NUTRI SERVICE| TODOS OS DIREITOS RESERVADOS\n");
    printf("--------------------------------------------\n");

    //Questao 1 
    custoBase = (numSessoes * valorSessao) + (quantRef * precoPorRef);

    //Questao 2 
    float percentualDesconto = 0;

    if (tipoClient == 1 ){
        if(tipoServico == 1) percentualDesconto = 0; 
         else if(tipoServico == 2) percentualDesconto = 2; 
          if(tipoServico == 3) percentualDesconto = 4; 
     }else if (tipoClient == 2){
     if(tipoServico == 1) percentualDesconto = 4;
      else if(tipoServico == 2) percentualDesconto = 6;
        else if(tipoServico == 3) percentualDesconto = 8;
  } else if (tipoClient == 3){
     if(tipoServico == 1) percentualDesconto = 8;
      else if(tipoServico == 2) percentualDesconto = 10;
        else if(tipoServico == 3) percentualDesconto = 12;
 }
    acrescimoTipPacote = custoBase * (percentualDesconto / 100);

    //QUESTAO 3 
    if (tipoPacote == 1) acrescimoTipPacote = 0;
    else if (tipoPacote == 2) acrescimoTipPacote = custoBase =  0.8;
    else if (tipoPacote == 3 ) acrescimoTipPacote =  custoBase = 0.15;

    //QUESTAO 4 
    if(atendimentoFeriado == 1 ) acrescimoHoraEspecial = custoBase = 0.8;

    //QUESTAO 5 
    if (nivelPersonalizacao == 1) acrescimoPersonalizacaoCardapio = custoBase = 0.10;

    //QUESTAO 6 
    if(profissionalExclu ==  1 ) acrescimoFixoProfissionalexclu = 80.0;

    //QUESTAO 7 
    if(delivery == 1) 
    if(modalidade == 1)taxaDeslocamento = 0;
    else if (modalidade == 2) taxaDeslocamento = 0;
    else if (modalidade == 3 ) taxaDeslocamento = delivery;


    totalDesconto = desccontoTipCliente;
    totalAcrescimo = acrescimoTipPacote + acrescimoHoraEspecial + acrescimoPersonalizacaoCardapio + acrescimoFixoProfissionalexclu;
    
    valorFinal = custoBase + totalAcrescimo + taxaDeslocamento  - totalDesconto;


    printf("=============================================================\n");
    printf("RELATORIO FINAL\n");
    printf("=============================================================\n");
    printf("NOME CLIENTE : %s\n", nomeCliente);

    printf("--------------------------DESCONTOS APLICADOS----------------------------\n");
    printf("DESCONTO POR TIPO DE  CLIENTE: %2f\n", desccontoTipCliente);
    printf("TOTAL EM DESCONTOS: %2f\n", totalDesconto);
    printf("--------------------------ACRESCIMOS APLICADOS----------------------------\n");
    printf("ACRESCIMOS TIPO DE PACOTE: %d\n", acrescimoTipPacote);
    printf("ACRESCIMOS POR HORARIO ESPECIAL: %d\n", acrescimoHoraEspecial);
    printf("ACRESCIMOS POR PERSONALIZACAO: %d\n", acrescimoPersonalizacaoCardapio);
    printf("PROFISSIONAL EXCLUISIVA: %d\n", acrescimoFixoProfissionalexclu);
    printf("--------------------------TAXA DE SERVIÇO----------------------------\n");
    printf("TAXA DE DESLOCAMENTO: %2f\n", delivery);
    printf("TOTAL  DE TAXAS: %d\n", valorFinal);

    printf("--------------------------VALOR FINAL----------------------------\n");






    




return 0;
}