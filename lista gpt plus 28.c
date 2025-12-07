/*Pedro Henrique Cardoso - 11202321449

Exercício 28 – Filtragem de funcionários por salário em listas com nó cabeça
Considere a seguinte estrutura de nó para uma lista simplesmente encadeada com nó
cabeça:
typedef struct node {
int id;
double salario;
struct node *prox;
} No;
typedef No* Lista;
E uma função auxiliar Lista criarCabeca(); que cria um nó cabeça (sentinela) com campos
arbitrários e ponteiro prox = NULL.
Implemente uma função:
Lista filtrarFuncionarios(Lista headOriginal, double salario_minimo);
que deve:
1. Percorrer a lista ligada headOriginal (com nó cabeça).
2. Permanecer em headOriginal apenas os funcionários cujo salario seja maior ou igual a
salario_minimo.
3. Remover da lista original todos os nós com salario < salario_minimo e colocá-los em uma
nova lista headFiltrados, também com nó cabeça recém-criado.
4. Retornar o ponteiro para headFiltrados.
Requisitos:
- Reaproveitar nós (apenas rearranjando ponteiros).
- Não perder o nó cabeça original.
- Não criar nós de funcionário novos (apenas o nó cabeça da lista retornada).
Mostre ainda um exemplo de cenário:
- Lista original: funcionários com salários 2500.0, 1800.0, 3200.0, 1500.0
- salario_minimo = 2000.0
- Lista original após a filtragem → contém apenas 2500.0 e 3200.0
- Lista retornada → contém 1800.0 e 1500.0.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int id;
double salario;
struct node *prox;
}No;
typedef No* Lista;

Lista criarCabeca();
Lista insere_no(Lista funcionario, int id, double salario);
void imprime_lista(Lista lista);
Lista filtrarFuncionarios(Lista headOriginal, double salario_minimo);
void libera_lista(Lista lista);

int main(){
    
    int n, id;
    double salario;
    double salario_minimo = 2000.0;
    scanf("%d", &n);
    
    Lista funcionarios = criarCabeca();
    
    for(int i = 0; i < n; i++){
        scanf("%d %lf", &id, &salario);
        funcionarios = insere_no(funcionarios, id, salario);
    }
    
    Lista func_minimo = filtrarFuncionarios(funcionarios, salario_minimo);
    
    printf("Funcionario que recebem acima do salario minimo: \n");
    imprime_lista(funcionarios);
    
    printf("Funcionarios que recebem abaixo do salario minimo: \n");
    imprime_lista(func_minimo);
    
    libera_lista(funcionarios);
    libera_lista(func_minimo);
    
    return 0;
}

Lista criarCabeca(){
    
    Lista headLista = NULL;
    headLista = (Lista)malloc(sizeof(No));
    if(headLista == NULL){
        printf("Erro ao alocar memoria para cabeca");
        exit(1);
    }
    
    headLista->id = -1;
    headLista->salario = -1.0;
    headLista->prox = NULL;
    
    return headLista;
}

Lista insere_no(Lista funcionario, int id, double salario){
    
    Lista novo = NULL;
    novo = (Lista)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria para novo no");
        exit(1);
    }
    
    novo->id = id;
    novo->salario = salario;
    novo->prox = NULL;
    
    Lista aux = funcionario;
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return funcionario;
}

void imprime_lista(Lista lista){
    
    Lista aux = lista;
    aux = aux->prox;
    
    while(aux != NULL){
        printf("(Funcionario %d recebe %.1lf) ", aux->id, aux->salario);
        if(aux->prox != NULL)
            printf("-> ");
        aux = aux->prox;
    }
    printf("\n");
}

Lista filtrarFuncionarios(Lista headOriginal, double salario_minimo){
    
    Lista func_minimo = criarCabeca();
    
    No* atualO = headOriginal->prox;
    No* anteriorO = headOriginal;
    No* ultimoN = func_minimo;
    
    while(atualO != NULL){
        
        if(atualO->salario < salario_minimo){
            
            anteriorO->prox = atualO->prox;
            atualO->prox = NULL;
            ultimoN->prox = atualO;
            ultimoN = atualO;
            atualO = anteriorO->prox;
        }else{
            anteriorO = atualO;
            atualO = atualO->prox;
            
        }
    }
    
    return func_minimo;
}

void libera_lista(Lista lista){
    
    Lista aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
    }
}
