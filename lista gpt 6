/*Pedro Henrique Cardoso - 11202321449
lista GPT - lista simplimente encadeada

6️⃣ Encontrar o maior elemento da lista (recursivo)
Enunciado

Implemente uma função recursiva em C que receba uma lista simplesmente encadeada contendo números inteiros e retorne 
o maior elemento da lista.

A lista não deve ser alterada.

Exemplo de Entrada:

Lista:

3 → 9 → 1 → 7 → 4 → NULL

Exemplo de Saída:
Maior = 9

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}No;

No *insere_lista(No *lista, int x);
void imprime_lista (No *lista);
int maior_elemento(No *lista);

int main(){
    
    int n, x;
    
    No *lista = NULL;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        lista = insere_lista(lista, x);
    }
    
    imprime_lista(lista);
    
    int maior = maior_elemento(lista);
    printf("Maior = %d\n", maior);
    
    return 0;
}

No *insere_lista(No *lista, int x){
    
    No *novo = NULL;
    novo = (No*)malloc(sizeof(No));
    if (novo == NULL)
        printf("Erro ao alocar memoria para novo No\n");
    
    novo->valor = x;
    novo->prox = NULL;
    
    if(lista == NULL)
        return novo;
        
    No *aux = lista;
    while(aux->prox != NULL)
        aux = aux->prox;
    
    aux->prox = novo;
    return lista;
    
}

void imprime_lista(No *lista){
    
    No *aux = lista;
    if(aux == NULL){
        printf("NULL\n");
        return;
    }
    
    printf("%d -> ", aux->valor);
    imprime_lista(aux->prox);
}

int maior_elemento(No *lista){
    
    No *aux = lista;
    No *retorno = lista;
    if(aux -> NULL)
        return retorno->valor;
        
    aux
    
    //deu prequiça(e não sei fazer kkkkk)
}

void libera_lista(No *lista){
    
    No *aux;
    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}
