/*Pedro Henrique Cardoso - 11202321449

Exercício 25 – Separar lista de caracteres em vogais e consoantes
Usando a mesma estrutura de lista simplesmente encadeada sem nó cabeça, implemente
uma função que receba uma lista de caracteres e a separe em duas novas listas:
- lista V contendo apenas os nós cujo campo letra é vogal (a, e, i, o, u, maiúsculas ou
minúsculas)
- lista C contendo o restante (consoantes e outros caracteres)
A função deve:
- reaproveitar os nós existentes, apenas rearranjando os ponteiros
- retornar (por parâmetros) os ponteiros para o início das listas V e C
- deixar a lista original vazia (ponteiro inicial NULL)
Mostre um exemplo de entrada e saída usando uma lista representando a palavra
"ProgRamAcao".

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char letra;
    struct node *prox;
}No;

char *ler_texto();
No *insere_no(No *lista, char x);
void separa_vog_con(No **lista, No **v, No **c);
void imprime_lista(No *lista);
void libera_lista(No *lista);

int eh_vogal(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
}

int main(){
    char *str = ler_texto();
    
    No *lista = NULL;
    No *v = NULL;
    No *c = NULL;

    int i = 0; 
    while(str[i] != '\0'){
        lista = insere_no(lista, str[i]);
        i++;
    }
    
    printf("Lista original: ");
    imprime_lista(lista);
    printf("\n");

    separa_vog_con(&lista, &v, &c);

    printf("Lista vogais: ");
    imprime_lista(v);
    printf("\n");

    printf("Lista consoantes: ");
    imprime_lista(c);
    printf("\n");
    
    libera_lista(v);
    libera_lista(c);
    
    return 0;
}

char *ler_texto(){
    int capacidade = 12, tamanho = 0;
    
    char *str = (char *)malloc(capacidade);
    if (!str)
        return NULL;
    
    int c;
    while((c = getchar()) != '\n' && c != EOF){
        
        str[tamanho] = c;
        tamanho++;
        
        if(tamanho >= capacidade - 1){
            capacidade *= 2;
            char *temp = realloc(str, capacidade);
            if(!temp){
                free(str);
                return NULL;
            }
            str = temp;
        }
    }
    
    str[tamanho] = '\0';
    return str;
}

No *insere_no(No *lista, char x){
    No *novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria\n");
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

void separa_vog_con(No **lista, No **v, No **c){
    if(*lista == NULL)
        return;

    No *aux = *lista;
    *lista = aux->prox;
    aux->prox = NULL;

    if(eh_vogal(aux->letra)){
        if(*v == NULL){
            *v = aux;
        } else {
            No *p = *v;
            while(p->prox != NULL) p = p->prox;
            p->prox = aux;
        }
    } else {
        if(*c == NULL){
            *c = aux;
        } else {
            No *p = *c;
            while(p->prox != NULL) p = p->prox;
            p->prox = aux;
        }
    }

    separa_vog_con(lista, v, c);
}

void imprime_lista(No *lista){
    if(lista == NULL)
        return;
    printf("%c ", lista->letra);
    imprime_lista(lista->prox);
}

void libera_lista(No *lista){
    while(lista != NULL){
        No *aux = lista;
        lista = lista->prox;
        free(aux);
    }
}
