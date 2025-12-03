/*Pedro Henrique Cardoso - 11202321449

Exercício 4 – Operadores & e * e endereço de memória
Implemente um programa em C que:
1. Declare uma variável int x e um ponteiro int *px = NULL;
2. Leia um valor inteiro do teclado e armazene em x.
3. Faça px apontar para x.
4. Imprima:
- o valor de x
- o endereço de x
- o valor armazenado em px
- o valor de *px
Exemplo de saída (endereços ilustrativos):
Valor de x: 42
Endereco de x (&x): 0x7ffca1234abc
Valor de px (endereco armazenado): 0x7ffca1234abc
Valor de *px: 42
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int x;
    int *px = NULL;
    
    scanf("%d", &x);
    px = &x;
    
    printf("%d\n", x);
    printf("%d\n", &x);
    printf("%d\n", px);
    printf("%d\n", *px);
    
    return 0;
}
