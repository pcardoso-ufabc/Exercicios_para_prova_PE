/*Pedro Henrique Cardoso - 11202321449
exercicio 8

8. O que faz o seguinte trecho de c´odigo em C quando executado? Qual ´e a sa´ıda e os principais
conceitos de ponteiros envolvidos no programa?

#include <stdio.h>
void funcX(int v[], int tam);
 int main() {
 int vet[] = {4,9,12};
 int i, *ptr;
 ptr = vet;
 funcX(vet, 3);
 for (i = 0; i < 3; i++) {
 printf("%d ", *ptr++);
 }
 printf("\n");
 return 0;
 }
 void funcX(int v[], int tam){
 v[0] = v[0] + v[2];
 v[2] = v[0] - v[2];
 v[0] = v[0] - v[2];
 }
*/

Na main() e declarado um vetor de inteiros com 3 valores. Em seguida é criado um ponteiro de inteiro que
aponta para o primeiro elemento do vetor vet[]. 
Em seguida é chamada a função funcX, passando o vetor e a quantidade de elementos. Apesar da função não
valor, por se tratar do tipo void, a mesma altera o vetor diretamente, ou seja, os valores presentes na main
também sçao alterados.
Para imprimir o vetor é ultilizado um for, que a cada interação faz com que o ponteiro aponte para o proximo
elemento do vetor.

