/*Pedro Henrique Cardoso - 11202321449
exercicio 9

9. Defina uma estrutura chamada Ponto para representar coordenadas (x, y) no plano cartesiano. Crie uma vari´avel desse tipo e inicialize-a com valores (3, 5) e imprima os valores das
coordenadas.
Exemplo de Sa´ıda:
Ponto: (3, 5)
*/

#include <stdio.h>

typedef struct ponto{
    int x;
    int y;
}coordenadas;

int main(){
    
    coordenadas ponto;
    ponto.x = 3;
    ponto.y = 5;
    
    printf("Ponto: (%d, %d)", ponto.x, ponto.y);
    
    return 0;
}
