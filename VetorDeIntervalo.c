/*Pedro Henrique Cardoso - 11202321449
exercicio 10

10. Implemente uma fun¸c˜ao em C que recebe dois valores inteiros, minimo e maximo, aloca dinamicamente 
um vetor de inteiros preenchendo-o com 0 (zero) em todas as posi¸c˜oes, para
representar o intervalo [minimo, maximo]. Retorne um ponteiro para o vetor alocado. Se
minimo > maximo, retorne NULL.
Exemplo de Entrada:
minimo: 5
maximo: 10
Exemplo de Sa´ıda:
Vetor alocado: [0, 0, 0, 0, 0, 0]
*/

#include <stdio.h>
#include <stdlib.h>

int* vetorIntervalo(int min, int max);
void imprime_vetor(int * vetor, int min, int max);

int main(){
    
    int min, max, intervalo;
    scanf("%d %d", &min, &max);
    
    int *vetor = vetorIntervalo(min, max);
    
    imprime_vetor(vetor, min, max);
    
    return 0;
    
}

int* vetorIntervalo(int min, int max){
    
    if(min > max)
        return NULL;
        
    int intervalo = (max - min) + 1;
    
    int *vetor = (int *)calloc(intervalo, sizeof(int));
        
    return vetor;
    
}

void imprime_vetor(int * vetor, int min, int max){
    
    printf("[");
    for(int i = 0; i < (max - min) + 1; i++){
        printf("%d", vetor[i]);
        if(i < (max - min))
            printf(", ");
    }
    printf("]\n");
}
