#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    
    //Variaveis de Entrada
    char nomeCliente[100]; 
    int sexo, tipoCliente, complexidade, pigmento, atendimento;
    float areaCorpo, valorBase, taxaBiossegurancaPercentual, taxaArtePercentual, impostoMunicipalPercentual, impostoEstadualPercentual, impostoFederalPercentual, descontoPromocionalPercentual, adiantamentoPercentual, multaCancelamentoPercentual, multaReagendamentoPercentual;

    // Variaveis de Saída
    float custoServico, acrescimoComplexidade, acrscimoArea, acrescimoMaterial, acrescimoAtendimento, subtotalAcrescimo, valorTaxaBiosseguranca, valorTaxaArte, subtotalTaxado, impostoMunicipal, impostoEstadual, impostoFederal, totalImposto, descontoTipoCliente, descontoPromocional, totalDescontoAplicados, valorAdiantamento, multaCancelamento, multaReagendamento, totalMultas, valorFinalProcedimento;

    //Entrada de Dados
    //Dados do cliente
    printf("\nDADOS DO CLIENTE");
    printf("\nQual o seu nome: ");
    scanf(" %[^\n]", nomeCliente);
    printf("Sexo [1] MASCULINO [2] FEMININO [3] OUTRO: ");
    scanf("%d", &sexo);
    printf("Tipo de Cliente [1] NOVO [2] FIEL [3] INDICADO [4] CORPORATIVO: ");
    scanf("%d", &tipoCliente);

    //Dados do Serviço
    printf("\nDETALHES DO SERVICO"); 
    printf("\nArea do Corpo cm2: ");
    scanf("%f", &areaCorpo);
    printf("Qual o nivel de Complexidade [1] BAIXA [2] MEDIA [3] ALTA: ");
    scanf("%d", &complexidade);
    printf("Qual o tipo de Pigmento/ Material [1] PADRAO [2] PREMIUM [3] HIPOALERGENICO: ");
    scanf("%d", &pigmento);
    printf("Qual o tipo de Atendimento [1] ESTUDIO [2] DOMICILIAR: ");
    scanf("%d", &atendimento);

    //Valores e Taxas
    printf("\nVALORES E TAXAS");
    printf("\nValor base R$: ");
    scanf("%f", &valorBase);
    printf("Percentual da Taxa de Biosseguranca: ");
    scanf("%f", &taxaBiossegurancaPercentual);
    printf("Percentual da Taxa de Arte: ");
    scanf("%f", &taxaArtePercentual);
    
    //Impostos
    printf("Percentual Imposto Federal: ");
    scanf("%f", &impostoFederalPercentual);
    printf("Percentual Imposto Estudal: ");
    scanf("%f", &impostoEstadualPercentual);printf("Percentual Imposto Municipal: ");
    scanf("%f", &impostoMunicipalPercentual);
    printf("Percentual de Desconto Promocional: ");
    scanf("%f", &descontoPromocionalPercentual);
    printf("Percentual de Adiantamento: ");
    scanf("%f", &adiantamentoPercentual);

    //ADIANTAMENTO
    printf("Qual o valor do adiantamento: ");
    scanf("%f", &valorAdiantamento);

    //Multas e Condições
    printf("\nMULTAS E TAXAS");
    printf("\nMulta por Cancelamento: ");
    scanf("%f", &multaCancelamentoPercentual);
    printf("Multa por Reagendamento: ");
    scanf("%f", &multaReagendamentoPercentual);

    //CALCULOS 
    custoServico = areaCorpo * valorBase;
    
    //QUESTÃO 3: Complexidade
    if (complexidade == 1) //Baixa
    {
        acrescimoComplexidade =  custoServico * 0.05;
    }else if (complexidade ==2)
    {
        acrescimoComplexidade =  custoServico * 0.15;
    }else if (complexidade == 3)
    {
        acrescimoAtendimento =  custoServico * 0.30;
    }else{
        printf("NIVEL DE COMPLEXIDADE INEXISTENTE!");
    }
    
    //QUESTÃO 4: ÁREA
    if (areaCorpo <= 50) 
    {
        acrscimoArea = custoServico;
    }else if (areaCorpo > 51 || areaCorpo <= 150) 
    {
        acrscimoArea =  custoServico * 0.05;
    }else if (areaCorpo > 151 || areaCorpo <= 300) 
    {
        acrscimoArea =  custoServico * 0.10;
    }else if (areaCorpo > 300) 
    {
        acrscimoArea =  custoServico * 0.15;
    }else{
        printf("FAIXA DE ARÉA IMPOSSIVEL!");
    }

    //QUESTÃO 5: Pigmento
    if (pigmento == 1) //Padrao
    {
        acrescimoMaterial = custoServico;
    }else if (pigmento == 1) //Padrao
    {
        acrescimoMaterial =  custoServico * 0.05;
    }else if (pigmento == 1) //Padrao
    {
        acrescimoMaterial =  custoServico * 0.10;
    }else{
        printf("TIPO DE PIGMENTO INEXISTENTE!");
    }

    //QUESTÃO 6: Tipo de Atendimento
    if (atendimento == 1) //estudio
    {
        acrescimoAtendimento = custoServico;
    }else if (atendimento == 2) //Domiciliar
    {
        acrescimoAtendimento =  150 + 10;
    }else{
        printf("OPCAO DE TIPO DE ATENDIMENTO INEXISTENTE!");
    }
    
    //QUESTÃO 7: Desconto Cliente
    if (tipoCliente == 1) //Novo
    {
        descontoTipoCliente = custoServico;
    }else if (tipoCliente == 2) //Fiel
    {
        descontoTipoCliente = custoServico - custoServico * 0.05;
    }else if (tipoCliente == 3) //Indicado
    {
        descontoTipoCliente = custoServico - custoServico * 0.08;
    }else if (tipoCliente == 4) //Corporativo
    {
        descontoTipoCliente = custoServico - custoServico * 0.10;
    }else{
        printf("TIPO DE CLIENTE INEXISTENTE!");
    }
    //QUESTÃO 8: PROMOCIONAL
    descontoPromocional = custoServico * (descontoPromocionalPercentual / 100);

    //QUESTÃO 9: Taxas
    valorTaxaBiosseguranca =   custoServico * (taxaBiossegurancaPercentual / 100);
    valorTaxaArte =  custoServico * (taxaArtePercentual / 100);

    //QUESTÃO 10: Imposto
    impostoMunicipal =  custoServico * (impostoMunicipalPercentual / 100);
    impostoEstadual =  custoServico * (impostoEstadualPercentual / 100);
    impostoFederal =  custoServico *(impostoFederalPercentual / 100);

    //QUESTÃO 11: Multas
    multaCancelamento =  custoServico * (multaCancelamentoPercentual / 100);
    multaReagendamento =  custoServico * (multaReagendamentoPercentual / 100);   
    
    //QUESTÃO 12 : VALOR FINAL
    //ACRESCIMOS
    subtotalAcrescimo = acrescimoComplexidade + acrscimoArea + acrescimoMaterial + acrescimoAtendimento;
    subtotalTaxado = valorTaxaArte + valorTaxaBiosseguranca;
    totalImposto = impostoEstadual + impostoFederal + impostoMunicipal;
    totalDescontoAplicados = descontoPromocional + descontoTipoCliente + valorAdiantamento; 
    totalMultas = multaCancelamento + multaReagendamento;

    valorFinalProcedimento = custoServico + subtotalAcrescimo + subtotalTaxado + totalImposto + totalMultas - totalDescontoAplicados;


    //Comprovante Final
    printf("\n=======================================================================");
    printf("\n                            RELATORIO FINAL                            ");
    printf("\n=======================================================================");
    printf("\n   DADOS DO CLIENTE");
    printf("\nNOME CLIENTE : %s", nomeCliente);
    printf("\nTIPO DE CLIENTE: %d", tipoCliente);
    
    printf("\n   DETALHES DO SERVICO");
    printf("\nAREA DO CORPO: %f", areaCorpo);
    printf("\nCOMPLEXIDADE: %d", complexidade);
    printf("\nMATERIAL / PIGMENTO: %d", pigmento);
    printf("\n=======================================================================");
    printf("\n   VALORES E ACRESCIMOS");
    printf("\nVALOR BASE:                                              R$:%f",valorBase);
    printf("\nCUSTO DO SERVICO:                                        R$:%f",custoServico);
    printf("\nACRESCIMO COMPLEXIDADE:                                  R$:%f",acrescimoComplexidade);
    printf("\nACRESCIMO AREA:                                          R$:%f",acrscimoArea);
    printf("\nACRESCIMO MATERIAL/CORES:                                R$:%f",acrescimoMaterial);
    printf("\nACRESCIMO ATENDIMENTO:                                   R$:%f",acrescimoAtendimento);
    printf("\nTAXA BIOSSEGURANCA:                                      R$:%f",valorTaxaBiosseguranca);
    printf("\nTAXA DE ARTE/DESENHO:                                    R$:%f",valorTaxaArte);
    printf("\nTOTAL ACRESCIMOS:                                        R$:%f",subtotalAcrescimo);
    printf("\n=======================================================================");
    printf("\n   DESCONTOS APLICADOS");
    printf("\nDESCONTO CLIENTE:                                        R$:%f",descontoTipoCliente);
    printf("\nDESCONTO PROMOCIONAL:                                    R$:%f",descontoPromocional);
    printf("\nTOTAL DESCONTO:                                          R$:%f",totalDescontoAplicados);
    printf("\n=======================================================================");
    printf("\n=======================================================================");
    printf("\n=======================================================================");
    printf("\n   IMPOSTOS E MULTAS");
    printf("\nIMPOSTO MUNICIPAL:                                       R$:%f",impostoMunicipal);
    printf("\nIMPOSTO ESTADUAL:                                        R$:%f",impostoEstadual);
    printf("\nIMPOSTO FEDERAL:                                         R$:%f",impostoFederal);
    printf("\nMULTA POR CANCELAMENTO:                                  R$:%f",multaCancelamento);
    printf("\nMULTA POR REAGENDAMENTO:                                 R$:%f",multaReagendamento);
    printf("\nTOTAL TAXAS/MULTAS:                                      R$:%f",totalImposto + totalMultas);
    printf("\n=======================================================================");
    printf("\n   BALANCO FINAL");
    printf("\nTOTAL DOS ACRESCIMOS:                                    R$:%f",subtotalAcrescimo);
    printf("\nTOTAL IMPOSTOS E MULTAS:                                 R$:%f",totalImposto + totalMultas);
    printf("\nTOTAL DESCONTOS:                                         R$:%f",totalDescontoAplicados);
    printf("\nADIANTAMENTO:                                            R$:%f",valorAdiantamento);
    printf("\n=======================================================================");
    printf("\nVALOR FINAL DO PROCEDIMENTO                              R$:%f",valorFinalProcedimento);
    
    

    


}
