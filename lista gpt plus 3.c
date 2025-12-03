/*Pedro Henrique Cardoso - 11202321449

Exercício 5 – Inserir em lista ordenada
Suponha que a lista esteja sempre ordenada em ordem crescente pelo campo dado
(caractere).
Implemente uma função em C que insira um novo elemento x mantendo a lista ordenada:
Lista insereOrdenado(Lista l, char x);
Exemplo:
- Lista atual: B -> D -> F -> NULL
- Inserindo E: nova lista B -> D -> E -> F -> NULL
- Inserindo A: nova lista A -> B -> D -> F -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int dado;
    struct node *prox;
}No;

No *insere_no(No *lista, int x);
void imprime_lista(No *lista);

int main(){
    
    int x, n;
    scanf("%d", &n);
    
    No *lista = NULL;
    
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        lista = insere_no(lista, x);
    }
    
    imprime_lista(lista);
    
}

No *insere_no(No *lista, int x){
    
    int count = 0;
    
    No* novo = NULL;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria para novo no");
        exit(1);
    }
    
    novo->dado = x;
    novo->prox = NULL;
    
    if(lista == NULL)
        return novo;
    
    if(x < lista->dado){
        novo->prox = lista;
        return novo;
    }
    
    No *aux = lista;
    while(aux->prox != NULL && x > aux->prox->dado){
        aux = aux->prox;
    }
    
    novo->prox = aux->prox;
    aux->prox = novo;
    return lista;
}

void imprime_lista(No *lista){
    
    No *aux = lista;
    if(aux == NULL)
        return;
    printf("%d ", aux->dado);
    imprime_lista(aux->prox);
    
}
