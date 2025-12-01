/*Pedro Henrique Cardoso - 11202321449
exercicio 34

34. Implemente uma fun¸c˜ao que, dada uma matriz 3x3 que representa um tabuleiro de jogo da
velha (com -1 para vazio, 0 para ’O’ e 1 para ’X’), determine o estado do jogo. A fun¸c˜ao deve
retornar: -1 (ainda jogando), 0 (’O’ venceu), 1 (’X’ venceu), ou 2 (empate).
Exemplo de Entrada:
Matriz: [[1, 0, 1],
[0, 1, 0],
[0, 1, 1]]
Exemplo de Sa´ıda:
Estado do jogo: 1 (X venceu)

*/

#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(int **matriz, int n);
void le_matriz(int **matriz, int n);
void analisa_jogo(int **matriz, int n);

int main(){
    
    int n;
    scanf("%d", &n);
    
    int **matriz = cria_matriz(matriz, n);
    le_matriz(matriz, n);

    analisa_jogo(matriz, n);
    
    
    return 0;
}

int **cria_matriz(int **matriz, int n){
    
    matriz = (int**)malloc(n * sizeof(int*));
    
    for(int i = 0; i < n; i++){
        matriz[i] = (int *)malloc(n * sizeof(int));
    }
    
    return matriz;
}

void le_matriz(int **matriz, int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);
    }
    
}

void analisa_jogo(int **matriz, int n){
    
    int i = 0, j = 0;

    for (i = 0; i < n; i++){
        j = 0;
        if (matriz[i][j] == 0 && matriz[i][j + 1] == 0 && matriz [i][j + 2] == 0 ){
            printf("0 ('O' venceu)");
            return;
        }    
    }    
    
    for (i = 0; i < n; i++){
        j = 0;
        if (matriz[i][j] == 1 && matriz[i][j + 1] == 1 && matriz [i][j + 2] == 1 ){
            printf("1 ('x' venceu)");
            return;
        }    
    }

    for (j = 0; j < n; j++){
        i = 0;
        if (matriz[i][j] == 0 && matriz[i + 1][j] == 0 && matriz [i + 2][j] == 0 ){
            printf("0 ('O' venceu)");
            return;
        }    
    } 
    
    for (j = 0; j < n; j++){
        i = 0;
        if (matriz[i][j] == 1 && matriz[i + 1][j] == 1 && matriz [i + 2][j] == 1 ){
            printf("1 ('x' venceu)");
            return;
        }    
    }
    
    i = 0; j = 0;
    if (matriz[i][j] == 0 && matriz[i + 1][j + 1] == 0 && matriz [i + 2][j + 2] == 0 ){
        printf("0 ('O' venceu)");
        return;
    }
    
    i = 0; j = 0;
    if (matriz[i][j] == 1 && matriz[i + 1][j + 1] == 1 && matriz [i + 2][j + 2] == 1 ){
        printf("1 ('1' venceu)");
        return;
    }
    
    i = 0; j = 3;
    if (matriz[i][j] == 0 && matriz[i + 1][j - 1] == 0 && matriz [i + 2][j - 2] == 0 ){
        printf("0 ('O' venceu)");
        return;
    }
    
    i = 0; j = 3;
    if (matriz[i][j] == 1 && matriz[i + 1][j - 1] == 1 && matriz [i + 2][j - 2] == 1 ){
        printf("1 ('1' venceu)");
        return;
    }
    
    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            if (matriz[i][j] == -1){
                printf("-1 (ainda jogando)");
                return;
            }    
    }
    
    printf("2 (empate)");
    
}
