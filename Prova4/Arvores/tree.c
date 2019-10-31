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

Tree* search(Tree* t, int data) {
	if (t == NULL)
		return NULL;
	else if (t->data == data)
		return t;
	else if (data < t->data)
		return search(t->left, data);

	return search(t->right, data);
}

int findMax(Tree* t) {
	if (t->right != NULL)
		return findMax(t->right);
	else
		return t->data;
}

int findMin(Tree* t) {
	if (t->left != NULL)
		return findMin(t->left);
	else
		return t->data;
}

void prune(Tree* root, Tree* t, int data) {
	if (search(t, data) == NULL)
		printf("Not found on tree!\n");
	//else if (root->data == data) {
//
	//}
	//else {
//
	//}
}


int main() {
	Tree *tree = newTree(4);

	int find = 4;

	insert(tree, 2);
	insert(tree, 1);
	insert(tree, 3);
	insert(tree, 7);
	insert(tree, 6);
	insert(tree, 5);
	insert(tree, 8);

	if (search(tree, find) != NULL)
		printf("Found %d on tree!\n", find);
	else
		printf("Could not find %d on tree!\n", find);

	printTree(tree);
	printf("\n");

	printf("Max: %d\nMin: %d\n", findMax(tree), findMin(tree));

	//prune(tree, tree, find);
	//printTree(tree);
	//printf("\n");


	return 0;
}
