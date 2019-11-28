/*
 * Escreva uma função RECURSIVA que receba uma árvore binária e imprima todos os valores contidos nela em ordem DECRESCENTE.
 */

#include <stdio.h>

void printTree(Tree *t) {
	if (t->right != NULL)
		printTree(t->right);

	printf(t->data);

	if (t->left != NULL)
		printTree(t->left);
}
