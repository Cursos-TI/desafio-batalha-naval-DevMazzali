#include <stdio.h>

void tabuleiro (int tabuleiro[10][10]) {
    char line [10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    printf(" TABULEIRO BATALHA NAVAL \n");
    printf("  ");
    for(int j = 0; j < 10; j++){
        printf("%c ", line[j]); // Imprime os números das colunas
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i+1); // Aqui o comando i+1 serve para imprimir os numeros das linhas começando em 1, ao invez de começar em 0
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


int main () {
    int ship[10][10] = {0}; // Inicializa o tabuleiro com 0 (água)
    
    ship [1][1] = 3;
    ship [1][2] = 3;
    ship [1][3] = 3;

    ship [6][4] = 3;
    ship [7][4] = 3;
    ship [8][4] = 3;
    
    tabuleiro(ship); // Chama a função para imprimir o tabuleiro
    
    return 0;
}
