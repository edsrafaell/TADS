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

    double salarioFinal = 0.0;
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
                printf("Informe o Nome do FUNCIONARIO: ");
                scanf("%s", nome);
                printf("Informe o Cargo:\n"); 
                printf("[1] Operado de Computador\n [2]Analista de Sistema:")
                scanf("%d", &cargoCodigo);
                printf("Nome do Cargo: ");
                scanf("%s", cargoNome);
                printf("Salario Minimo: ");
                scanf("%lf", &salarioMinimo);
                printf("Anos de Servico: ");
                scanf("%d", &anosServico);
                printf("Dependentes: ");
                scanf("%d", &dependentes);
                flagCadastro = 1;
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