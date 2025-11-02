#include <stdio.h>


int main() {
    int MatrizTabuleiro[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            MatrizTabuleiro[i][j] = 0;
        }
    }

    int navio_horizontal_linha = 1;
    int navio_horizontal_coluna = 1;

    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 1;
    }

    int navio_vertical_linha = 3;
    int navio_vertical_coluna = 4;

    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 1;
    }

    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", MatrizTabuleiro[i][j]);
        }
        printf(" \n");
    }
    return 0;
}
