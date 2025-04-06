#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3

void tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    char line[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    printf(" TABULEIRO BATALHA NAVAL \n");
    printf("  ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", line[j]); // Imprime os números das colunas
    }
    printf("\n"); // Pula uma linha para começar a imprimir o tabuleiro
    
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Imprime os números das linhas começando em 1
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int naval_battle[10][10] = {AGUA}; // Inicializa o tabuleiro com 0 (água)
    
    // Inicializando os navios base com 3 (navio)
    for (int i = 4; i < 5; i++) {
        for (int j = 6; j < 9; j++) {
            if (i >= 0 && i < TAMANHO_TABULEIRO && j >= 0 && j < TAMANHO_TABULEIRO) {
                naval_battle[i][j] = NAVIO;
        } 
      }  
      
      for (int i = 8; i < 9; i++) {
        for (int j = 2; j < 5; j++) {
            if (i >= 0 && i < TAMANHO_TABULEIRO && j >= 0 && j < TAMANHO_TABULEIRO) {
              naval_battle[i][j] = NAVIO;
        } 
      }  

    for (int i = 0; i < 3; i++) {
        naval_battle[i][i] = NAVIO;
    }
    for (int i = 6; i < 9; i++) {
        naval_battle[i][i] = NAVIO;
    }
        
    // Áreas de habilidade
    int cone_column = 3;
    for (int i = cone_column - cone_column; i < cone_column; i++) {
        for (int j = cone_column - i; j <= cone_column + i; j++) {
            if (i >= 0 && i < TAMANHO_TABULEIRO && j >= 0 && j < TAMANHO_TABULEIRO) {
                if (naval_battle[i][j] == NAVIO) {
                    naval_battle[i][j] = 5; // Marca o navio atingido
                } else {
                    naval_battle[i][j] = 1; // Marca a área atingida
                }
            }
        }
    }

    int cruz_coluna = 5;
    for (int i = cruz_coluna; i < cruz_coluna + 4; i++) {
        if (i >= 0 && i < TAMANHO_TABULEIRO && cruz_coluna >= 0 && cruz_coluna < TAMANHO_TABULEIRO) {
            naval_battle[i][cruz_coluna] = 1;
        }
    }
    for (int x = cruz_coluna + 1; x == cruz_coluna + 1; x++) {
        for (int j = cruz_coluna - x + 4; j <= cruz_coluna + x - 4; j++) {
            if (j >= 0 && j < TAMANHO_TABULEIRO && x >= 0 && x < TAMANHO_TABULEIRO) {
                if (naval_battle[x][j] == NAVIO) {
                    naval_battle[x][j] = 5; // Marca o navio atingido
                } else {
                    naval_battle[x][j] = 1; // Marca a área atingida
                }
            }
        }
    }

    int octaedro_coluna = 8;
    for (int i = octaedro_coluna - 6; i < octaedro_coluna - 3; i++) {
        if (i >= 0 && i < TAMANHO_TABULEIRO && octaedro_coluna >= 0 && octaedro_coluna < TAMANHO_TABULEIRO) {
            naval_battle[i][octaedro_coluna] = 1;
        }
    }
    for (int x = octaedro_coluna - 5; x == octaedro_coluna - 5; x++) {
        for (int y = octaedro_coluna - 1; y <= octaedro_coluna + 1; y++) {
            if (y >= 0 && y < TAMANHO_TABULEIRO && x >= 0 && x < TAMANHO_TABULEIRO) {
                if (naval_battle[x][y] == NAVIO) {
                naval_battle[x][y] = 5;
            } 
            else {
                naval_battle[x][y] = 1;
            }
        }
    }
}


    // Chama a função para imprimir o tabuleiro
    tabuleiro(naval_battle);
    
    return 0;
}
