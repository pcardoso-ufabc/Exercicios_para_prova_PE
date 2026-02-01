/*Pedro Henrique Cardoso - 11202321449
exercicio 4

4. Fa¸ca um programa que lˆe um n´umero N e imprime caracteres ’#’ em um formato de triˆangulo
de lado N.
Exemplo de Entrada:
N: 5
Exemplo de Sa´ıda:
# # # # #
# # # #
# # #
# #
#
*/

#include <stdio.h>

int main(){
    
    int N;
    scanf("%d", &N);
    
    for(; N > 0; N--){
        for(int i = N; i > 0; i-- )
            printf("# ");   
        printf("\n");
    }
    
    return 0;
}
