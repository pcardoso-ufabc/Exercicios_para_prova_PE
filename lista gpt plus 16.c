/*Pedro Henrique Cardoso - 11202321449

Exercício 16 – Segundo menor e segundo maior valor em vetor
A análise de extremos nem sempre se resume apenas ao menor e maior valor: em alguns
contextos (por exemplo, ranking de atletas), também é útil saber o segundo menor e o
segundo maior.
Implemente uma função que receba um vetor de inteiros e seu tamanho e determine:
- o menor valor
- o segundo menor valor
- o maior valor
- o segundo maior valor
Todos devem ser retornados por meio de parâmetros passados por referência. Caso o vetor
não tenha elementos suficientes (por exemplo, tamanho < 2), a função deve apenas retornar
sem alterar os parâmetros.
Após a implementação, exemplifique a chamada da função, mostrando também as
declarações de variáveis necessárias.
*/

#include <stdio.h>
#include <stdlib.h>

void segundo_maior_menor(int lista[], int tamanho, int *segMen, int *segMaior, int *menor, int *maior);

int main(){
    
    int segMen, segMaior, menor, maior;
    
    int lista[3] = {1, 2, 3};
    segundo_maior_menor(lista, 3, &segMen, &segMaior, &menor, &maior);
    
    printf("Menor: %d\n", menor);
    printf("Segundo menor: %d\n", segMen);
    printf("Maior: %d\n", maior);
    printf("Segundo maior: %d\n", segMaior);
    
    return 0;
}

void segundo_maior_menor(int lista[], int tamanho, int *segMen, int *segMaior, int *menor, int *maior){
    
    if(tamanho < 2)
        return;
        
    *menor = *segMen = 9999;
    *maior = *segMaior = -9999;
    
    for(int i = 0; i < tamanho; i++){
    
        if (lista[i] < *menor){
            *segMen = *menor;
            *menor = lista [i];
        }else if (lista[i] < *segMen && lista[i] != *menor) {
            *segMen = lista[i];
        }
    
        if (lista[i] > *maior){
            *segMaior = *maior;
            *maior = lista[i];
        }else if (lista[i] > *segMaior && lista[i] != *maior) {
            *segMaior = lista[i];
        }

    }
}
