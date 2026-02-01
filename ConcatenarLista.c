/*Pedro Henrique Cardoso - 11202321449

Exercício 14 – Concatenar duas listas
Implemente uma função em C que receba duas listas simplesmente encadeadas l1 e l2 e as
concatene, ligando o final de l1 ao início de l2:
Lista concatena(Lista l1, Lista l2);
Requisitos:
- A função deve retornar o ponteiro para o início da lista resultante.
- Não é permitido realocar nós, apenas rearranjar ponteiros.
Exemplo:
- l1: A -> B -> NULL
- l2: C -> D -> NULL
- Resultado: A -> B -> C -> D -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letra;
    struct node *prox;
}Lista;

Lista *concatena(Lista *l1, Lista *l2);
Lista *insere_no(Lista *lista, char x);
void imprime_lista(Lista *l1);

int main(){
    
    int n;
    scanf("%d", &n);
    
    char x;
    
    Lista *l1 = NULL;
    Lista *l2 = NULL;
    
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        l1 = insere_no(l1, x);
    }
    
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        l2 = insere_no(l2, x);
    }    
    
    l1 = concatena(l1, l2);
    imprime_lista(l1);
    
    return 0;
    
}

Lista *insere_no(Lista *lista, char x){
    
    Lista *novo = NULL;
    novo = (Lista *)malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Erro ao alocar memoriia para novo no");
        exit(1);
    }
    
    novo->letra = x;
    novo ->prox = NULL;
    
    if (lista == NULL)
        return novo;
        
    Lista *aux = lista;
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return lista;
        
}

Lista *concatena(Lista *l1, Lista *l2){
    
    Lista *aux = l1;
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = l2;
    
    return l1;
}

void imprime_lista(Lista *l1){
    
    Lista* aux = l1;
    if(aux == NULL)
        return;
    printf("%c ", aux->letra);
    imprime_lista(aux->prox);
}
