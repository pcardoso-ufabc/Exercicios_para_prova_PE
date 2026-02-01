/*Pedro Henrique Cardoso - 11202321449

Exercício 20 – Redução de vetor dinâmico para o tamanho utilizado
Após diversas inserções e remoções em um vetor dinâmico de inteiros, é comum que a
capacidade seja muito maior que o número de elementos usados, desperdiçando memória.
Implemente uma função:
int* encolheVetor(int *v, int tamanho_usado, int *capacidade);
Que deve:
- alocar um novo vetor com capacidade exatamente igual a tamanho_usado
- copiar os tamanho_usado elementos
- liberar o vetor antigo
- atualizar *capacidade para tamanho_usado
- retornar o ponteiro para o novo vetor
Mostre um exemplo de uso em que:
- a capacidade inicial é 20
- apenas 7 elementos estão em uso
- após chamar encolheVetor, a capacidade passa a ser 7.
*/

#include <stdio.h>
#include <stdlib.h>

int* encolheVetor(int *v, int tamanho_usado, int *capacidade);

int main(){
    
    int tamanho_usado = 7, capacidade = 20;
    
    int *v = NULL;
    v = (int *)malloc(capacidade * sizeof(int));
    if(v == NULL){
        printf("Erro ao alocar memoria para vetor");
        exit(1);
    }
    
    for(int i = 0; i < tamanho_usado; i++)
        v[i] = i * 10;
    
    v = encolheVetor(v,tamanho_usado, &capacidade);
    
    for (int i = 0; i < tamanho_usado; i++)
        printf("%d ", v[i]);
    printf("\n");
        
    printf("Capacidade = %d\n", capacidade);
    
}

int* encolheVetor(int *v, int tamanho_usado, int *capacidade){
    
    int *aux = NULL;
    aux = (int *)malloc(tamanho_usado * sizeof(int));
    if(aux == NULL){
        printf("Erro ao alocar memoria para novo vetor");
        exit(1);
    }
    
    for(int i = 0; i < tamanho_usado; i++)
        aux[i] = v[i];
        
    *capacidade = tamanho_usado;
    free(v);
    
    return aux;
}
