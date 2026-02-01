/*Pedro Henrique Cardoso - 11202321449
lista GPT - lista simplimente encadeada

1️⃣ Exibir a lista ao contrário (recursivo)

Implemente uma função recursiva em C que receba uma lista simplesmente encadeada e imprima seus elementos em ordem inversa, sem alterar 
a lista.

Exemplo de Entrada:
Lista: A → B → C → D → NULL

Exemplo de Saída:

D
C
B
A

*/

#include <stdio.h>
#include<stdlib.h>

typedef struct No {
    char dado;
    struct No* prox;
}No;

void imprime_inverso(No *inicio);
No *insere_no(No *lista, char x);
void libera_lista(No*lista);


int main(){
    
    No* lista = NULL;
    
    int n;
    char x;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        lista = insere_no(lista, x);
    }
    
    imprime_inverso(lista);
    
    libera_lista(lista);
    
    return 0;
}

No *insere_no(No *lista, char x){

No *novo = NULL;
novo = (No*)malloc(sizeof(No));
if(novo == NULL){
    printf("Erro ao alocar no.");
    exit(1);
}
    novo->dado = x;
    novo->prox = NULL;

    if (lista == NULL) 
        return novo;

    No* aux = lista;
    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = novo;
    return lista;
}

void imprime_inverso(No *inicio) {
    if (inicio == NULL) 
        return;
    imprime_inverso(inicio->prox);
    printf("%c\n", inicio->dado);
}

void libera_lista(No *lista){
    
    No *aux;
    
    while(lista != 0){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

