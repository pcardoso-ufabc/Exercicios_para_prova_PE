/*Pedro Henrique Cardoso - 11202321449
exercicio 30

30. Identifique e corrija o erro no seguinte c´odigo de uma fun¸c˜ao de troca de valores usando
ponteiros:
Listing 3: Fun¸c˜ao de troca incorreta
1 void troca(int *i, int *j) {
2 int *temp;
3 *temp = *i;
4 *i = *j;
5 *j = *temp;
6 }


*/

// O erro da função esta na linha 3, ao desreferênciar "temp", que neste momento ainda não está apontando para um enderço, o mesmo não sera
// não seria capaz de "guardar" o valor de *j. Correção:  

void troca(int *i, int *j) {
int temp;
temp = *i;
*i = *j;
*j = *temp;
}
