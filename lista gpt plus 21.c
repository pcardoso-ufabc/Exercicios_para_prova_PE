/*Pedro Henrique Cardoso - 11202321449

Exercício 21 – Leitura de string de tamanho desconhecido com realloc
Implemente uma função em C que leia do teclado uma linha de texto de tamanho
desconhecido, até encontrar \n, e retorne um ponteiro para uma string alocada
dinamicamente com o tamanho exato do texto (mais o \0).
Requisitos:
- Comece com um buffer pequeno (por exemplo, 8 caracteres).
- Vá aumentando o buffer com realloc sempre que estiver cheio.
- Não use gets (proibida); use getchar() ou lógica equivalente.
Após a implementação, mostre a declaração de variáveis e um exemplo de chamada à
função, guardando o ponteiro retornado em um char *.
*/

#include <stdio.h>
#include <stdlib.h>

char *ler_texto();

int main(){
    
    char *texto = ler_texto();
    
    printf("%s", texto);
    
    free(texto);
    return 0;
}

char *ler_texto(){

    int capacidade = 8, tamanho = 0;
    
    char *str = NULL; 
    str = (char *)malloc(capacidade * sizeof(char));
    if(str == NULL){
        printf("Erro ao alocar memoria para string\n");
        exit(1);
    }
    
    int c;
    while((c = getchar()) != '\n' && c != EOF){
        
        if(tamanho == capacidade - 1){
            
            capacidade = capacidade * 2;
            
            char *temp = NULL;
            temp = realloc(str, capacidade * sizeof(char));
            if(temp == NULL){
                printf("Erro ao alocar memoria \n");
                exit(1);
            }
            str = temp;
        }
        
        str[tamanho++] = c;
    }
    str[tamanho] = '\0';
    
    char *final = realloc(str, tamanho + 1);
    if(final == NULL)
        return str;
    
    return final;
}
