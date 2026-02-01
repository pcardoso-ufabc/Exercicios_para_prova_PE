/*Pedro Henrique Cardoso - 11202321449

Exercício 13 – Remover todas as ocorrências de um elemento
Implemente uma função em C que remova todas as ocorrências do valor x na lista
simplesmente encadeada:
Lista removeTodas(Lista l, char x);
Exemplo:
- Lista: A -> B -> A -> C -> A -> NULL
- x = 'A'
- Lista resultante: B -> C -> NULL


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char dado;
    struct node *prox;
}Lista;

Lista *inclui_no(Lista *lista, char x);
Lista *removeTodas(Lista *l, char x);
void imprime_lista(Lista *lista);
void libera_lista(Lista *lista);

int main(){
    
    int n;
    char x;
    
    Lista *lista = NULL;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf(" %c", &x);
        lista = inclui_no(lista, x);
    }
    
    scanf(" %c", &x);
    lista = removeTodas(lista, x);
    
    imprime_lista(lista);
    libera_lista(lista);
    
    return 0;
    
}

Lista *inclui_no(Lista *lista, char x){
    
    Lista *novo = NULL;
    novo = (Lista *)malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Erro ao alocar memoria para novo No");
        exit(1);
    }
    
    novo->dado = x;
    novo->prox = NULL;
    
    if(lista == NULL)
        return novo;
        
    Lista *aux = lista;
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return lista;
}

Lista *removeTodas(Lista *l, char x){
    
    while (l != NULL && l->dado == x) {
        Lista *temp = l;
        l = l->prox;
        free(temp);
    }

    if (l == NULL) 
        return NULL;

    Lista *aux = l;
    while (aux->prox != NULL) {
        if (aux->prox->dado == x) {
            Lista *temp = aux->prox;
            aux->prox = aux->prox->prox;
            free(temp);
        } else {
            aux = aux->prox;
        }
    }

    return l;
}

void imprime_lista(Lista *lista){
    
    Lista *aux = lista;
    if(aux == NULL)
        return;
    printf("%c ", aux->dado);    
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
