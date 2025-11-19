#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/* ================== CONFIG ================== */
#define W   90
#define BANNER_TEXT "MINDTECH 2025"

/* ================== CP437 (BOX DRAWING) ================== */
#define BD_TL   201  /* + */
#define BD_TR   187  /* + */
#define BD_BL   200  /* + */
#define BD_BR   188  /* + */
#define BD_H    205  /* - */
#define BD_V    186  /* ¦ */
#define BD_L    204  /* ¦ */
#define BD_R    185  /* ¦ */
#define BD_FILL 219  /* ¦ */

/* Extras visuais para as janelas de teste */
#define SHADE1 176  /* ¦ */
#define SHADE2 177  /* ¦ */
#define SHADE3 178  /* ¦ */
#define BULLET 254  /* ¦ */
#define ARROW  175  /* » */

/* ---------- UTIL ---------- */
static void cls(void){ system("cls"); }
/* FUNDO PRETO (0), TEXTO VERDE CLARO (A)  -> “0A” */
static void theme(void){ system("color 0A"); }
static void cp437(void){
    SetConsoleOutputCP(437);
    SetConsoleCP(437);
    system("chcp 437 >nul");
}
static void mode_90x28(void){ system("mode con cols=90 lines=28"); }

/* ================== BANNER 5x5 ================== */
static const char *GLYPH_M[5] = { "10001","11011","10101","10001","10001" };
static const char *GLYPH_I[5] = { "11111","00100","00100","00100","11111" };
static const char *GLYPH_N[5] = { "10001","11001","10101","10011","10001" };
static const char *GLYPH_D[5] = { "11110","10001","10001","10001","11110" };
static const char *GLYPH_T[5] = { "11111","00100","00100","00100","00100" };
static const char *GLYPH_E[5] = { "11111","10000","11110","10000","11111" };
static const char *GLYPH_C[5] = { "01111","10000","10000","10000","01111" };
static const char *GLYPH_H[5] = { "10001","10001","11111","10001","10001" };
static const char *GLYPH_2[5] = { "11110","00001","11110","10000","11111" };
static const char *GLYPH_0[5] = { "01110","10001","10001","10001","01110" };
static const char *GLYPH_5[5] = { "11111","10000","11110","00001","11110" };
static const char *GLYPH_SPACE[5] = { "00000","00000","00000","00000","00000" };

static const char **getGlyph(char ch){
    switch(ch){
        case 'M': return GLYPH_M; case 'I': return GLYPH_I;
        case 'N': return GLYPH_N; case 'D': return GLYPH_D;
        case 'T': return GLYPH_T; case 'E': return GLYPH_E;
        case 'C': return GLYPH_C; case 'H': return GLYPH_H;
        case '2': return GLYPH_2; case '0': return GLYPH_0;
        case '5': return GLYPH_5; case ' ': default: return GLYPH_SPACE;
    }
}

static void imprimirBannerBoxed(const char *texto){
    int n = (int)strlen(texto);
    const int charW = 5, charH = 5, gap = 2;
    int totalW = n*charW + (n-1)*gap; if (totalW > (W-2)) totalW = W-2;

    for (int row=0; row<charH; row++){
        putchar(BD_V);
        int left = ((W-2) - totalW)/2; if(left<0) left=0;
        for(int i=0;i<left;i++) putchar(' ');

        int printed = 0;
        for (int t=0; t<n; t++){
            const char **g = getGlyph(texto[t]);
            const char *line = g[row];
            for (int col=0; col<charW && printed<totalW; col++){
                putchar(line[col]=='1' ? BD_FILL : ' ');
                printed++;
            }
            if (t != n-1){
                for (int s=0; s<gap && printed<totalW; s++){ putchar(' '); printed++; }
            }
        }
        int right = (W-2) - left - totalW; if(right<0) right=0;
        for(int i=0;i<right;i++) putchar(' ');
        putchar(BD_V); putchar('\n');
    }
}

/* ================== MOLDURA ================== */
void linhaTopo(){ putchar(BD_TL); for(int i=0;i<W-2;i++) putchar(BD_H); putchar(BD_TR); putchar('\n'); }
void linhaRodape(){ putchar(BD_BL); for(int i=0;i<W-2;i++) putchar(BD_H); putchar(BD_BR); putchar('\n'); }
void linhaDiv(){ putchar(BD_L); for(int i=0;i<W-2;i++) putchar(BD_H); putchar(BD_R); putchar('\n'); }
void linhaVazia(){ putchar(BD_V); for(int i=0;i<W-2;i++) putchar(' '); putchar(BD_V); putchar('\n'); }
void linhaCentro(const char* texto){
    int len=(int)strlen(texto); int esp=(W-2-len); if(esp<0) esp=0;
    int left=esp/2, right=esp-left;
    putchar(BD_V); for(int i=0;i<left;i++) putchar(' ');
    fputs(texto, stdout);
    for(int i=0;i<right;i++) putchar(' ');
    putchar(BD_V); putchar('\n');
}

/* ========= PROMPT CENTRAL ========= */
void linhaPromptCentro(const char* texto, SHORT* px, SHORT* py){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO s; GetConsoleScreenBufferInfo(h,&s);

    SHORT y = s.dwCursorPosition.Y;
    int len=(int)strlen(texto); int esp=(W-2-len); if(esp<0) esp=0;
    int left=esp/2, right=esp-left;

    putchar(BD_V);
    for(int i=0;i<left;i++) putchar(' ');
    fputs(texto, stdout);
    for(int i=0;i<right;i++) putchar(' ');
    putchar(BD_V); putchar('\n');

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

/* CABEÇALHO / RODAPÉ PADRÃO */
void janelaTitulo(const char* titulo){ linhaTopo(); linhaVazia(); linhaCentro(titulo); linhaVazia(); linhaDiv(); }
void janelaRodapePadrao(const char* rodape){ linhaDiv(); linhaCentro(rodape); linhaRodape(); }

/* ================== SPLASH ================== */
void splash(){
    mode_90x28(); cls(); theme();

    linhaTopo(); linhaVazia();
    imprimirBannerBoxed(BANNER_TEXT);
    linhaVazia(); linhaCentro("AUTODIAGNOSTICO DE BURNOUT ESTUDANTIL - OUT/2025");
    linhaVazia();
    linhaCentro("DESENVOLVIDO POR ESTUDANTES DE TADS - IFPI CAMPUS FLORIANO");
    linhaCentro("ORIENTACAO: PROFA. ELANE CRISTINA");
    linhaVazia(); linhaDiv();

    linhaVazia(); linhaCentro("INICIALIZANDO MODULOS DO SISTEMA..."); linhaVazia();

    int barraW = W - 2 - 20; if(barraW < 20) barraW = 20;
    putchar(BD_V); for(int i=0;i<10;i++) putchar(' ');
    putchar('['); for(int i=0;i<barraW-2;i++) putchar(' '); putchar(']');
    for(int i=0;i<10;i++) putchar(' '); putchar(BD_V); putchar('\n');

    linhaVazia(); linhaDiv();
    linhaCentro("DICA: ESTA SIMULACAO NAO SUBSTITUI AVALIACAO PROFISSIONAL.");
    linhaRodape();

    int util = barraW-2;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO s; GetConsoleScreenBufferInfo(h,&s);
    SHORT baseY = s.dwCursorPosition.Y, barraY = baseY - 6, infoY  = barraY + 1;
    const char* fases[] = {
        "INICIALIZANDO MODULOS","VERIFICANDO INTEGRIDADE","CARREGANDO RECURSOS",
        "AJUSTANDO INTERFACE","OTIMIZANDO DESEMPENHO","PREPARANDO QUESTIONARIO","CONCLUINDO"
    };
    int nfases = (int)(sizeof(fases)/sizeof(fases[0])), faseAtual = 0;

    for(int p=0;p<=100;p++){
        COORD c; c.X=0; c.Y=barraY; SetConsoleCursorPosition(h,c);
        putchar(BD_V); for(int i=0;i<10;i++) putchar(' ');
        putchar('['); int filled=(p*util)/100; for(int i=0;i<util;i++) putchar(i<filled?BD_FILL:' ');
        putchar(']'); for(int i=0;i<10;i++) putchar(' '); putchar(BD_V); putchar('\n');

        c.X=0; c.Y=infoY; SetConsoleCursorPosition(h,c);
        if (p >= ((faseAtual+1)*100)/nfases && faseAtual < nfases-1) faseAtual++;
        char msg[128]; snprintf(msg,sizeof(msg),"CARREGANDO %3d%% - %s", p, fases[faseAtual]);
        int len=(int)strlen(msg), esp=(W-2-len); if(esp<0) esp=0; int left=esp/2, right=esp-left;
        putchar(BD_V); for(int i=0;i<left;i++) putchar(' '); fputs(msg, stdout);
        for(int i=0;i<right;i++) putchar(' '); putchar(BD_V); putchar('\n');
        Sleep(18 + (p%7));
    }
    Sleep(250); cls();
}

/* ================== TELAS PADRÃO ================== */
void telaPrincipal(){
    theme(); cls();

    linhaTopo(); linhaVazia();
    imprimirBannerBoxed(BANNER_TEXT);
    linhaVazia(); linhaDiv();

    linhaVazia();
    linhaCentro("CALM-TECH: SISTEMA DIDATICO DE AUTODIAGNOSTICO DE BURNOUT ESTUDANTIL.");
    linhaCentro("OBJETIVO: PROMOVER CONSCIENCIA, AUTOAVALIACAO E HIGIENE DIGITAL.");
    linhaCentro("MODULOS: QUESTIONARIO LIKERT, CALCULO DO IEG, RELATORIO E SUGESTOES.");
    linhaCentro("PRIVACIDADE: NENHUM DADO E ARMAZENADO; USO EXCLUSIVO EM AULAS/FEIRAS.");
    linhaCentro("PARCERIA: TADS - IFPI CAMPUS FLORIANO | SNCT 2025.");
    linhaVazia();

    linhaDiv();
    linhaVazia();
    linhaCentro("[1] INICIAR (TESTE DE BURNOUT)");
    linhaCentro("[2] INSTRUCOES");
    linhaCentro("[3] SOBRE");
    linhaCentro("[4] SAIR");
    linhaVazia();

    linhaDiv();
    SHORT px=0, py=0;
    linhaPromptCentro("DIGITE UMA OPCAO: ", &px, &py);
    linhaCentro("PRESSIONE ENTER");
    linhaRodape();

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { px, py }; SetConsoleCursorPosition(h, c);
}

void telaInstrucoes(){
    theme(); cls();

    linhaTopo(); linhaVazia();
    imprimirBannerBoxed(BANNER_TEXT);
    linhaVazia(); linhaDiv();

    linhaVazia();
    linhaCentro("INSTRUCOES");
    linhaVazia();
    linhaCentro("RESPONDA AS QUESTOES USANDO ESCALA 0..4:");
    linhaCentro("0=NUNCA  1=RARAMENTE  2=AS VEZES  3=FREQUENTEMENTE  4=SEMPRE");
    linhaVazia();
    linhaCentro("USE PAUSAS DE 5 MINUTOS A CADA 25 DE ESTUDO (TECNICA POMODORO).");
    linhaCentro("DESATIVE NOTIFICACOES DURANTE AS TAREFAS E PRIORIZe SONO REGULAR.");
    linhaVazia();

    linhaDiv();
    SHORT px=0, py=0;
    linhaPromptCentro("PRESSIONE ENTER PARA VOLTAR...", &px, &py);
    linhaCentro(" ");
    linhaRodape();

    aguardaEnterDentro(px, py);
}

void telaSobre(){
    theme(); cls();

    linhaTopo(); linhaVazia();
    imprimirBannerBoxed(BANNER_TEXT);
    linhaVazia(); linhaDiv();

    linhaVazia();
    linhaCentro("SOBRE");
    linhaVazia();
    linhaCentro("PROJETO ACADEMICO SNCT 2025 - TADS/IFPI CAMPUS FLORIANO.");
    linhaCentro("SISTEMA EDUCACIONAL PARA REFLEXAO SOBRE SAUDE MENTAL ESTUDANTIL.");
    linhaCentro("BASEADO EM ESCALA LIKERT E INDICE DE EQUILIBRIO GNOSTICO (IEG).");
    linhaVazia();

    linhaDiv();
    SHORT px=0, py=0;
    linhaPromptCentro("PRESSIONE ENTER PARA VOLTAR...", &px, &py);
    linhaCentro(" ");
    linhaRodape();

    aguardaEnterDentro(px, py);
}

/* ========= PAINEL INTERNO ELEGANTE (USADO NAS PERGUNTAS) ========= */
static void painelTopo(int pw){
    int left=((W-2)-pw)/2; if(left<0) left=0;
    int right=(W-2)-pw-left; if(right<0) right=0;
    putchar(BD_V);
    for(int i=0;i<left;i++) putchar(' ');
    putchar(BD_TL); for(int i=0;i<pw-2;i++) putchar(BD_H); putchar(BD_TR);
    for(int i=0;i<right;i++) putchar(' ');
    putchar(BD_V); putchar('\n');
}
static void painelRodape(int pw){
    int left=((W-2)-pw)/2; if(left<0) left=0;
    int right=(W-2)-pw-left; if(right<0) right=0;
    putchar(BD_V);
    for(int i=0;i<left;i++) putchar(' ');
    putchar(BD_BL); for(int i=0;i<pw-2;i++) putchar(BD_H); putchar(BD_BR);
    for(int i=0;i<right;i++) putchar(' ');
    putchar(BD_V); putchar('\n');
}
static void painelLinhaCheia(int pw, int shade){
    int left=((W-2)-pw)/2; if(left<0) left=0;
    int right=(W-2)-pw-left; if(right<0) right=0;
    putchar(BD_V);
    for(int i=0;i<left;i++) putchar(' ');
    putchar(BD_V);
    for(int i=0;i<pw-2;i++) putchar(shade);
    putchar(BD_V);
    for(int i=0;i<right;i++) putchar(' ');
    putchar(BD_V); putchar('\n');
}
static void painelCentro(int pw, const char* txt){
    int left=((W-2)-pw)/2; if(left<0) left=0;
    int right=(W-2)-pw-left; if(right<0) right=0;
    int len=(int)strlen(txt);
    int innerLeft=(pw-2-len); if(innerLeft<0) innerLeft=0;
    int il=innerLeft/2, ir=innerLeft-il;

    putchar(BD_V);
    for(int i=0;i<left;i++) putchar(' ');
    putchar(BD_V);
    for(int i=0;i<il;i++) putchar(' ');
    fputs(txt, stdout);
    for(int i=0;i<ir;i++) putchar(' ');
    putchar(BD_V);
    for(int i=0;i<right;i++) putchar(' ');
    putchar(BD_V); putchar('\n');
}

/* ================== ENTRADA LIKERT (0..4) COM PAINEL ELEGANTE ================== */
int lerLikertJanela(const char* bloco, const char* pergunta){
    const int PW = 74; /* largura do painel interno */
    while (1){
        theme(); cls();

        janelaTitulo(bloco);

        /* Painel elegante */
        painelTopo(PW);
        painelLinhaCheia(PW, SHADE1);
        char title[96]; snprintf(title,sizeof(title)," %c %s %c", BULLET, "PERGUNTA", ARROW);
        painelCentro(PW, title);
        painelLinhaCheia(PW, SHADE3);
        painelCentro(PW, pergunta);
        painelCentro(PW, " ");
        painelCentro(PW, "0=NUNCA   1=RARAMENTE   2=AS VEZES   3=FREQUENTEMENTE   4=SEMPRE");
        painelLinhaCheia(PW, SHADE2);
        painelRodape(PW);

        linhaDiv();
        SHORT px=0, py=0;
        linhaPromptCentro("DIGITE UM VALOR DE 0 A 4: ", &px, &py);
        linhaCentro("PRESSIONE ENTER");
        linhaRodape();

        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD c = { px, py }; SetConsoleCursorPosition(h, c);

        int v = -1;
        if (scanf("%d", &v) == 1 && v >= 0 && v <= 4) return v;

        fflush(stdin);
        theme(); cls();
        janelaTitulo("AVISO");
        linhaVazia(); linhaCentro("VALOR INVALIDO. USE 0, 1, 2, 3 OU 4."); linhaVazia();
        janelaRodapePadrao("PRESSIONE ENTER PARA TENTAR NOVAMENTE");
        int ch; do { ch=getchar(); } while(ch!='\n' && ch!=EOF);
    }
}

/* ================== RESULTADO IEG ================== */
void telaResultadoIEG(float Ex,float De,float Re,float Fo,float Hu,float IEG){
    theme(); cls();
    janelaTitulo("RESULTADOS");

    char buf[110];
    linhaVazia(); snprintf(buf,sizeof(buf),"EXAUSTAO: %.1f/4 | DESPERSONALIZACAO: %.1f/4 | REALIZACAO: %.1f/4",Ex,De,Re); linhaCentro(buf);
    snprintf(buf,sizeof(buf),"FOCO: %.1f/4     | HUMOR: %.1f/4",Fo,Hu); linhaCentro(buf); linhaVazia();

    linhaDiv(); linhaVazia();
    snprintf(buf,sizeof(buf),"INDICE DE EQUILIBRIO GNOSTICO (IEG): %.1f / 100", IEG); linhaCentro(buf); linhaVazia();

    if (IEG >= 80.0f)        linhaCentro("* EQUILIBRIO ELEVADO - MENTE SAUDAVEL E PRODUTIVA.");
    else if (IEG >= 60.0f)   linhaCentro("* ATENCAO MODERADA - REVEJA HABITOS E HORARIOS.");
    else if (IEG >= 40.0f)   linhaCentro("* RISCO MODERADO - AJUSTE SUA ROTINA DE DESCANSO.");
    else                     linhaCentro("* RISCO ELEVADO - PROCURE APOIO EMOCIONAL E PEDAGOGICO.");

    linhaVazia(); linhaDiv();
    linhaCentro("SUGESTOES:");
    linhaCentro("- FACA PAUSAS DE 5 MINUTOS A CADA 25 DE ESTUDO.");
    linhaCentro("- EVITE TELAS A NOITE E MANTENHA SONO REGULAR.");
    linhaCentro("- CONVERSE COM COLEGAS E PROFESSORES QUANDO SOBRECARREGADO.");
    linhaVazia();

    linhaDiv();
    SHORT px=0, py=0;
    linhaPromptCentro("PRESSIONE ENTER PARA VOLTAR...", &px, &py);
    linhaCentro(" ");
    linhaRodape();

    aguardaEnterDentro(px, py);
}

/* ================== TESTE DE BURNOUT (IEG) ================== */
void aplicarTesteBurnout(){
    int e1=lerLikertJanela("BLOCO 1 - EXAUSTAO MENTAL","E1. SINTO-ME MENTALMENTE ESGOTADO(A) AO ESTUDAR.");
    int e2=lerLikertJanela("BLOCO 1 - EXAUSTAO MENTAL","E2. TENHO DIFICULDADE PARA RECUPERAR ENERGIA COGNITIVA.");
    int e3=lerLikertJanela("BLOCO 1 - EXAUSTAO MENTAL","E3. MEU SONO NAO RESTAURA MEU CANSACO MENTAL.");

    int d1=lerLikertJanela("BLOCO 2 - DESPERSONALIZACAO","D1. FICO INDIFERENTE AS ATIVIDADES ACADEMICAS.");
    int d2=lerLikertJanela("BLOCO 2 - DESPERSONALIZACAO","D2. EVITO CONTATO COM COLEGAS OU PROFESSORES.");

    int r1=lerLikertJanela("BLOCO 3 - REALIZACAO/PROPOSITO","R1. SINTO QUE APRENDO E EVOLUO ACADEMICAMENTE.");
    int r2=lerLikertJanela("BLOCO 3 - REALIZACAO/PROPOSITO","R2. ENCONTRO SENTIDO PESSOAL NO QUE ESTUDO.");
    int r3=lerLikertJanela("BLOCO 3 - REALIZACAO/PROPOSITO","R3. RECONHECO MINHAS PEQUENAS CONQUISTAS SEMANAIS.");

    int f1=lerLikertJanela("BLOCO 4 - FOCO/ATENCAO","F1. CONSIGO MANTER FOCO POR PELO MENOS 25 MINUTOS.");
    int f2=lerLikertJanela("BLOCO 4 - FOCO/ATENCAO","F2. DISTRAIO-ME FACILMENTE COM NOTIFICACOES.");

    int h1=lerLikertJanela("BLOCO 5 - HUMOR/EMOCOES","H1. MEU HUMOR TEM ESTADO PREDOMINANTEMENTE POSITIVO.");
    int h2=lerLikertJanela("BLOCO 5 - HUMOR/EMOCOES","H2. TENHO SENTIDO DESANIMO OU IRRITABILIDADE.");
    int h3=lerLikertJanela("BLOCO 5 - HUMOR/EMOCOES","H3. CONSIGO IDENTIFICAR E NOMEAR MINHAS EMOCOES.");

    float Ex=(e1+e2+e3)/3.0f, De=(d1+d2)/2.0f, Re=(r1+r2+r3)/3.0f, Fo=(f1+f2)/2.0f, Hu=(h1+h2+h3)/3.0f;

    float IEG = 100.0f - (0.45f*Ex*25.0f + 0.35f*De*25.0f
                        + 0.05f*(100.0f - Re*25.0f)
                        + 0.10f*(100.0f - Fo*25.0f)
                        + 0.05f*(100.0f - Hu*25.0f));
    if(IEG<0.0f) IEG=0.0f; if(IEG>100.0f) IEG=100.0f;

    telaResultadoIEG(Ex,De,Re,Fo,Hu,IEG);
}

/* ================== FINALIZACAO (AUTO-EXIT) ================== */
void finalizarAuto(){
    theme(); cls(); mode_90x28();

    janelaTitulo("ENCERRANDO");
    linhaVazia();
    linhaCentro("OBRIGADO POR USAR O SISTEMA. SALVANDO PREFERENCIAS E LIMPANDO MEMORIA...");
    linhaVazia();

    int barraW=W-2-20; if(barraW<20) barraW=20;
    putchar(BD_V); for(int i=0;i<10;i++) putchar(' ');
    putchar('['); for(int i=0;i<barraW-2;i++) putchar(' '); putchar(']');
    for(int i=0;i<10;i++) putchar(' '); putchar(BD_V); putchar('\n');

    linhaVazia(); linhaDiv();
    linhaCentro("FECHAMENTO AUTOMATICO AO FINAL DO CARREGAMENTO.");
    linhaRodape();

    int util=barraW-2;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO s; GetConsoleScreenBufferInfo(h,&s);
    SHORT baseY=s.dwCursorPosition.Y, barraY=baseY-6, infoY=barraY+1;

    const char* fases[]={"LIBERANDO RECURSOS","GRAVANDO CACHE","FINALIZANDO MODULOS",
                         "SINCRONIZANDO ESTADO","ENCERRANDO SUBSISTEMAS","CONCLUINDO"};
    int nfases=(int)(sizeof(fases)/sizeof(fases[0])), faseAtual=0;

    for(int p=0;p<=100;p++){
        COORD c; c.X=0; c.Y=barraY; SetConsoleCursorPosition(h,c);
        putchar(BD_V); for(int i=0;i<10;i++) putchar(' ');
        putchar('['); int filled=(p*util)/100; for(int i=0;i<util;i++) putchar(i<filled?BD_FILL:' ');
        putchar(']'); for(int i=0;i<10;i++) putchar(' '); putchar(BD_V); putchar('\n');

        c.X=0; c.Y=infoY; SetConsoleCursorPosition(h,c);
        if (p >= ((faseAtual+1)*100)/nfases && faseAtual < nfases-1) faseAtual++;
        char msg[128]; snprintf(msg,sizeof(msg),"ENCERRANDO %3d%% - %s", p, fases[faseAtual]);
        int len=(int)strlen(msg), esp=(W-2-len); if(esp<0) esp=0; int left=esp/2, right=esp-left;
        putchar(BD_V); for(int i=0;i<left;i++) putchar(' '); fputs(msg, stdout);
        for(int i=0;i<right;i++) putchar(' '); putchar(BD_V); putchar('\n');
        Sleep(20 + (p%9));
    }
    Sleep(350); cls();
}

/* ================== MAIN ================== */
int main(){
    cp437(); theme(); mode_90x28();

    splash();

    int op=0;
    do{
        telaPrincipal();
        if(scanf("%d",&op)!=1){ fflush(stdin); op=0; }

        if(op==1)      aplicarTesteBurnout();
        else if(op==2) telaInstrucoes();
        else if(op==3) telaSobre();
        else if(op!=4){
            theme(); cls();
            janelaTitulo("AVISO");
            linhaVazia(); linhaCentro("OPCAO INVALIDA. TENTE NOVAMENTE."); linhaVazia();
            linhaRodape();
            int ch; do { ch=getchar(); } while(ch!='\n' && ch!=EOF);
        }
    }while(op!=4);

    finalizarAuto();
    return 0;
}

