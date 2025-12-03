/*Pedro Henrique Cardoso - 11202321449

Exercício 2 – Contar nós recursivamente
Implemente uma função recursiva em C que conte a quantidade de nós em uma lista
simplesmente encadeada:
int tamanhoLista(Lista l);
Exemplo de Saída:
- Para a lista A -> B -> C -> D -> NULL, a função deve retornar 4.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char dado;
    struct node* prox;
}No;

No *insere_no(No *lista, int x);
void conta_nos(No *lista, int *tamanho);
void libera_lista(No *lista);

int main(){
    
    int n, tamanho = 0;
    char x;
    
    No *lista = NULL;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        lista = insere_no(lista, x);
    }
    
    conta_nos(lista, &tamanho);
    printf("%d", tamanho);
    
    libera_lista(lista);

    return 0;
    
}

No *insere_no(No *lista, int x){
    
    No *novo = NULL;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria para novo no");
        exit(1);
    }
    
    novo->dado = x;
    novo->prox = NULL;
    
    if(lista == NULL)
        return novo;
    
    No* aux = lista;    
    while(aux->prox !=NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return lista;
}

void conta_nos(No *lista, int * tamanho){
    
    No *aux = lista;
    if (aux == NULL)
        return;
    conta_nos(aux->prox, tamanho);
    (*tamanho)++;
}

void libera_lista(No *lista){
    
    No *aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
}
