/*Pedro Henrique Cardoso - 11202321449

Quest˜ao 5: Filtragem de Dados - Aprovados e Reprovados
A filtragem e separa¸c˜ao de dados ´e uma tarefa comum em muitos sistemas, desde gerenciamento
de alunos at´e organiza¸c˜ao de invent´arios. Por exemplo, em um sistema educacional, separar alunos
aprovados de reprovados com base em um crit´erio dinˆamico (como uma m´edia definida) ´e uma
funcionalidade pr´atica.
Dada a estrutura No (com ID, nota e pr´oximo), implemente uma fun¸c˜ao que receba uma lista
simplesmente encadeada com n´o cabe¸ca A contendo dados de alunos e um valor media aprovacao
para o crit´erio de aprova¸c˜ao. O n´o cabe¸ca (o primeiro n´o da lista) serve apenas como um
marcador e n˜ao cont´em dados de aluno v´alidos (ID e nota s˜ao ignorados nele); ele apenas aponta
para o primeiro aluno da lista atrav´es do seu ponteiro pr´oximo. Em seguida, a fun¸c˜ao deve dividir
os alunos em duas listas:
• A lista A original (com seu n´o cabe¸ca) ser´a modificada para conter apenas os alunos aprovados
(nota maior ou igual a media aprovacao).
• Uma nova lista R (tamb´em com seu pr´oprio n´o cabe¸ca rec´em-criado) ser´a gerada para conter
os alunos reprovados (nota menor que media aprovacao).
A fun¸c˜ao deve retornar o ponteiro para o n´o cabe¸ca da nova lista R. Vocˆe pode usar fun¸c˜oes
auxiliares. Ao final da implementa¸c˜ao, exemplifique a chamada da fun¸c˜ao, mostrando tamb´em as
declara¸c˜oes das vari´aveis exigidas para sua correta utiliza¸c˜ao.
Para a resolu¸c˜ao da quest˜ao, considere a seguinte estrutura e fun¸c˜ao:

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int ID;
float nota;
struct node *prox;
} No;

typedef No* Lista;

Lista criarNoCabeca();
Lista inserir_no(Lista A, int id, float nota);
void filtrarAlunos(Lista A, Lista R, int media_aprovacao);
void imprime_lista(Lista lista);
void libera_lista(Lista lista);

int main(){
    
    int n, id;
    float nota;
    float media_aprovacao = 6.5;
    scanf("%d", &n);
    
    Lista A = criarNoCabeca();
    Lista R = criarNoCabeca();
    
    for(int i = 0; i < n; i++){
        scanf("%d %f", &id, &nota);
        A = inserir_no(A, id, nota);
    }
    
    filtrarAlunos(A, R, media_aprovacao);
    
    printf("\nAlunos aprovados:\n");
    imprime_lista(A);
    libera_lista(A);
    
    printf("\nAlunos reprovados:\n");
    imprime_lista(R);
    libera_lista(R);
    
    return 0;
}

Lista criarNoCabeca() {
    No* head = (No*)malloc(sizeof(No));
    if (head == NULL) {
        printf("Erro ao alocar mem´oria para o no cabe¸ca.\n");
        exit(1);
    }
    head->ID = -1; // ID arbitr´ario para o n´o cabe¸ca
    head->nota = -1.0; // Nota arbitr´aria para o n´o cabe¸ca
    head->prox = NULL;
    return head;
}

Lista inserir_no(Lista A, int id, float nota){
    
    Lista novo = NULL;
    novo = (Lista)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria para novo no");
        exit(1);
    }
    
    novo->ID = id;
    novo->nota = nota;
    novo->prox = NULL;
    
    Lista aux = A;
    while(aux->prox != NULL)
        aux = aux->prox;
        
    aux->prox = novo;
    return A;
}

void filtrarAlunos(Lista headA, Lista headR, int media_aprovacao){
    
    No* atualA = headA->prox;
    No* anteriorA = headA;
    No* ultimoR = headR;
    while (atualA != NULL) {
        if (atualA->nota < media_aprovacao) {
            anteriorA->prox = atualA->prox;
            atualA->prox = NULL;
            ultimoR->prox = atualA;
            ultimoR = atualA;
            atualA = anteriorA->prox;
        } else {
            anteriorA = atualA;
            atualA = atualA->prox;
        }
    }
}

void imprime_lista(Lista lista){
    
    Lista aux = lista ->prox;
    while(aux != NULL){
        printf("(ID: %d, NOTA: %.2f) ", aux->ID, aux->nota);
        if(aux->prox != NULL)
            printf("-> ");
        aux = aux->prox;
    }
}
void libera_lista(Lista lista){
    
    Lista aux = lista;
    while(lista != NULL){
        lista = lista->prox;
        free(aux);
        aux = lista;
        }
}
