/*
 * Escreva uma função RECURSIVA que receba uma árvore binária, imprima todos os nós FOLHA, e retorne a quantidade
 * de nós folha contidos nesta árvore. Se a árvore for composta por apenas um nó, este também conta como folha.
 */

 #include <stdio.h>

 int printLeaves(Tree *t, int count) {
	 if (t->left != NULL)
	 	count = printLeaves(t->left, count);

	// Se for no folha;
	if (t->left == NULL && t->right == NULL) {
		printf("%d ", t->data);
		count++;
	}

	if (t->right != NULL)
		count = printLeaves(t->right, count);

	return count;
 }
