/*Pedro Henrique Cardoso - 11202321449
lista GPT - lista simplimente encadeada

2️⃣ Somar os elementos de uma lista

Implemente uma função em C que receba uma lista simplesmente encadeada contendo números inteiros e retorne a soma de todos os 
elementos, sem alterar a lista.

Exemplo de Entrada:

Lista:

4 → 7 → 2 → 5 → NULL

Exemplo de Saída:
Soma = 18

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * prox;
}No;

No *insere_lista(No* lista, int x);
int soma_lista(No *lista);
void libera_lista(No *lista);

int main(){
    
    int n, x;
    
    No *lista = NULL;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        lista = insere_lista(lista, x);
    }
    
    int soma = soma_lista(lista);
    printf("Soma = %d", soma);
    
    libera_lista(lista);
    
    return 0;
}

No *insere_lista(No* lista, int x){
    
    No *novo = NULL;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria para no\n");
        exit(1);
    }
    
    novo->valor = x;
    novo->prox = NULL;
    
    if (lista == NULL)
        return novo;
        
    No* aux = lista;    
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return lista;
    
}

int soma_lista(No *lista){
    
    int soma = 0;
    No* aux = lista;
    
    while(aux != NULL){
        soma += aux->valor;
        aux = aux->prox;
    }
    
    return soma;
}

void libera_lista(No *lista){
    
    No *aux;
    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}
