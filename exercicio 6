/*Pedro Henrique Cardoso - 11202321449
exercicio 6

6. Crie uma fun¸c˜ao recursiva que leia N n´umeros inteiros e retorne o maior entre eles.
Exemplo de Entrada:
N = 2
Numero 1: 15
Numero 2: 7
Exemplo de Sa´ıda:
O maior numero e: 15
*/

#include <stdio.h>

int maior_numero(int N, int numeros[], int resultado);

int main(){
    
    int N;
    scanf("%d", &N);
    
    int numeros[N];
    for(int i = 0; i < N; i++){
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    int resultado = numeros[0];
    resultado = maior_numero(N, numeros, resultado);
    printf("O maior numero é: %d", resultado);
    
    return 0;
}

int maior_numero(int N, int numeros[], int resultado){
    if(N == 0){
        return resultado;
    }else{
        if(resultado < numeros[N - 1])
            resultado = numeros[N - 1];
        return maior_numero(N - 1, numeros, resultado);
    }
}
