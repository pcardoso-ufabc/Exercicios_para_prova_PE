/*Pedro Henrique Cardoso - 11202321449

Exercício 17 – Índices do mínimo e do máximo
Em muitas aplicações, não basta saber apenas os valores mínimo e máximo de um vetor,
mas também onde eles aparecem.
Implemente uma função em C que receba um vetor de double e seu tamanho e determine:
- o valor mínimo e seu índice
- o valor máximo e seu índice
Os valores e índices devem ser retornados por referência.
Exemplo de uso (apenas ilustrativo no enunciado):
vetor = {2.5, -1.0, 7.2, 7.2, 0.0}
minimo = -1.0 (índice 1)
maximo = 7.2 (índice 2) // considere o primeiro índice em caso de empate
Mostre também a invocação da função e as declarações das variáveis usadas.
*/

#include <stdio.h>
#include <stdlib.h>

void encontrarMaxMix(double vetor[], int tamanho, double *maximo, double *minimo, int *indice_1, int *indice_2);

int main(){
    
    double vetor[5] = {2.5, -1.0, 7.2, 7.2, 0.0};
    double maximo, minimo;
    int indice_1, indice_2;
    
    encontrarMaxMix(vetor, 5, &maximo, &minimo, &indice_1, &indice_2);
    printf("minimo = %.1lf (indice %d)\n", minimo, indice_1);
    printf("maximo = %.1lf (indice %d)\n", maximo, indice_2);
    
    return 0;
}

void encontrarMaxMix(double vetor[], int tamanho, double *maximo, double *minimo, int *indice_1, int *indice_2){
    
    *minimo = *maximo = vetor[0];
    *indice_1 = *indice_2 = 0;
    for(int i = 0; i < tamanho; i++){
        
        if(vetor[i] < *minimo){
            *minimo = vetor[i];
            *indice_1 = i;
        }
        
        if(vetor[i] > *maximo){
            *maximo = vetor[i];
            *indice_2 = i;
        }        
    }
}
