#include <stdio.h>

int main() {
    int MatrizTabuleiro[10][10];

    //Tabuleiro Iniciado
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            MatrizTabuleiro[i][j] = 0;
        }
    }

    // Navio 1 - Horizontal
    int navio_horizontal_linha = 1;
    int navio_horizontal_coluna = 1;
    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 1;
    }

    // Navio 2 - Vertical
    int navio_vertical_linha = 3;
    int navio_vertical_coluna = 4;
    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 1;
    }

    // Navio 3 Diagonal
    int navio_diag1_linha = 0;
    int navio_diag1_coluna = 6;
    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_diag1_linha + i][navio_diag1_coluna + i] = 1;
    }

    // Navio 4 Diagonal 
    int navio_diag2_linha = 7;
    int navio_diag2_coluna = 2;
    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_diag2_linha + i][navio_diag2_coluna - i] = 1;
    }

    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", MatrizTabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
