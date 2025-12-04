/*Pedro Henrique Cardoso - 11202321449

Exercício 11 – Ponteiro para ponteiro e alocação de vetor por função
Implemente uma função que aloque dinamicamente um vetor de inteiros e devolva o
ponteiro usando um ponteiro para ponteiro:
int alocaVetor(int **v, int n);
Regras:
- A função deve:
- Alocar n * sizeof(int) bytes usando malloc.
- Retornar 0 em caso de sucesso e 1 em caso de erro.
- Em caso de erro, garantir que *v permaneça NULL.
Em main:
- Declare int *vet = NULL;
- Leia n.
- Chame alocaVetor(&vet, n);
- Se der certo, preencha o vetor com números quaisquer (ex.: vet[i] = i * 10;) e imprima.
- Libere com free(vet).

*/

#include <stdio.h>
#include <stdlib.h>

int alocaVetor(int **v, int n);

int main(){
    
    int *vet = NULL;
    int n, sucesso;
    scanf("%d", &n);
    
    sucesso = alocaVetor(&vet, n);
    
    if(!sucesso){
        for(int i = 0; i < n; i++){
            vet[i] = i * 10;
            printf("%d ", vet[i]);
        }
    }
    
    free(vet);
    
    return 0;
}

int alocaVetor(int **v, int n){
    
    *v = (int *)malloc(n * sizeof(int));
    if (v == NULL)
        return 1;
    return 0;
}
