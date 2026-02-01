/*Pedro Henrique Cardoso - 11202321449
exercicio 12

12. Escreva um programa que simula o jogo “Pedra, Papel e Tesoura” entre dois jogadores. O
programa deve ler as escolhas e indicar o vencedor.
Exemplo de Entrada:
Jogador A (Pedra, Papel, Tesoura): Pedra
Jogador B (Pedra, Papel, Tesoura): Tesoura
Exemplo de Sa´ıda:
Jogador A Venceu!

*/

#include <stdio.h>
#include <string.h>

int main(){
    
    char escolhaA[10], escolhaB[10];
    
    printf("Jogador A (Pedra, Papel, Tesoura): ");
    scanf("%s", escolhaA);
    printf("Jogador B (Pedra, Papel, Tesoura): ");
    scanf("%s", escolhaB);
    
    if(strcmp(escolhaA, "Pedra") == 0){
        if(strcmp(escolhaB, "Pedra") == 0){
            printf("Empate\n");
        }else if(strcmp(escolhaB, "Papel") == 0){
            printf("Jogador B venceu\n");
        }else if(strcmp(escolhaB, "Tesoura") == 0){
            printf("Jogador A venceu\n");
        }else{
            printf("Escolha invalida para jogador B\n");
        }
    }else if(strcmp(escolhaA, "Papel") == 0){
        if(strcmp(escolhaB, "Pedra") == 0){
            printf("Jogador A venceu\n");
        }else if(strcmp(escolhaB, "Papel") == 0){
            printf("Empate\n");
        }else if(strcmp(escolhaB, "Tesoura") == 0){
            printf("Jogador B venceu\n");
        }else{
            printf("Escolha invalida para jogador B\n");
        }
    }else if(strcmp(escolhaA, "Tesoura") == 0){
        if(strcmp(escolhaB, "Pedra") == 0){
            printf("Jogador B venceu\n");
        }else if(strcmp(escolhaB, "Papel") == 0){
            printf("Jogador A venceu\n");
        }else if(strcmp(escolhaB, "Tesoura") == 0){
            printf("Empate\n");
        }else{
            printf("Escolha invalida para jogador B\n");
        }
    }else{
        printf("Escolha invalida para jogador A");
    }    
    
    return 0;
}
