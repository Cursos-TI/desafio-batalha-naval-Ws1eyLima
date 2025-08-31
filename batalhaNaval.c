#include <stdio.h>

// ==================== NÍVEL NOVATO ====================
void nivelNovato() {
    int tabuleiro[5][5] = {0}; // 0 = posição vazia

    // Navio horizontal na linha 1
    for (int j = 0; j < 3; j++) {
        tabuleiro[1][j] = 3;  // 3 = navio
        printf("Navio horizontal: (%d, %d)\n", 1, j);
    }

    // Navio vertical na coluna 4
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][4] = 3;
        printf("Navio vertical: (%d, %d)\n", i, 4);
    }

    // Exibir tabuleiro final
    printf("\nTabuleiro Nível Novato:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ==================== NÍVEL AVENTUREIRO ====================
void nivelAventureiro() {
    int tabuleiro[10][10] = {0}; // Tabuleiro 10x10 inicializado com zeros

    // 1) Navio horizontal na linha 2
    for (int j = 0; j < 4; j++) tabuleiro[2][j] = 3;

    // 2) Navio vertical na coluna 7
    for (int i = 0; i < 4; i++) tabuleiro[i][7] = 3;

    // 3) Navio diagonal principal (↘)
    for (int i = 0; i < 4; i++) tabuleiro[5 + i][0 + i] = 3;

    // 4) Navio diagonal secundária (↙)
    for (int i = 0; i < 4; i++) tabuleiro[5 + i][7 - i] = 3;

    // Exibir tabuleiro final
    printf("\nTabuleiro Nível Aventureiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// ==================== NÍVEL MESTRE ====================
void imprimirMatriz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void nivelMestre() {
    int habilidade[5][5] = {0};

    // --- Cruz ---
    for (int i = 0; i < 5; i++) habilidade[i][2] = 1; // Coluna do meio
    for (int j = 0; j < 5; j++) habilidade[2][j] = 1; // Linha do meio

    printf("\nHabilidade em Cruz:\n");
    imprimirMatriz(habilidade);

    // Resetando a matriz
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = 0;

    // --- Cone ---
    habilidade[2][2] = 1;
    habilidade[3][1] = habilidade[3][2] = habilidade[3][3] = 1;
    habilidade[4][0] = habilidade[4][1] = habilidade[4][2] = habilidade[4][3] = habilidade[4][4] = 1;

    printf("\nHabilidade em Cone:\n");
    imprimirMatriz(habilidade);

    // Resetando a matriz
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = 0;

    // --- Octaedro ---
    habilidade[1][2] = 1;
    habilidade[2][1] = habilidade[2][2] = habilidade[2][3] = 1;
    habilidade[3][2] = 1;

    printf("\nHabilidade em Octaedro:\n");
    imprimirMatriz(habilidade);
}

// ==================== FUNÇÃO PRINCIPAL ====================
int main() {
    int opcao;
    printf("Escolha o nível: 1-Novato | 2-Aventureiro | 3-Mestre: ");
    scanf("%d", &opcao);

    if (opcao == 1) nivelNovato();
    else if (opcao == 2) nivelAventureiro();
    else if (opcao == 3) nivelMestre();
    else printf("Opção inválida.\n");

    return 0;
}
