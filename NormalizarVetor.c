/*Pedro Henrique Cardoso - 11202321449

Exercício 18 – Normalização de dados em vetor
Em processamento de dados, é comum normalizar um vetor para que todos os valores
fiquem entre 0 e 1, usando a fórmula:
v_norm[i] = (v[i] - min) / (max - min)
Implemente uma função que receba um vetor de float e seu tamanho e normalize os dados
no próprio vetor, isto é, alterando os valores originais. A função deve:
1. Encontrar o menor e o maior valor do vetor.
2. Aplicar a normalização em todos os elementos.
3. Tratar o caso em que min == max (por exemplo, deixando todos os elementos iguais a
0.0).
Após a implementação, exemplifique a chamada da função e a situação antes/depois da
normalização.
*/

#include <stdio.h>
#include <stdlib.h>

void normaliza(float vetor[], int tamanho);

int main(){
    
    float vetor[5] = {1.1, 2.2, 2.9, 5.8, 4.1};
    printf("vetor original = ");
    for (int i = 0; i < 5; i++)
        printf("%.1f ", vetor[i]);
    printf("\n");
        
    normaliza(vetor, 5);
    printf("vetor normalizado = ");
    for (int i = 0; i < 5; i++)
        printf("%.1f ", vetor[i]);
    printf("\n");
    
    return 0;
}

void normaliza(float vetor[], int tamanho){
    
    float max, min;
    max = min = vetor[0];
    
    for(int i = 0; i < tamanho; i++){
        
        if(vetor[i] < min)
            min = vetor[i];
            
        if(vetor[i] > max)
            max = vetor[i];
    }
    
    if(min == max){
        for(int i = 0; i < tamanho; i++)
            vetor[i] = 0.0;
    }else{
        for(int i = 0; i < tamanho; i++)
            vetor[i] = (vetor[i] - min) / (max - min);
    }    
}
