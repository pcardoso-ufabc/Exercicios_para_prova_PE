/*Pedro Henrique Cardoso - 11202321449

Exercício 5 – Troca de valores com passagem por referência
Implemente uma função em C que troque os valores de dois inteiros usando ponteiros:
void troca(int *x, int *y);
Em main:
1. Leia dois inteiros a e b.
2. Chame troca(&a, &b);
3. Imprima os valores de a e b antes e depois da chamada, mostrando que foram trocados.
Exemplo (entrada e saída):
Entrada:
10 20
Saida:
Antes da troca: a = 10, b = 20
Depois da troca: a = 20, b = 10
*/

#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y);

int main(){
    
    int a, b;
    scanf("%d %d", &a, &b);
    printf("a e b originais: %d e %d\n", a, b);
    
    troca(&a, &b);
    printf("a e b alterados: %d e %d\n", a, b);
    
    return 0;
}

void troca(int *x, int *y){
    
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
