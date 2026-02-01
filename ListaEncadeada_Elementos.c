/*Pedro Henrique Cardoso - 11202321449
lista GPT - lista simplimente encadeada

4️⃣ Contar quantos elementos existem na lista (recursivo)
Enunciado

Implemente uma função recursiva em C que receba uma lista simplesmente encadeada e retorne quantos nós existem na lista.

A lista não deve ser modificada.

Exemplo de Entrada:

Lista:

10 → 4 → 8 → 3 → 1 → NULL

Exemplo de Saída:
Quantidade = 5

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
}No;

No *insere_lista(No *lista, int x);
void imprime_lista(No *lista);
int le_quantidade(No *lista);

int main(){
    
    int n, x;
    
    No *lista = NULL;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        lista = insere_lista(lista, x);
    }
    
    imprime_lista(lista);
    
    int quantidade = le_quantidade(lista);
    
    printf("Quantidade = %d", quantidade);
    
    return 0;
}

No *insere_lista(No *lista, int x){
    
    No *novo = NULL;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar No\n");
        exit(1);
    }
    
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

void imprime_lista(No* lista){
    
    No *aux = lista;
    
    if (aux == NULL){
        printf("NULL\n");
        return;
    }
    
    printf("%d -> ", aux->valor);
    aux = aux->prox;
    return imprime_lista(aux);
}

int le_quantidade(No *lista){
    
    No* aux = lista;
    if (aux == NULL)
        return 0;
    return 1 + le_quantidade(aux->prox);
    
}
