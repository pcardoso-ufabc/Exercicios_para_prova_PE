/*Pedro Henrique Cardoso - 11202321449
exercicio 1

Exercício 1 – Imprimir lista recursivamente (ida e volta)
Implemente duas funções recursivas em C:
1. void imprime(Lista l); que imprime os elementos da lista na ordem em que aparecem.
2. void imprimeReverso(Lista l); que imprime os mesmos elementos na ordem inversa, sem
alterar os ponteiros da lista.
Exemplo de Saída (para uma lista A -> B -> C -> NULL):
Imprime: A B C
Imprime reverso: C B A

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prox;
}No;

No *insere_no(No *lista, int x);
void imprime_normal(No *lista);
void imprime_inverso(No *lista);
void libera_lista(No *lista);

int main(){
    
    No *lista = NULL;
    
    int n, x;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        lista = insere_no(lista, x);
    }
    printf("lista normal: \n");
    imprime_normal(lista);
    printf("lista inversa: \n");
    imprime_inverso(lista);
    
    libera_lista(lista);
    
    return 0;
    
}

No *insere_no(No *lista, int x){
    
    No *novo = NULL;
    novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
       printf("Erro ao alocar memoria para novo no");
       exit(1);
   }
   
    novo->data = x;
    novo->prox = NULL;
   
    if(lista == NULL)
        return novo;
    
    No *aux = lista;
    while(aux->prox != NULL)
        aux = aux->prox;
    
    aux->prox = novo;
    return lista;
   
}

void imprime_normal(No *lista){
    
    No* aux = lista;
    if(aux == NULL){
        printf("\n");
        return;
    }
    printf("%d ", aux->data);
    imprime_normal(aux->prox);
    
}

void imprime_inverso(No *lista){
    
    No *aux = lista;
    if(aux == NULL)
        return;
    imprime_inverso(aux->prox);
    printf("%d ", aux->data);
    
}

void libera_lista(No *lista){
    
    No *aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
}
