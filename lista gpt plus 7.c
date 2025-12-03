/*Pedro Henrique Cardoso - 11202321449

Exercício 7 – Vetor e ponteiro: zerando com aritmética de ponteiros
Implemente a função:
void zerarVetor(int *v, int n);
Regras:
- A função deve verificar se v != NULL.
- Deve zerar todos os n elementos do vetor usando apenas aritmética de ponteiros (isto é,
sem usar v[i], apenas *(v + i) ou equivalentes).
No main:
1. Declare um vetor int v[5] = {1, 2, 3, 4, 5};
2. Imprima o vetor antes e depois da chamada de zerarVetor

*/

#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *vetor, int tam);
void zerarVetor(int *v, int n);

int main(){
    
    int v[5] = {1, 2, 3, 4, 5};
    imprime_vetor(v, 5);
    
    zerarVetor(v, 5);
    imprime_vetor(v, 5);
}

void imprime_vetor(int vetor[], int tam){
    
    for(int i = 0; i < tam; i++)
        printf("%d ", *(vetor + i));
    printf("\n");
}

void zerarVetor(int *v, int n){
    
    for(int i = 0; i < n; i++)
        *(v + i) = 0;
}
