/*Pedro Henrique Cardoso - 11202321449

Exercício 26 – Rotação de matriz 180° in-place
Em continuidade à ideia de rotação de matrizes, agora considere uma matriz quadrada n x n
de inteiros armazenada como int **matriz.
Implemente uma função:
void rotacionarMatriz180(int **matriz, int n);
que rotacione a matriz 180 graus no sentido horário (o que é equivalente no sentido
anti-horário) in-place, sem alocar outra matriz n x n.

Exemplo (3x3):
Antes:
1 2 3
4 5 6
7 8 9
Depois:
9 8 7
6 5 4
3 2 1

Mostre também um exemplo de código de invocação, incluindo a alocação dinâmica da
matriz, como feito na prova.


*/

#include <stdio.h>
#include <stdlib.h>

void rotacionarMatriz180(int **matriz, int n);
void imprime_matriz(int **matriz, int n);
void libera_matriz(int **matriz, int n);

int main(){
    
    int n;
    scanf("%d", &n);
    
    int **matriz = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        matriz[i] = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);
    }
    printf("\nMatriz original: \n");
    imprime_matriz(matriz, n);    
    rotacionarMatriz180(matriz, n);
    printf("\nMatriz rotacionada: \n");    
    imprime_matriz(matriz, n);
    
    libera_matriz(matriz, n);
    
    return 0;
}

void rotacionarMatriz180(int **matriz, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            int ii = n - 1 - i;
            int jj = n - 1 - j;

            if (i > ii || (i == ii && j >= jj))
                return;

            int aux = matriz[i][j];
            matriz[i][j] = matriz[ii][jj];
            matriz[ii][jj] = aux;
        }
    }
}

void imprime_matriz(int **matriz, int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

void libera_matriz(int **matriz, int n){
    
    for(int i = 0; i < n; i++){
        free(matriz[i]);
    }
    
    free(matriz);
}
