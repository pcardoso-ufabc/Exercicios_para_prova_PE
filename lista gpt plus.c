/*Pedro Henrique Cardoso - 11202321449

Exercício 8 – Alocação dinâmica de vetor com malloc
Implemente um programa que:
1. Leia um inteiro n do teclado (tamanho do vetor).
2. Aloque dinamicamente um vetor de n inteiros usando malloc.
3. Leia n valores inteiros do teclado e armazene no vetor.
4. Calcule e exiba:
- a soma dos elementos
- a média (como double)
5. Libere a memória com free.
Se a alocação falhar (ptr == NULL), o programa deve imprimir uma mensagem de erro e
encerrar com return 1;.

*/

#include <stdio.h>
#include <stdlib.h>

void somar(int *ptr, int *soma, int n);
void media_calc(int *soma, double *media, int n);

int main (){
    
    int n, soma = 0;
    double media = 0.0;
    scanf("%d", &n);
    
    int *ptr = NULL;
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL){
        printf("Erro ao alocar memoria");
        return 1;
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }
    
    somar(ptr, &soma, n);
    media_calc(&soma, &media, n);
    
    printf("%d\n", soma);
    printf("%.3f\n", media);
    
    free(ptr);
    
    return 0;
}

void somar(int *ptr, int *soma, int n){
    
    for(int i = 0; i < n; i++){
        *soma = *soma + ptr[i];
    }
}
void media_calc(int *soma, double *media, int n){
    
    *media = (double)(*soma) / n;
}
