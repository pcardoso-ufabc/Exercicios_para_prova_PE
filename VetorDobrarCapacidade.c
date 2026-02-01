/*Pedro Henrique Cardoso - 11202321449

Exercício 19 – Vetor dinâmico com capacidade flexível
Você está implementando um sistema que armazena leituras de sensores em um vetor
dinâmico. A cada novo valor, se o vetor estiver cheio, a capacidade deve ser aumentada em
50% (em vez de dobrar).
Implemente uma função:
double* aumentaCapacidade(double *v, int *capacidade);
Em que:
- v é o vetor atual, com capacidade *capacidade
- a função deve alocar um novo vetor com capacidade nova_cap = *capacidade +
(*capacidade / 2) (arredonde para cima se necessário)
- copiar os dados antigos
- liberar o vetor original e retornar o novo ponteiro, atualizando *capacidade
Em seguida, escreva um pequeno trecho de código que mostre:
- declaração de double *leituras, int capacidade, int tamanho_logico
- inicialização com capacidade pequena (por exemplo, 4)
- inserção de vários valores, chamando aumentaCapacidade quando for necessário.
*/

#include <stdio.h>
#include <stdlib.h>

double *aumentaCapacidade(double *v, int *capacidade);

int main(){
    
    int tam = 0, capacidade = 4;
    double *vetor = NULL;
    vetor = (double *)malloc(capacidade * sizeof(double));
    if(vetor == NULL){
        printf("Erro alocar memoria para vetor");
        exit(1);
    }
    
    for(int i = 0; i < 10; i++){
        
        if(tam == capacidade){
            vetor = aumentaCapacidade(vetor, &capacidade);
            printf("memoria aumentada em 50%");
        }    
            
        scanf("%lf", &vetor[tam]);
        tam++;
    }
    
    for(int i = 0; i < tam; i++)
        printf("%.2lf ", vetor[i]);
        
    free(vetor);
    return 0;
}

double *aumentaCapacidade(double *v, int *capacidade){
    
    int nova_cap = *capacidade + (*capacidade / 2);
    if (*capacidade % 2 != 0)
        nova_cap++;

    double *aux = NULL;
    aux = (double *)malloc(nova_cap * sizeof(double));
    
    for(int i = 0; i < *capacidade; i++)
        aux[i] = v[i];
        
    *capacidade = nova_cap;
    free(v);
    return aux;
}
