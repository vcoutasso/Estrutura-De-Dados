#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH			20
#define REHASHING_THRESHOLD		0.3

typedef struct DataItem DataItem;
typedef struct HashTable HashTable;

int insert(HashTable**, char*);

struct DataItem {
	char *str;
};

struct HashTable {
	DataItem *data;
	int size;
	int items;
};

HashTable* newHashTable(int size) {
	HashTable *ht = malloc(sizeof(HashTable));
	ht->data = malloc(sizeof(DataItem) * size);

	ht->size = size;
	ht->items = 0;

	int i;

	for (i = 0; i < size; i++) {
		ht->data[i].str = malloc(sizeof(char) * MAX_STR_LENGTH);
		strcpy(ht->data[i].str, "\0");
	}

	return ht;
}

void rehash(HashTable **ht) {
	int i;
	HashTable *aux = *ht;

	*ht = newHashTable((*ht)->size * 2);

	for (i = 0; i < aux->size; i++) {
		if (strcmp(aux->data[i].str, "\0"))
			insert(ht, aux->data[i].str);
	}

	free(aux);
}

unsigned long hash(char *str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

int insert(HashTable **ht, char *str) {

	if ((*ht)->items + 1 > (int) (*ht)->size * REHASHING_THRESHOLD)
		rehash(ht);

	int pos = hash(str) % (*ht)->size;

	while (strcmp((*ht)->data[pos].str, "\0")) {
		if (!strcmp((*ht)->data[pos].str, str)) // Valor ja existe
			return -1;
		if (++pos == (*ht)->size)	// Sem espaço, volta para o começo
			pos = 0;
	}

	strcpy((*ht)->data[pos].str, str);
	(*ht)->items += 1;

	return pos;
}

void printHashTable(HashTable *ht) {
	int i;

	for (i = 0; i < ht->size; i++) {
		if (!strcmp(ht->data[i].str, "\0"))
			printf("- ");
		else
			printf("%s ", ht->data[i].str);
	}

	printf("\n");
}

int indexOf(HashTable *ht, char *str) {
	int pos = hash(str) % ht->size;
	int cont = 0;

	while (strcmp(ht->data[pos].str, "\0")) {
		if (!strcmp(ht->data[pos].str, str)) // Valor ja existe
			return pos;
		if (++pos == ht->size)	// Sem espaço, volta para o começo
			pos = 0;
		if (++cont == ht->size)
			break;
	}

	return -1;
}

int removeData(HashTable *ht, char *str) {
	int idx = indexOf(ht, str);

	if (idx != -1) {
		strcpy(ht->data[idx].str, "\0");
		ht->items -= 1;
		return 0;
	}

	return -1;
}


int main() {
	int size = 20;
	HashTable *ht = newHashTable(size);
	char word[MAX_STR_LENGTH];

	FILE *fp = fopen("lipsum.txt", "r");

	if (fp == NULL) {
		printf("Could not open file!\n");
		return 1;
	}

	while (fscanf(fp, "%s", word) == 1)
		insert(&ht, word);

	removeData(ht, "dictum");

	printHashTable(ht);

	return 0;

}
