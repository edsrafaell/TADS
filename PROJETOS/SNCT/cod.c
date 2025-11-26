#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/* ================== CONFIG ================== */
#define W 120

/* ================== CORES ANSI ================== */
#define COR_VERDE "\033[1;92m"
#define COR_RESET "\033[0m"  

/* ================== CP437 (BOX DRAWING) LINHAS FINAS ================== */
#define TL 218 // ┌
#define TR 191 // ┐
#define BL 192 // └
#define BR 217 // ┘
#define H 196  // ─
#define V 179  // │ 
#define L 195  // ├
#define R 180  // ┤
#define FILL ' '

/* ============ VISUAL CONFIG ============ */
static void cls(void){ system("cls"); }
static void theme(void){ system("color 0B"); }
static void cp437(void){
    SetConsoleOutputCP(437);
    SetConsoleCP(437);
    system("chcp 437 >nul");
}
static void mode_120x28(void){ system("mode con cols=120 lines=28"); }

/* ================== MOLDURA ================== */
void linhaTopo(){ putchar(TL); for(int i=0;i<W-2;i++) putchar(H); putchar(TR); putchar('\n'); }
void linhaRodape(){ putchar(BL); for(int i=0;i<W-2;i++) putchar(H); putchar(BR); putchar('\n'); }
void linhaDiv(){ putchar(L); for(int i=0;i<W-2;i++) putchar(H); putchar(R); putchar('\n'); }
void linhaVazia(){ putchar(V); for(int i=0;i<W-2;i++) putchar(FILL); putchar(V); putchar('\n'); }

void linhaCentro(const char* texto){
    int len=(int)strlen(texto);
    int esp=(W-2-len); if(esp<0) esp=0;
    int left=esp/2, right=esp-left;
    putchar(V);
    for(int i=0;i<left;i++) putchar(FILL);
    fputs(texto, stdout);
    for(int i=0;i<right;i++) putchar(FILL);
    putchar(V); putchar('\n');
}

void linhaPromptCentro(const char* texto, SHORT* px, SHORT* py){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO s; GetConsoleScreenBufferInfo(h,&s);

    SHORT y = s.dwCursorPosition.Y;
    int len=(int)strlen(texto);
    int esp=(W-2-len); if(esp<0) esp=0;
    int left=esp/2, right=esp-left;

    putchar(V);
    for(int i=0;i<left;i++) putchar(FILL);
    fputs(texto, stdout);
    for(int i=0;i<right;i++) putchar(FILL);
    putchar(V); putchar('\n');

    if(px) *px = (SHORT)(1 + left + len);
    if(py) *py = y;
}

void aguardaEnterDentro(SHORT px, SHORT py){
    int ch; do { ch=getchar(); } while(ch!='\n' && ch!=EOF);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { px, py };
    SetConsoleCursorPosition(h, c);
    do { ch=getchar(); } while(ch!='\n' && ch!=EOF);
}

/* CABEÇALHO E RODAPÉ */
void janelaTitulo(const char* titulo){ linhaTopo(); linhaVazia(); linhaCentro(titulo); linhaVazia(); linhaDiv(); }
void janelaRodapePadrao(const char* rodape){ linhaDiv(); linhaCentro(rodape); linhaRodape(); }

/* ================== BARRA DE CARREGAMENTO ================== */
void barra_carregamento_visual() {
    const char *ascii_art[] = {
        " /$$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$",
        "| $$__  $$ /$$__  $$ /$$__  $$| $$  | $$",
        "| $$  \\ $$| $$  \\ $$| $$  \\__/| $$  | $$",
        "| $$  | $$| $$$$$$$$|  $$$$$$ | $$$$$$$$",
        "| $$  | $$| $$__  $$ \\____  $$| $$__  $$",
        "| $$  | $$| $$  | $$ /$$  \\ $$| $$  | $$",
        "| $$$$$$$/| $$  | $$|  $$$$$$/| $$  | $$",
        "|_______/ |__/  |__/ \\______/ |__/  |__/ "
    };

    int largura = 60;
    for (int p = 0; p <= largura; p++) {
        cls();
        printf("\n\n\n");
        for (int j = 0; j < 8; j++) printf("   %s\n", ascii_art[j]);
        printf("\n\n");

        printf("                          [");
        for (int i = 0; i < largura; i++) {
            if (i < p) printf("%c", 219);
            else printf(" ");
        }
        printf("]  %3d%%", (p * 100) / largura);
        fflush(stdout);
        Sleep(20);
    }
    Sleep(400);
    cls();
}

/* ================== TELAS ================== */
void telaPrincipal(){
    theme(); cls();
    linhaTopo(); 
    linhaVazia();

    linhaCentro(" /$$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$");
    linhaCentro("| $$__  $$ /$$__  $$ /$$__  $$| $$  | $$");
    linhaCentro("| $$  \\ $$| $$  \\ $$| $$  \\__/| $$  | $$");
    linhaCentro("| $$  | $$| $$$$$$$$|  $$$$$$ | $$$$$$$$");
    linhaCentro("| $$  | $$| $$__  $$ \\____  $$| $$__  $$");
    linhaCentro("| $$  | $$| $$  | $$ /$$  \\ $$| $$  | $$");
    linhaCentro("| $$$$$$$/| $$  | $$|  $$$$$$/| $$  | $$");
    linhaCentro("|_______/ |__/  |__/ \\______/ |__/  |__/ ");
    linhaVazia();
    linhaDiv();

    linhaVazia();
    linhaCentro("D.A.S.H. - Disciplina, Atencao, Saude e Habitos Digitais");
    linhaCentro("Ferramenta educativa para avaliar foco e autocontrole digital.");
    linhaCentro("Responda o teste e receba um feedback imediato.");
    linhaVazia();

    linhaDiv();
    linhaCentro("[1] INICIAR TESTE");
    linhaCentro("[2] SOBRE O SISTEMA");
    linhaCentro("[3] SAIR");
    linhaVazia();

    linhaDiv();
    SHORT px=0, py=0;
    linhaPromptCentro("DIGITE UMA OPCAO: ", &px, &py);
    linhaCentro("PRESSIONE ENTER");
    linhaRodape();

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { px, py }; 
    SetConsoleCursorPosition(h, c);
}

void telaSobre(){
    theme(); cls();
    janelaTitulo("SOBRE O D.A.S.H.");
    linhaVazia();
    linhaCentro("O sistema D.A.S.H. avalia habitos digitais e niveis de atencao.");
    linhaCentro("Projeto educativo nao substitui diagnostico medico.");
    linhaCentro("Objetivo: promover consciencia e equilibrio no uso da tecnologia.");
    linhaCentro("Desenvolvido por alunos de TADS - IFPI | 2025");
    linhaVazia();
    linhaDiv();
    SHORT px=0, py=0;
    linhaPromptCentro("PRESSIONE ENTER PARA VOLTAR...", &px, &py);
    linhaCentro(" ");
    linhaRodape();
    aguardaEnterDentro(px, py);
}

/* ================== PERGUNTAS ================== */
const char *perguntas[] = {
    "VOCE SE DISTRAI FACILMENTE COM NOTIFICACOES E REDES SOCIAIS?",
    "COSTUMA PROCRASTINAR TAREFAS IMPORTANTES POR ESTAR ONLINE?",
    "SENTE DIFICULDADE EM MANTER FOCO POR MAIS DE 30 MINUTOS?",
    "VERIFICA O CELULAR REPE TIDAMENTE SEM PERCEBER?",
    "PASSA MUITO TEMPO EM REDES SOCIAIS SEM UM PROPOSITO CLARO?",
    "TEM DIFICULDADE EM CONCLUIR TAREFAS SEM INTERRUPCOES DIGITAIS?",
    "SENTE ANSIEDADE QUANDO FICA LONGE DO CELULAR POR UM TEMPO?",
    "USA O CELULAR MESMO DURANTE REFEICOES OU CONVERSAS PRESENCIAIS?",
    "CONSEGUE DORMIR BEM OU O USO DO CELULAR ATRAPALHA SEU SONO?",
    "JA TENTOU REDUZIR O TEMPO DE TELA E NAO CONSEGUIU MANTER?"
};

/* ================== TESTE ================== */
void aplicarTesteAtencao(){
    int respostas[10];
    int total = 0;
    int num_perguntas = 10;

    for(int i=0;i<num_perguntas;i++){
        theme(); cls();
        char titulo[64]; snprintf(titulo,sizeof(titulo),"PERGUNTA %d DE %d", i+1, num_perguntas);
        janelaTitulo(titulo);
        linhaVazia(); linhaCentro(perguntas[i]); linhaVazia();
        linhaCentro("1 = NUNCA   |   2 = AS VEZES   |   3 = FREQUENTEMENTE   |   4 = SEMPRE");
        linhaDiv();
        SHORT px=0, py=0;
        linhaPromptCentro("SUA RESPOSTA (1-4): ", &px, &py);
        linhaRodape();

        HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD c={px,py}; SetConsoleCursorPosition(h,c);
        scanf("%d",&respostas[i]);
        if(respostas[i]<1||respostas[i]>4){
            i--;
        } else total += respostas[i];
    }

    theme(); cls();
    janelaTitulo("RESULTADO");
    linhaVazia();

    /* ================== DIAGNOSTICO MELHORADO ================== */
    if(total <= 15){
        linhaCentro("NIVEL: EXCELENTE");
        linhaCentro("Parabens! Sem sinais de deficit de atencao digital.");
    }
    else if(total <= 24){
        linhaCentro("NIVEL: LEVE");
        linhaCentro("Alguns sinais de distracao, mas ainda sob controle.");
    }
    else if(total <= 32){
        linhaCentro("NIVEL: MODERADO");
        linhaCentro("Dificuldade perceptivel em manter foco.");
        linhaCentro("Reduza estimulos digitais e organize rotinas.");
    }
    else if(total <= 36){
        linhaCentro("NIVEL: ALTO");
        linhaCentro("Sinais fortes de dispersao e dependencia digital.");
        linhaCentro("Recomendado praticar pausas e limitar notificacoes.");
    }
    else{
        linhaCentro("NIVEL: GRAVE");
        linhaCentro("Possivel deficit de atencao digital.");
        linhaCentro("Considere buscar orientacao profissional.");
    }

    linhaVazia();
    linhaDiv();
    SHORT px=0, py=0;
    linhaPromptCentro("PRESSIONE ENTER PARA VOLTAR AO MENU...", &px, &py);
    linhaCentro(" ");
    linhaRodape();
    aguardaEnterDentro(px, py);
}

/* ================== FINALIZACAO ================== */
void finalizarAuto(){
    theme(); cls(); mode_120x28();
    janelaTitulo("ENCERRANDO D.A.S.H.");
    linhaVazia(); linhaCentro("Obrigado por utilizar o sistema."); linhaVazia();
    linhaRodape();
    barra_carregamento_visual();
}

/* ================== MAIN ================== */
int main(){
    cp437(); theme(); mode_120x28();
    barra_carregamento_visual();

    int op=0;
    do{
        telaPrincipal();
        if(scanf("%d",&op)!=1){ fflush(stdin); op=0; }
        if(op==1) aplicarTesteAtencao();
        else if(op==2) telaSobre();
        else if(op!=3){
            theme(); cls();
            janelaTitulo("AVISO");
            linhaVazia(); linhaCentro("OPCAO INVALIDA. TENTE NOVAMENTE."); linhaVazia();
            linhaRodape();
            int ch; do { ch=getchar(); } while(ch!='\n' && ch!=EOF);
        }
    }while(op!=3);

    finalizarAuto();
    return 0;
}
