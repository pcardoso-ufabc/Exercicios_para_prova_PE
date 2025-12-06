/*Pedro Henrique Cardoso - 11202321449

Exercício 24 – Contagem de nós e profundidade máxima via recursão
Ainda com a estrutura No anterior, escreva uma função recursiva:
int contaNos(No *lista);
que retorne o número de nós da lista.
Depois, escreva uma versão alternativa:
int contaNosLimitado(No *lista, int limite);
que interrompe a contagem e retorna -1 se o número de nós ultrapassar o valor limite.
Mostre exemplos de chamadas em que:
- a lista tem menos nós que o limite → retorna o número exato;
- a lista tem mais nós que o limite → retorna -1.


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char letra;
    struct node *prox;
}Lista;

Lista *insere_no(Lista *lista, char x);
int contaNos(Lista *lista);
int contaNosLimitado(Lista *lista, int limite);
void imprime_lista(Lista* lista);
void libera_lista(Lista* lista);


int main(){
    
    int n, m;
    scanf("%d", &n);
    int limite = 3;
    
    char x;
    Lista *lista = NULL;
    for(int i = 0; i < n; i++){
        scanf(" %c", &x);
        lista = insere_no(lista, x);
    }
    
    printf("quantidade exata = %d\n", n);
    m = contaNos(lista);
    printf("quantidade retornada 'contaNos' = %d\n", m);
    m = contaNosLimitado(lista, limite);
    printf("quantidade retornada 'contaNosLimitado' = %d\n", m);
    
    printf("Lista: ");
    imprime_lista(lista);
    libera_lista(lista);
    
    return 0;
}
int contaNos(Lista *lista){
    
    Lista *aux = lista;
    if(aux == NULL)
        return 0;
        
    return 1 + contaNos(aux->prox);     
}
int contaNosLimitado(Lista *lista, int limite){
    
    if (lista == NULL)
        return 0;

    if (limite == 0)
        return -1;

    int res = contaNosLimitado(lista->prox, limite - 1);

    if (res == -1)
        return -1;

    return 1 + res;
}

void imprime_lista(Lista* lista){
    
    Lista *aux = lista;
    if(aux == NULL)
        return;
    printf("%c ", aux->letra);
    imprime_lista(aux->prox);
}

void libera_lista(Lista* lista){
    
    Lista *aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
}

Lista *insere_no(Lista *lista, char x){
    
    Lista *novo = NULL;
    novo = (Lista*)malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Erro ao alocar novo no");
        exit(1);
    }
    
    novo->letra = x;
    novo->prox = NULL;
    
    if(lista == NULL)
        return novo;
        
    Lista *aux = lista;
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return lista;
}
