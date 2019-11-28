/*
 Escreva uma função RECURSIVA que receba uma árvore binária e imprima em ordem decrescente todos os nós que NÃO são folhas.
 */

#include <stdio.h>

void printDescendingTreeButNotItsLeaves(Tree *t) {
	if (t->right != NULL)
		printDescendingTreeButNotItsLeaves(t->right);

	if (t->right != NULL || t->left != NULL)
		printf("%d ", t->data);

	if (t->left != NULL)
		printDescendingTreeButNotItsLeaves(t->left);
}
