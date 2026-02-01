/*Pedro Henrique Cardoso - 11202321449
exercicio 7

7. Crie uma fun¸c˜ao que gere n n´umeros inteiros aleat´orios no intervalo de [a, b] (inclusive) e
retorne esses n´umeros em um vetor.
Exemplo de Entrada:
n: 5
a: 1
b: 10
2
Exemplo de Sa´ıda (com valores aleat´orio):
Vetor gerado: [3, 7, 1, 9, 5]
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, n;
    scanf("%d %d %d", &n, &a, &b);
    
    int vetor[n];
    for(int i = 0; i < n; i++){
        srand(i);
        vetor[i] = a + rand() % (b - a + 1);
    }
    
    printf("Vetor gerado: [");
    for(int i = 0; i < n - 1; i++)
        printf("%d, ", vetor[i]);
    printf("%d]\n", vetor[n-1]);
    
}
