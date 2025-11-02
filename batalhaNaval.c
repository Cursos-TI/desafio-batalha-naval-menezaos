#include <stdio.h>

void soltarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int origem_linha, int origem_coluna) {
    int tamanho_habilidade = 5;
    int centro_habilidade = tamanho_habilidade / 2;

    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            if (habilidade[i][j] == 1) {
                int linha_tabuleiro = origem_linha + i - centro_habilidade;
                int coluna_tabuleiro = origem_coluna + j - centro_habilidade;
                if (linha_tabuleiro >= 0 && linha_tabuleiro < 10 &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < 10) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
                }
            }
        }
    }
}

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
        MatrizTabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 3;
    }

    // Navio 2 - Vertical
    int navio_vertical_linha = 3;
    int navio_vertical_coluna = 4;
    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 3;
    }

    // Navio 3 Diagonal
    int navio_diag1_linha = 0;
    int navio_diag1_coluna = 6;
    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_diag1_linha + i][navio_diag1_coluna + i] = 3;
    }

    // Navio 4 Diagonal 
    int navio_diag2_linha = 7;
    int navio_diag2_coluna = 2;
    for (int i = 0; i < 3; i++) {
        MatrizTabuleiro[navio_diag2_linha + i][navio_diag2_coluna - i] = 3;
    }

    int habilidadeCone[5][5] = {0};
    int habilidadeCruz[5][5] = {0};
    int habilidadeOctaedro[5][5] = {0};
    int centro = 5 / 2; 

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Cone
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                habilidadeCone[i][j] = 1;
            }

            // Cruz
            if (i == centro || j == centro) {
                habilidadeCruz[i][j] = 1;
            }

            // Octaedro
            int dist = (i > centro ? i - centro : centro - i) + (j > centro ? j - centro : centro - j);
            if (dist <= centro) {
                habilidadeOctaedro[i][j] = 1;
            }
        }
    }


    // Habilidade em Cone com origem em (1, 7)
    soltarHabilidade(MatrizTabuleiro, habilidadeCone, 1, 7);

    // Habilidade em Cruz com origem em (7, 7)
    soltarHabilidade(MatrizTabuleiro, habilidadeCruz, 7, 7);

    // Habilidade em Octaedro com origem em (4, 1)
    soltarHabilidade(MatrizTabuleiro, habilidadeOctaedro, 4, 1);


    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", MatrizTabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
