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

