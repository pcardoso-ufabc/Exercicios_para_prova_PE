/*Pedro Henrique Cardoso - 11202321449
exercicio 2

2. Escreva um programa em C que leia dois n´umeros inteiros e imprima sua soma.
Exemplo de Entrada:
Digite o primeiro numero: 5
Digite o segundo numero: 7
Exemplo de Sa´ıda:
Resultado: 12 */

#include <stdio.h>

int main(){
    
    int num1, num2, soma;
    
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    
    soma = num1 + num2;
    printf("Resultado: %d", soma);
}
