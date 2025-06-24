#include <stdio.h>

// Função recursiva para movimentação da Torre
void moverTorre(int casas, int direcao) {
    if (casas == 0) return;

    if (direcao == 1) {
        printf("Cima\n");
    } else if (direcao == 2) {
        printf("Baixo\n");
    } else if (direcao == 3) {
        printf("Esquerda\n");
    } else if (direcao == 4) {
        printf("Direita\n");
    }

    moverTorre(casas - 1, direcao);
}

// Função recursiva para movimentação diagonal do Bispo
void moverBispoRecursivo(int casas, int direcaoVertical, int direcaoHorizontal) {
    if (casas == 0) return;

    if (direcaoVertical == 1 && direcaoHorizontal == 1) {
        printf("Diagonal Superior Direita\n");
    } else if (direcaoVertical == 1 && direcaoHorizontal == -1) {
        printf("Diagonal Superior Esquerda\n");
    } else if (direcaoVertical == -1 && direcaoHorizontal == 1) {
        printf("Diagonal Inferior Direita\n");
    } else if (direcaoVertical == -1 && direcaoHorizontal == -1) {
        printf("Diagonal Inferior Esquerda\n");
    }

    moverBispoRecursivo(casas - 1, direcaoVertical, direcaoHorizontal);
}

// Bispo com loops aninhados (simula movimentos em todas as diagonais)
void moverBispoComLoops(int casas) {
    for (int vertical = -1; vertical <= 1; vertical += 2) {
        for (int horizontal = -1; horizontal <= 1; horizontal += 2) {
            printf("\nMovimento diagonal (vertical: %d, horizontal: %d):\n", vertical, horizontal);
            moverBispoRecursivo(casas, vertical, horizontal);
        }
    }
}

// Função recursiva para movimentação da Rainha
void moverRainha(int casas) {
    if (casas == 0) return;

    printf("Cima\n");
    printf("Direita\n");

    moverRainha(casas - 1);
}

// Movimento complexo do Cavalo (duas casas pra cima e uma pra direita)
void moverCavalo() {
    printf("\nMovimentos do Cavalo:\n");

    for (int vertical = 0; vertical < 8; vertical++) {
        for (int horizontal = 0; horizontal < 8; horizontal++) {
            // Simular o movimento: duas pra cima, uma pra direita
            int novoY = vertical - 2;
            int novoX = horizontal + 1;

            if (novoY >= 0 && novoX < 8) {
                printf("De (%d,%d) para (%d,%d): ", vertical, horizontal, novoY, novoX);
                printf("Duas pra Cima e uma pra Direita\n");
            }

            // Exemplo de uso de continue e break:
            if (horizontal == 3) {
                continue; // Pula pra próxima iteração do loop interno
            }

            if (vertical == 2 && horizontal == 2) {
                break; // Sai do loop interno se atingir essa posição
            }
        }
    }
}

int main() {
    int casasTorre = 3;
    int casasBispo = 2;
    int casasRainha = 2;

    printf("Movimentos da Torre:\n");
    moverTorre(casasTorre, 1);  // Torre subindo
    moverTorre(casasTorre, 4);  // Torre para direita

    printf("\nMovimentos do Bispo (com recursividade e loops aninhados):\n");
    moverBispoComLoops(casasBispo);

    printf("\nMovimentos da Rainha (Recursividade):\n");
    moverRainha(casasRainha);

    moverCavalo();  // Movimentos complexos do cavalo

    return 0;
}
