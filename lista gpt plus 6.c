/*Pedro Henrique Cardoso - 11202321449

Exercício 6 – Matriz dinâmica: soma da diagonal principal
Usando alocação dinâmica de matrizes com int **, implemente um programa que:
1. Leia dois inteiros linhas e colunas.
2. Aloque dinamicamente uma matriz int **matriz de tamanho linhas x colunas conforme o
esquema:
matriz = (int**) malloc(linhas * sizeof(int*));
for (i = 0; i < linhas; i++)
matriz[i] = (int*) malloc(colunas * sizeof(int));
3. Leia todos os elementos da matriz do teclado.
4. Se a matriz for quadrada (linhas == colunas), calcule e imprima a soma da diagonal
principal. Caso contrário, imprima uma mensagem avisando que não é quadrada.
5. Desaloque corretamente toda a memória (cada linha + bloco principal).
*/

#include <stdio.h>
#include <stdlib.h>

int **le_matriz(int linha, int coluna);

int main(){
    
    int linha, coluna, soma;
    scanf("%d %d", linha, coluna);
    
    int **matriz = le_matriz(linha, coluna);
    
    
    if(linha == coluna){
        soma = soma_diagonal(matriz, linha);
    }else
        printf("Matriz não quadrada.")
        
    printf("%d", soma);
}

int **le_matriz(int linha, int coluna){
    
    int **matriz = (int **)malloc(linha * sizeof(int *));
    for(int i = 0; int < coluna; i++)
        matriz[i] = (int *)malloc(coluna * sizeof(int *));
    
    for (int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++)
            scanf("%d", matriz[i][j]);
    }
}

int soma_diagonal(int ** matriz, int n){
    
}
