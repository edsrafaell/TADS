#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao = 0;
    
    char nome[100] = "";
    int cargoCodigo = 0;
    char cargoNome[60] = "";
    double salarioMinimo = 0.0;
    int anosServico = 0;
    int dependentes = 0;

    double salarioBruto = 0.0;
    double impostos = 0.0;
    double aumentoTempoServico = 0.0;
    double auxilioAlimentacao = 0.0;
    double salarioLiquido = 0.0;

    // FLAGS DE CONTROLE DE FLUXO (0 =  ainda não fez a etapa / 1 = já fez a etapa)
    int flagCadastro = 0;
    int flagBruto = 0;
    int flagImpostos = 0;
    int flagAumento = 0;
    int flagGratificacao = 0;
    int flagAuxilio = 0;
    int flagLiquido = 0;

    while(opcao != 9){
        printf("\n--------------------------------------------------------\n");
        printf("\n-------------------- MENU DE OPCOES --------------------\n");
        printf("\n--------------------------------------------------------\n");
        printf("1. Cadastrar Funcionario\n");
        printf("2. Calcular Salario Bruto\n");
        printf("3. Calcular Impostos\n");
        printf("4. Calcular Aumento por Tempo de Servico\n");
        printf("5. Calcular Gratificacao por Cargo\n");
        printf("6. Calcular Auxilio Alimentacao\n");
        printf("7. Calcular Salario Liquido\n");
        printf("8. Relatorio do Funcionario\n");
        printf("9. Sair\n");
        printf("--------------------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        //sair
        if (opcao == 9) {
            system("cls");
            printf("Saindo do programa...\n");
            break;
        }

        //Validar menu
        if (opcao < 1 || opcao > 9) {
            system("cls");
            printf("Opcao invalida! Tente novamente.\n");
            continue;
    }
        //Chamar funcoes
        switch(opcao){
            case 1:
                system("cls");
                printf("CADASTRAR / ATUALIZAR FUNCIONARIO\n");
                printf("--------------------------------------------------------\n");
                printf("Informe o NOME DO FUNCIONARIO: ");
                scanf("%s", nome);
                printf("Informe o CARGO:\n"); 
                printf(" [1] Operado de Computador\n [2]Analista de Siste\n [3]Engenheiro de Software: ");
                scanf("%d", &cargoCodigo);
                printf("Informe o SALARIO MINIMO(R$): ");
                scanf("%lf", &salarioMinimo);
                printf("Informe o TEMPO DE SERVIÇO (anos): ");
                scanf("%d", &anosServico);
                printf("Informe a QUANTIDADE DE DEPENDETES: ");
                scanf("%d", &dependentes);
                
                if (cargoCodigo == 1)
                {
                    strcpy(cargoNome, "Operador de Computador");
                }
                else if (cargoCodigo == 2)
                {
                    strcpy(cargoNome, "Analista de Sistemas");
                }
                else if (cargoCodigo == 3)
                {
                    strcpy(cargoNome, "Engenheiro de Software");
                }
                else
                {
                    printf("Cargo invalido! Tente novamente.\n");
                }
                
                //Ao alterar dados base, zeramos resultados anteriores
                salarioBruto: 0.0;
                impostos: 0.0;
                aumentoTempoServico: 0.0;
                auxilioAlimentacao: 0.0;    
                salarioLiquido: 0.0;

                //Atualizar flags
                flagCadastro = 1;
                flagBruto = 0;
                flagImpostos = 0;
                flagAumento = 0;
                flagGratificacao = 0;
                flagAuxilio = 0;
                flagLiquido = 0;
                
                printf("\n Dados cadastrados com sucesso!\n");
                printf("Agora voce opde calcular o salario brutona opcao 2.\n");
                printf("Presione qualquer tecla para continuar...");
                break;
            case 2:
                //chamar funcao calcular salario bruto
                break;
            case 3:
                //chamar funcao calcular impostos
                break;
            case 4:
                //chamar funcao calcular aumento por tempo de servico
                break;
            case 5:
                //chamar funcao calcular gratificacao por cargo
                break;
            case 6:
                //chamar funcao calcular auxilio alimentacao
                break;
            case 7:
                //chamar funcao calcular salario liquido
                break;
            case 8:
                //chamar funcao relatorio do funcionario
                break;
    }
}
}