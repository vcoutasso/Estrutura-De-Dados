/*
 * Dada a raiz de uma árvore binária de busca, escreva uma função que calcule a sua altura - o número de nós da raiz
 * até o nó folha mais distante, onde iremos percorrer o caminho mais longo.
 */

#include <stdio.h>

int height(Tree *t) {

	if (t == NULL)
		return 0;

	int left = height(t->left);
	int right = height(t->right);

	if (left > right)
		return 1 + left;

	return 1 + right;
}
