/*Pedro Henrique Cardoso - 11202321449
exercicio 23

23. Determine o valor final das vari´aveis e express˜oes dadas ap´os a execu¸c˜ao de um trecho de
c´odigo com ponteiros.
Listing 2: Opera¸c˜oes com ponteiros
1 int x = 10, y = 20;
2 int *p1;
3 int *p2;
4 p1 = &x;
5 p2 = &y;
6 (*p1)++;
Sa´ıda (Valores finais):

x: 11
y: 20
&x: endereço de x
&y: endereço de y
p1: endereço de x
p2: endereço de y
*p1 + *p2: 31
*(&x): 11
&(*p2): endereço de y


*/
