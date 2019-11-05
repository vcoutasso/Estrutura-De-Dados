/*
 * Uma árvore deve ser criada com as palavras de um texto. Os elementos desta árvore devem contar, além da palavra, a quantidade de vezes que ela aparece no texto.
 * O programa deve se encerrar imprimindo as palavras presentes no texto (em ordem alfabética) e sua frequência.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

typedef struct Tree Tree;

struct Tree {
	Tree *left;
	Tree *right;
	int count;
	char str[MAX_LENGTH];
};

void format(char str[]) {
	int i = 0;
	for (; str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
		if (!isalpha(str[i])) {
			str[i] = '\0';
			break;
		}
	}
}

Tree* newTree(char str[]) {
	Tree *t = malloc(sizeof(Tree));

	format(str);
	strcpy(t->str, str);
	t->count = 1;

	return t;
}

void insert(Tree *t, char str[]) {
	format(str);
	if (t == NULL) {
		t = malloc(sizeof(Tree));
		strcpy(t->str, str);
		t->count = 1;
	}
	else {
		if (!strcmp(str, t->str))
			t->count++;
		else if(strcmp(str, t->str) < 0) {
			if (t->left == NULL) {
				t->left = malloc(sizeof(Tree));
				strcpy(t->left->str, str);
				t->left->count = 1;
			}
			else
				insert(t->left, str);
		}
		else {
			if (t->right == NULL) {
				t->right = malloc(sizeof(Tree));
				strcpy(t->right->str, str);
				t->right->count = 1;

			}
			else
				insert(t->right, str);
		}
	}
}

void printTree(Tree* t) {
	if (t != NULL) {
		printTree(t->left);
		printf("%s %d\n", t->str, t->count);
		printTree(t->right);
	}
}


int main() {
	FILE *fp;
	char word[MAX_LENGTH];

	fp = fopen("lipsum.txt", "r");

	if (fp == NULL) {
		printf("Could not open file!\n");
		return 1;
	}

	// Inicializa a arvore com a primeira palavra do arquivo.
	fscanf(fp, "%s", word);
	Tree* tree = newTree(word);

	while (fscanf(fp, "%s", word) == 1)
			insert(tree, word);

	printTree(tree);

	return 0;
}
