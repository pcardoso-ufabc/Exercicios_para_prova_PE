/*Pedro Henrique Cardoso - 11202321449

Exercício 6 – Remover todas as ocorrências de um elemento
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
    struct node prox;
}Lista;

Lista inclui_no(Lista lista, x);
Lista removeTodas(Lista l, char x);

int main(){
    
    int n;
    char x;
    
    Lista *lista = NULL;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%c", &x);
        lista = inclui_no(lista, x);
    }
    
    scanf("%c", &x);
    lista = removeTodas(lista, x);
    
    
}

Lista inclui_no(Lista lista, char x){
    
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
        aux = aux-prox;
        
    aux->prox = novo;
    return lista;
}

Lista removeTodas(Lista l, char x){
    
    Lista *aux = l;
    while(aux->prox != NULL){
        if(aux-dado == x){
            
        }
    }
}
