/*Pedro Henrique Cardoso - 11202321449
exercicio 1  

1. Faca um programa que receba trˆes notas e seus respectivos pesos, calcule e mostre a m´edia
ponderada.
Exemplo de Entrada:
Digite a nota 1 e seu peso: 7.0 2
Digite a nota 2 e seu peso: 8.0 3
Digite a nota 3 e seu peso: 9.0 5
Exemplo de Sa´ıda:
A media ponderada e: 8.2 */

#include <stdio.h>

typedef struct nota{
    float nota;
    int peso;
}NOTA;

int main(){
    
NOTA nota[3];
for(int i = 0; i < 3; i++){
    printf("Digite a nota %i e seu peso: ", i + 1);
    scanf("%f %d", &nota[i].nota, &nota[i].peso);
}

float soma_mp = 0.0;
int soma_peso = 0;

for(int i = 0; i < 3; i++){
    soma_mp = soma_mp + nota[i].nota * nota[i].peso;
    soma_peso = soma_peso + nota[i].peso;
}

float resultado = soma_mp / soma_peso;

printf("A media ponderada e: %.1f\n", resultado);

return 0;

}
