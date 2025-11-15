/*Pedro Henrique Cardoso - 11202321449
exercicio 1

11. Leia 2 n´umeros a e b. Calcule a solu¸c˜ao da equa¸c˜ao de primeiro grau ax + b = 0, que vale
x = (−b/a), se a ̸= 0. Imprima mensagens apropriadas para os casos de a = 0 (sem solu¸c˜ao
ou infinitas solu¸c˜oes).
Exemplo de Entrada 1:
a: 2
b: 4
Exemplo de Sa´ıda 1:
x = -2.00
Exemplo de Entrada 2:
a: 0
b: 0
Exemplo de Sa´ıda 2:
A equacao admite infinitas solucoes.

*/

#include<stdio.h>

void solucao(int a, int b);

int main(){
    
    int a, b;
    scanf("%d %d", &a, &b);
    
    solucao(a, b);
}

void solucao(int a, int b){
    
    if(a != 0){
        int x = (-b/a);
        printf("%d", x);
    }else if(a == 0 && b == 0){
        printf("A equacao admite infinitas solucoes.");
    }else{
        printf("A equacao nao possui solucoes");
    }
    
}
