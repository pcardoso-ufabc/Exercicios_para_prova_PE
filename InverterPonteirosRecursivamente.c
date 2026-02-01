/*Pedro Henrique Cardoso - 11202321449

Exercício 15 – Inverter lista recursivamente (alterando ponteiros)
Implemente uma função recursiva em C que inverta a lista, modificando os ponteiros prox:
Lista inverteLista(Lista l);
Exemplo:
- Antes: A -> B -> C -> D -> NULL
- Depois: D -> C -> B -> A -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char letra;
    struct node *prox;
}Lista;

Lista *inverteLista(Lista *l);
Lista *insere_no(Lista *lista, char x);
void imprime_lista(Lista *lista);
void libera_lista(Lista *lista);

int main(){
    
    int n;
    scanf("%d", &n);
    
    char x;
    
    Lista *lista = NULL;
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        lista = insere_no(lista, x);
    }
    
    lista = inverteLista(lista);
    imprime_lista(lista);
    libera_lista(lista);
    
    return 0;
}

Lista *insere_no(Lista *lista, char x){
    
    Lista *novo = NULL;
    novo = (Lista *)malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Erro ao alocar memoria para novo no");
        exit(1);
    }
    
    novo->letra = x;
    novo->prox = NULL;
    
    if(lista == NULL)
        return novo;
    
    Lista *aux = lista;
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return lista;
}

Lista *inverteLista(Lista *l){
    
if (l == NULL || l->prox == NULL)
        return l;

    Lista *novaCabeca = inverteLista(l->prox);

    l->prox->prox = l;
    l->prox = NULL;

    return novaCabeca;
}

void imprime_lista(Lista *lista){
    
    Lista *aux = lista;
    if(aux == NULL)
        return;
    printf("%c ", aux->letra);
    imprime_lista(aux->prox);
}

void libera_lista(Lista *lista){
    
    Lista *aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
    
}
