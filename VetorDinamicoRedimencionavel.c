/*Pedro Henrique Cardoso - 11202321449

Exercício 10 – Vetor dinâmico redimensionável (versão simplificada)
Baseado na ideia de vetor dinâmico dos slides, implemente um pequeno TAD de vetor
dinâmico de inteiros com redimensionamento automático.
Estrutura de estado (no main):
int *elementos = NULL;
int tam = 0; // tamanho logico
int max_tam = 0; // capacidade
Funções a implementar:
int* inicializaVetor(int *tam_ptr, int *max_tam_ptr); // capacidade inicial =
4
int* adicionaElemento(int *elementos, int *tam_ptr, int *max_tam_ptr, int
elem);
void imprimeVetor(const int *elementos, int tam, int max_tam);
Regras:
- inicializaVetor deve alocar capacidade inicial 4 (pode usar calloc).
- adicionaElemento deve:
- Duplicar a capacidade (max_tam *= 2) quando tam == max_tam.
- Alocar novo bloco, copiar elementos, liberar bloco antigo e retornar o novo ponteiro.
- imprimeVetor deve exibir todos os elementos, o tamanho atual e a capacidade.
No main, demonstre a inserção de pelo menos 6 elementos, mostrando quando ocorre
redimensionamento.

*/

#include <stdio.h>
#include <stdlib.h>

int* inicializaVetor(int *tam_ptr, int *max_tam_ptr);
int* adicionaElemento(int *elementos, int *tam_ptr, int *max_tam_ptr, int elem);
int* aumenta_memoria(int *elementos, int *tam_ptr, int *max_tam_ptr);
void imprimeVetor(const int *elementos, int tam, int max_tam);


int main(){
    
    int *elementos = NULL;
    int tam = 0, max_tam = 0, elem;
    
    elementos = inicializaVetor(&tam, &max_tam);
    
    for(int i = 0; i < 6; i ++){
        scanf("%d", &elem);
        elementos = adicionaElemento(elementos, &tam, &max_tam, elem);
    }
    
    imprimeVetor(elementos, tam, max_tam);
}

int* inicializaVetor(int *tam_ptr, int *max_tam_ptr){
    
    *max_tam_ptr = 4;
    
    int *ptr = (int *)malloc(*max_tam_ptr * sizeof(int));
    return ptr;
}
int* adicionaElemento(int *elementos, int *tam_ptr, int *max_tam_ptr, int elem){
    
    if(*tam_ptr == *max_tam_ptr)
        elementos = aumenta_memoria(elementos, tam_ptr, max_tam_ptr);
        
    elementos[*tam_ptr] = elem;
    (*tam_ptr)++;
    
    return elementos;
    
    
}

int* aumenta_memoria(int *elementos, int *tam_ptr, int *max_tam_ptr){
    
    *max_tam_ptr = (*max_tam_ptr) * 2;
    int *aux = (int *)malloc(*max_tam_ptr * sizeof(int));
    if (aux == NULL){
        printf("Erro ao realocar memoria");
        return elementos;
    }
    printf("Memoria dobrada\n\n");
    
    for(int i = 0; i < *tam_ptr; i++)
        aux[i] = elementos[i];
    free(elementos);
    return aux;
}

void imprimeVetor(const int *elementos, int tam, int max_tam){
    
    printf("Elementos inseridos: ");
    for(int i = 0; i < tam; i++)
        printf("%d ", elementos[i]);
    printf("\n");
    
    printf("Tamano atual: %d\n", tam);
    printf("Capacidade atual: %d\n", max_tam);
}
