/*Pedro Henrique Cardoso - 11202321449

Exercício 27 – Espelhar matriz em relação à diagonal secundária
Implemente uma função que receba uma matriz quadrada int **matriz, int n e a espelhe em
relação à diagonal secundária (a que vai do canto superior direito ao canto inferior
esquerdo), in-place.
Exemplo (3x3):
Antes:
a b c
d e f
g h i
Depois do espelhamento na diagonal secundária:
i f c
h e b
g d a
Você pode usar trocas (swap) apropriadas, tomando cuidado para não desfazer trocas já
realizadas.

*/

#include <stdio.h>
#include<stdlib.h>

void espelha_matriz(int **matriz, int n);
void imprime_matriz(int **matriz, int n);
void libera_matriz(int **matriz, int n);

int main(){
    
    int n;
    scanf("%d", &n);
    
    int **matriz = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
        matriz[i] = (int *)malloc(n * sizeof(int));
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);
    }
    
    printf("\nMatriz original:\n");
    imprime_matriz(matriz, n);
    espelha_matriz(matriz, n);
    printf("\nMatriz espelhada:\n");
    imprime_matriz(matriz, n);
    
    libera_matriz(matriz, n);
    
    return 0;
}

void espelha_matriz(int **matriz, int n){
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            
            int ii = n - 1 - j;
            int jj = n - 1 - i;
            
            if (i > ii || (i == ii && j >= jj))
                continue;
            
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
    
    for(int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);
}
