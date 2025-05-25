#include <math.h>
#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

// Constantes para valores no tabuleiro
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Inicializa tabuleiro com zeros
void inicializaTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for(int i=0; i<TAM_TABULEIRO; i++)
        for(int j=0; j<TAM_TABULEIRO; j++)
            tabuleiro[i][j] = AGUA;
}

// Função para posicionar navio horizontal (exemplo)
void posicionaNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for(int i=0; i<TAM_NAVIO; i++) {
        tabuleiro[linha][coluna+i] = NAVIO;
    }
}

// Função para posicionar navio vertical (exemplo)
void posicionaNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for(int i=0; i<TAM_NAVIO; i++) {
        tabuleiro[linha+i][coluna] = NAVIO;
    }
}

// Cria matriz cone (5x5), valor 1 nas posições que formam um cone "para baixo" com vértice no topo central
void criaMatrizCone(int cone[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // Limpa a matriz
    for(int i=0; i<TAM_HABILIDADE; i++)
        for(int j=0; j<TAM_HABILIDADE; j++)
            cone[i][j] = 0;

    // Construção dinâmica do cone:
    // Ponto topo é o centro da primeira linha
    int centro = TAM_HABILIDADE / 2;

    // Para cada linha i do cone
    for(int i=0; i<TAM_HABILIDADE; i++) {
        // Largura do cone na linha i: vai de centro - i até centro + i
        int inicio = centro - i;
        int fim = centro + i;
        if(inicio < 0) inicio = 0;
        if(fim >= TAM_HABILIDADE) fim = TAM_HABILIDADE - 1;

        for(int j=0; j<TAM_HABILIDADE; j++) {
            if(j >= inicio && j <= fim) {
                cone[i][j] = 1;
            }
        }
    }
}

// Cria matriz cruz (5x5), com 1 no centro da linha e coluna
void criaMatrizCruz(int cruz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for(int i=0; i<TAM_HABILIDADE; i++) {
        for(int j=0; j<TAM_HABILIDADE; j++) {
            // A cruz tem 1 na linha do centro e na coluna do centro
            if(i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Cria matriz octaedro (5x5) - losango com centro no meio
void criaMatrizOctaedro(int octaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for(int i=0; i<TAM_HABILIDADE; i++) {
        for(int j=0; j<TAM_HABILIDADE; j++) {
            // Distância Manhattan do centro
            int dist = abs(i - centro) + abs(j - centro);
            // Considera dentro do losango se dist ≤ centro
            if(dist <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Sobrepõe a matriz de habilidade ao tabuleiro centrando em (origemLinha, origemColuna)
void aplicaHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                      int origemLinha, int origemColuna) {
    int centro = TAM_HABILIDADE / 2;

    for(int i=0; i<TAM_HABILIDADE; i++) {
        for(int j=0; j<TAM_HABILIDADE; j++) {
            if(habilidade[i][j] == 1) {
                int tabLinha = origemLinha - centro + i;
                int tabColuna = origemColuna - centro + j;

                // Verifica limites do tabuleiro
                if(tabLinha >= 0 && tabLinha < TAM_TABULEIRO &&
                   tabColuna >= 0 && tabColuna < TAM_TABULEIRO) {

                    // Marca área afetada pela habilidade, somente se não for navio (3)
                    if(tabuleiro[tabLinha][tabColuna] != NAVIO) {
                        tabuleiro[tabLinha][tabColuna] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Imprime o tabuleiro com símbolos para facilitar visualização
void imprimeTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro (0=Agua, 3=Navio, 5=Habilidade):\n");
    for(int i=0; i<TAM_TABULEIRO; i++) {
        for(int j=0; j<TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializaTabuleiro(tabuleiro);

    // Posicionar alguns navios para exemplo
    posicionaNavioHorizontal(tabuleiro, 1, 2);  // horizontal em linha 1, coluna 2
    posicionaNavioVertical(tabuleiro, 4, 7);    // vertical em linha 4, coluna 7

    // Criar matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criaMatrizCone(cone);
    criaMatrizCruz(cruz);
    criaMatrizOctaedro(octaedro);

    // Definir pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 3, origemConeColuna = 3;
    int origemCruzLinha = 7, origemCruzColuna = 5;
    int origemOctaedroLinha = 5, origemOctaedroColuna = 8;

    // Aplicar as habilidades no tabuleiro
    aplicaHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicaHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicaHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    // Imprimir o tabuleiro final
    imprimeTabuleiro(tabuleiro);

    return 0;
}
