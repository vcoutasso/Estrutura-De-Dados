/* Escreva uma função RECURSIVA que receba como parâmetro uma árvore binária.
 * Essa árvore armazena números inteiros em seus nós.
 * Essa função deverá retornar o resultado da soma de todos os números PARES armazenados na árvore.
 * Não é permitido alocar novos elementos, criar ponteiros nem utilizar laços.
 */

#include <stdio.h>

int pairSum(Tree *t, int sum) {
	if (t->left != NULL)
		sum = pairSum(t->left, sum);

	if (t->data % 2 == 0)
		sum += t->data;

	if (t->right != NULL)
		sum = pairSum(t->right, sum);

	return sum;
}
