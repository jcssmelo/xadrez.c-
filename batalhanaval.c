#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0) e alguns navios (3)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }

    // Exemplo: adicionando navios fixos
    tabuleiro[2][2] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[7][7] = 3;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Cria matriz de habilidade em forma de Cone (expande para baixo)
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
            if (j >= (TAM_HABILIDADE / 2) - i && j <= (TAM_HABILIDADE / 2) + i && i <= TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Cria matriz de habilidade em forma de Cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Cria matriz de habilidade em forma de Octaedro (losango)
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = 0;
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1;
            }
        }
    }
}

// Aplica a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha + i - TAM_HABILIDADE / 2;
            int colunaTabuleiro = origemColuna + j - TAM_HABILIDADE / 2;

            // Verificar se está dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM_TABULEIRO) {

                if (habilidade[i][j] == 1) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Marca como área afetada
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    printf("Tabuleiro Inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Criar e aplicar Cone
    criarCone(cone);
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    printf("Tabuleiro após aplicar Habilidade - Cone:\n");
    exibirTabuleiro(tabuleiro);

    // Criar e aplicar Cruz
    criarCruz(cruz);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    printf("Tabuleiro após aplicar Habilidade - Cruz:\n");
    exibirTabuleiro(tabuleiro);

    // Criar e aplicar Octaedro
    criarOctaedro(octaedro);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);
    printf("Tabuleiro após aplicar Habilidade - Octaedro:\n");
    exibirTabuleiro(tabuleiro);
     
    printf ("new comitt /n");
    return 0;
}

