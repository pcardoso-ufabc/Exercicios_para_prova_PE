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
    
    int n, count = 0;
    scanf("%d", &n);
    
    No *lista = NULL;
    char x;
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        lista = inseri_no(lista, x);
    }
    
    checa_tam(lista, &count);
    imprime_alternado(lista, count);
    libera_lista(lista);    
    
    return 0;
}

void imprime_alternado(No *lista, int count) {

    if (lista == NULL || count <= 0)
        return;

    No *aux1 = lista;

    No *aux2 = lista;
    for (int i = 1; i < count; i++)
        aux2 = aux2->prox;

    if (aux1 == aux2) {
        printf("%c ", aux1->letra);
        return;
    }

    printf("%c ", aux1->letra);

    printf("%c ", aux2->letra);

    imprime_alternado(lista->prox, count - 2);
}

void checa_tam(No *lista, int *count){
    *count = 0;
    No *aux = lista;
    while (aux != NULL) {
        (*count)++;
        aux = aux->prox;
    }
}

void libera_lista(No *lista){
    
    No *aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
}

No *inseri_no(No *lista, char x){
    
    No* novo = NULL;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria para novo No");
        exit(1);
    }
    
    novo->letra = x;
    novo->prox = NULL;
    
    if(lista == NULL)
        return novo;
        
    No *aux = lista;
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return lista;
}
