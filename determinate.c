/*Pedro Henrique Cardoso - 11202321449
exercicio 1

17. Crie uma fun¸c˜ao que recebe uma matriz A (3x3) e retorna o valor da determinante det(A).
Matriz 3 × 3 (Regra de Sarrus)
Para uma matriz A =

|a11 a12 a13|
|a21 a22 a23|
|a31 a32 a33|

, o determinante pode ser calculado pela Regra de
Sarrus:
det(A) = a11a22a33 + a12a23a31 + a13a21a32 − (a13a22a31 + a11a23a32 + a12a21a33)

Exemplo de Entrada:
A =

|1 2 3|
|0 1 4|
|5 6 0|


Exemplo de Sa´ıda:
det(A) = 1

*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int** cria_matriz();
void le_matriz(int **matriz);
int det(int** matriz );


int main(){
    
    int **matriz = cria_matriz(); 
    
    le_matriz(matriz);
    
    int determinate = det(matriz);
    
    printf("%d\n", determinate);
    
    free(matriz);
    return 0;
}

int** cria_matriz(){
    int **matriz = (int **)calloc(3, sizeof(int*));
    for(int i = 0; i < 3; i++){
        matriz[i] = (int *)calloc(3, sizeof(int));
    }
    
    return matriz;
}

void le_matriz(int **matriz){
    
   for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }    

}

int det(int** matriz ) {
    int soma = 0, sub = 0;

    for (int i = 0; i < TAM; i++) {
        soma += matriz[0][i] * matriz[1][(i+1)%3] * matriz[2][(i+2)%3];
    }

    for (int i = 0; i < TAM; i++) {
        sub += matriz[0][i] * matriz[1][(i+2)%3] * matriz[2][(i+1)%3];
    }

    return soma - sub;
}
