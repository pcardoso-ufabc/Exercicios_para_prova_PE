/*Pedro Henrique Cardoso - 11202321449

Exercício 9 – Uso de calloc: vetor de frequências
Implemente um programa em C que:
1. Leia um inteiro n (quantidade de números a serem lidos).
2. Para cada número lido (entre 0 e 9), atualize um vetor de frequências de tamanho 10.
3. Use calloc para alocar o vetor de frequências, garantindo que comece inicializado com
zero.
4. Ao final, imprima quantas vezes cada dígito (0 a 9) apareceu.
Exemplo de saída:
Frequencias:
0: 1 vez(es)
1: 0 vez(es)
2: 3 vez(es)
...
9: 0 vez(es)

*/

#include <stdio.h>
#include <stdlib.h>

int *frequencia(int *vetor, int x);

int main(){
    
    int n, x;
    scanf("%d", &n);
    
    int *vetor = NULL;
    vetor = (int *)calloc(10, sizeof(int));
    if (vetor == NULL){
        printf("Erro ao alocar memoria para vetor");
        exit (1);
    }
    
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        vetor = frequencia(vetor, x);
    }
    
    for(int i = 0; i < 10; i++)
        printf("%d: %d vez(es)\n", i, vetor[i]);
        
    free(vetor);
    
    return 0;
}

int *frequencia(int *vetor, int x){
    
    int i = 0;
    
    while(x != i)
        i++;
    vetor[i] = vetor[i] + 1;

    
    return vetor;
}
