/* Dada uma árvore binária, verifique se a mesma é uma árvore binária de busca.
 * Lembre que para que uma árvore binária seja de busca, para cada nó todos os valores dos nós em sua subárvore esquerda devem ser menores do que o valor do nó,
 * e todos os valores dos nós em sua subárvore direita devem ser maiores que o valor do nó.
 *
 * Escreva uma função que receba uma árvore binária e retorne 1 se ela for uma árvore binária de busca, e 0 se ela não for uma árvore binária de busca.
 * Lembre-se de que a condição deve valer para todas as sub-árvores.
 * DICA: Implementar funções para achar o menor e o maior valor de cada (sub)árvore pode ajudar a deixar a sua solução mais clara.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree Tree;

struct Tree {
	int data;
	Tree *left;
	Tree *right;
};

Tree* newTree(int n) {
	Tree *t = malloc(sizeof(Tree));
	t->data = n;

	return t;
}

void insert(Tree* t, int data) {
	if (t == NULL)
		printf("Error: Tree is NULL\n");
	else {
		if (data < t->data) {
			if (t->left == NULL) {
				t->left = malloc(sizeof(Tree));
				t->left->data = data;
			}
			else
				insert(t->left, data);
		}
		else if (data > t->data) {
			if (t->right == NULL) {
				t->right = malloc(sizeof(Tree));
				t->right->data = data;
			}
			else
				insert(t->right, data);
		}
	}
}

void printTree(Tree* t) {
	if (t->left != NULL)
		printTree(t->left);

	printf("%d ", t->data);

	if (t->right != NULL)
		printTree(t->right);
}

int minVal(Tree *t, int min) {
	int minLeft, minRight;

	if (t->data < min)
		min = t->data;

	if (t->left != NULL)
		minLeft = minVal(t->left, min);
	else
		minLeft = min;

	if (t->right != NULL)
		minRight = minVal(t->right, min);
	else
		minRight = min;

	if (minLeft < minRight)
		return minLeft;

	return minRight;
}

int maxVal(Tree *t, int max) {
	int maxLeft, maxRight;

	if (t->data > max)
		max = t->data;

	if (t->left != NULL)
		maxLeft = minVal(t->left, max);
	else
		maxLeft = max;

	if (t->right != NULL)
		maxRight = minVal(t->right, max);
	else
		maxRight = max;

	if (maxLeft > maxRight)
		return maxLeft;

	return maxRight;
}


int isBinarySearchTree(Tree *t) {
	if (minVal(t->left, t->data) < t->data && maxVal(t->right, t->data) > t->data)
		return 1;

	return 0;

}

int main() {
	Tree *tree = newTree(4);

	insert(tree, 2);
	insert(tree, 1);
	insert(tree, 3);
	insert(tree, 7);
	insert(tree, 6);
	insert(tree, 5);
	insert(tree, 8);

	printTree(tree);

	if (isBinarySearchTree(tree))
		printf("\nEh arvore binaria de busca!\n");
	else
		printf("\nNao eh arvore binaria de busca!\n");

	// Modifica de forma que não seja mais uma arvore binaria de busca
	tree->right->data = 0;

	printTree(tree);

	if (isBinarySearchTree(tree))
		printf("\nEh arvore binaria de busca!\n");
	else
		printf("\nNao eh arvore binaria de busca!\n");

	return 0;
}
