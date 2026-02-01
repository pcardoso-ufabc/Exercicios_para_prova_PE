/*Pedro Henrique Cardoso - 11202321449
exercicio 22

22. Crie uma fun¸c˜ao que recebe uma matriz Mm,n e um ´ındice de coluna. Retorne um vetor
contendo os elementos dessa coluna, ordenados em ordem crescente.
Para ordenar utilize o Algoritmo Bubble Sort.
Algorithm 1 Bubble Sort Otimizado
1: procedure BubbleSortOtimizado(V , N)
2: trocou ← verdadeiro
3: i ← 0
4: while i < N − 1 and trocou do
5: trocou ← falso
6: for j ← 0 to N − 2 − i do
7: if V [j] > V [j + 1] then
8: temp ← V [j]
9: V [j] ← V [j + 1]
10: V [j + 1] ← temp
11: trocou ← verdadeiro
12: i ← i + 1
Exemplo de Entrada:
Matriz M = [[3, 5, 4], [1, 1, 9], [2, 6, 5]]
Indice da coluna: 1
Exemplo de Sa´ıda:
Coluna 1 ordenada: [1, 5, 6]

*/

#include <stdio.h>
#include <stdlib.h>

int ** cria_matriz(int n, int m);
void le_matriz(int **matriz, int n, int m);
void BubbleSortOtimizado(int **matriz, int n, int indice);
void imprime_coluna(int **matriz, int indice, int n);

int main(){
    
    int n, m, indice;
    scanf("%d %d", &n, &m);
    
    int **matriz = cria_matriz(n, m);
    
    le_matriz(matriz, n, m);
    
    scanf("%d", &indice);
    
    BubbleSortOtimizado(matriz , n, indice);
    
    imprime_coluna(matriz, indice, n);
    
    return 0;
}

int ** cria_matriz(int n, int m){
    
    int ** matriz = (int **)calloc(n, sizeof(int *));
    for(int i = 0; i < n; i++)
        matriz[i] = (int *)calloc(m, sizeof(int));
    
    return matriz;
}

void le_matriz(int **matriz, int n, int m){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void BubbleSortOtimizado(int **matriz, int n, int indice){
    
    int trocou = 1, temp;

    for(int i = 0; i < n - 1 && trocou; i++){
        trocou = 0;
        
        for(int j = 0; j < n - 1 - i; j++){
            if(matriz[j][indice] > matriz[j+1][indice]){
                temp = matriz[j][indice];
                matriz[j][indice] = matriz[j+1][indice];
                matriz[j+1][indice] = temp;
                trocou = 1;
            }
        }
    }
}

void imprime_coluna(int **matriz, int i, int n){
    
    printf("coluna %d ordenada: [", i);
    for(int j = 0; j < n; j++){
        printf("%d", matriz[j][i]);
        if(j < n - 1)
            printf(", ");
    }    
    printf("]");
}
