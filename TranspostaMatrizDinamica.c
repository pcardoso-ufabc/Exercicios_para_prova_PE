/*Pedro Henrique Cardoso - 11202321449

Exercício 12 – Transposta de matriz dinâmica
Ainda usando o esquema de matriz dinâmica (int **), implemente:
int** alocaMatriz(int linhas, int colunas);
void liberaMatriz(int **m, int linhas);
int** transposta(int **m, int linhas, int colunas);
Regras:
- alocaMatriz deve alocar a matriz linhas x colunas usando o padrão:
- vetor de linhas ponteiros e depois cada linha separadamente.
- liberaMatriz deve liberar cada linha e depois o vetor de ponteiros.
- transposta deve:
- Alocar uma nova matriz colunas x linhas.
- Copiar m[i][j] para mT[j][i].
- Retornar o ponteiro para a matriz transposta.
No main:
1. Leia linhas e colunas.
2. Aloque uma matriz m, leia os dados.
3. Chame transposta(m, linhas, colunas) para obter mT.
4. Imprima ambas (original e transposta).
5. Libere toda a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int** alocaMatriz(int linhas, int colunas);
void liberaMatriz(int **m, int linhas);
int** transposta(int **m, int linhas, int colunas);
void imprime_matrizes(int **m, int linhas, int colunas);

int main(){
    
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    
    int **m = NULL;
    m = alocaMatriz(linhas, colunas);
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
            scanf("%d", &m[i][j]);
    }
    
    int **mt = NULL;
    mt = transposta(m, linhas, colunas);
    
    printf("Matriz original:\n");
    imprime_matrizes(m, linhas, colunas);
    
    printf("Matriz transposta:\n");
    imprime_matrizes(mt, linhas, colunas);
    
    liberaMatriz(m, linhas);
    liberaMatriz(mt, linhas);
    
    return 0;
}

int** alocaMatriz(int linhas, int colunas){
    
    int **m = (int **)malloc(linhas * sizeof(int));
    
    for(int i = 0; i < linhas; i ++)
        m[i] = (int*)malloc(colunas * sizeof(int));
    
    return m;
}

int** transposta(int **m, int linhas, int colunas){
    int **mt = NULL;
    mt = alocaMatriz(linhas, colunas);
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
            mt[j][i] = m[i][j];
    }
    return mt;
    
}

void imprime_matrizes(int **m, int linhas, int colunas){
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

void liberaMatriz(int **m, int linhas){
    
    for (int i = 0; i < linhas; i++)
        free(m[i]);
        
    free(m);
}
