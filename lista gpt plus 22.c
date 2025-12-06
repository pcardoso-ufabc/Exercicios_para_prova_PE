/*Pedro Henrique Cardoso - 11202321449

Exercício 22 – Impressão de lista encadeada em ordem alternada
Considere a estrutura de lista simplesmente encadeada sem nó cabeça:
typedef struct node {
char letra;
struct node *prox;
} No;
Implemente uma função que receba o ponteiro para o início de uma lista e imprima seus
elementos na seguinte ordem:
- primeiro o primeiro nó
- depois o último
- depois o segundo
- depois o penúltimo
- e assim sucessivamente…
sem modificar a estrutura da lista (sem alterar ponteiros, sem criar nova lista) e sem
armazenar todos os elementos em um vetor.
Dica: você pode usar recursão ou uma combinação de ponteiros, mas lembre-se de não
perder a generalidade para listas de qualquer tamanho.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char letra;
    struct node *prox;
}No;

No *inseri_no(No *lista, char x);
void imprime_alternado(No *lista, int count);
void libera_lista(No *lista);
void checa_tam(No *lista, int *count);

int main(){
    
    int n count = 0;
    scanf("%d", &n);
    
    No *lista = NULL;
    char x;
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        lista = inseri_no(lista, x)
    }
    
    checa_tam(lista, &count);
    imprime_alternado(lista);
    libera_lista(lista);    
    
    return 0;
}

void imprime_alternado(No *lista, int count){
    
    No* aux = lista;
    
    if((count % 2) == 0){
        c
    }
}

void checa_tam(No *lista, int *count){
    
    No *aux = lista;
    while(aux->prox != NULL){
        aux = aux->prox;
        (*count)++;
    }
    
    return count;
}

void libera_lista(No *lista){
    
    No *aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
}
