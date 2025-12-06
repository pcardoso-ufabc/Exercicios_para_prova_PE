/*Pedro Henrique Cardoso - 11202321449

Exercício 23 – Remover duplicatas mantendo a primeira ocorrência
Implemente uma função em C que remove nós duplicados em uma lista simplesmente
encadeada, mantendo apenas a primeira ocorrência de cada valor:
Lista removeDuplicatas(Lista l);
Exemplo:
- Entrada: A -> B -> A -> C -> B -> NULL
- Saída: A -> B -> C -> NULL

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char letra;
    struct node *prox;
}No;

No *insere_no(No *lista, char x);
No *removeDuplicatas(No* l);
void imprime_lista(No* lista);
void libera_lista(No *lista);

int main(){
    
    int n;
    scanf("%d", &n);
    
    char x;
    No *lista = NULL;
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        lista = insere_no(lista, x);
    }
    
    lista = removeDuplicatas(lista);
    
    imprime_lista(lista);
    libera_lista(lista);
    
    return 0;
}

No *insere_no(No *lista, char x){
    
    No *novo = NULL;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria para novo no");
        exit(1);
    }
    
    novo->letra = x;
    novo->prox = NULL;
    
    if(lista == NULL)
        return novo;
        
    No *aux = lista;
    while(aux->prox != NULL)
        aux = aux->prox;
    
    aux->prox = novo;
    return lista;
}

No *removeDuplicatas(No *l) {

    No *atual = l;

    while (atual != NULL) {

        No *prev = atual;
        No *corr = atual->prox;

        while (corr != NULL) {

            if (corr->letra == atual->letra) {
                prev->prox = corr->prox;
                free(corr);
                corr = prev->prox;
            } else {
                prev = corr;
                corr = corr->prox;
            }
        }

        atual = atual->prox;
    }

    return l;
}

void imprime_lista(No* lista){
    
    No* aux = lista;
    if(aux == NULL)
        return;
    printf("%c ", aux->letra);
    imprime_lista(aux->prox);
}

void libera_lista(No *lista){
    
    No *aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
}
