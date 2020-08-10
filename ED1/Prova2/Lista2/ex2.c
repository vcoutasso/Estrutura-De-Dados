/*
 * Escreva uma função que recebe duas listas simplesmente encadeadas, lista1 e lista2. Esta função deve retornar uma terceira lista, lista3.
 * Esta lista deve conter, para cada elemento de lista2, o número de vezes que este elemento ocorre em lista1.
 * Por exemplo, considerando lista1={9,4,6,2,2,3,1,5,5,0,7} e lista2={3,2,8,5,0}, a lista retornada pela função deve ter os números {1,2,0,2,1}.
 * NÃO É PERMITIDO UTILIZAR NENHUMA FUNÇÃO PRONTA DA LISTA. É permitido implementar suas próprias funções, ou resolver tudo no corpo da função pedida.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Element Element;

struct List {
	Element* front;
};

struct Element {
	int data;
	Element* next;
};

// Função solicitada no exercicio
List* countOccurences(List* list, List* list2);

List* newList() {
	List* list = malloc(sizeof(List));

	list->front = NULL;

	return list;
}

int length(List* list) {
	if (list == NULL) {
		printf("Error! List is NULL.\n");
		return 0;
	}
	else {
		Element* aux = list->front;
		int len = 0;

		while (aux != NULL) {
			++len;
			aux = aux->next;
		}

		return len;
	}
}

void push_front(int data, List* list) {
	Element* e = malloc(sizeof(Element));

	e->data = data;

	if (list->front == NULL) {
		e->next = NULL;
	}
	else {
		e->next = list->front;
	}

	list->front = e;
}

List* countOccurences(List* list, List* list2) {
	List* result = newList();
	Element* aux;
	Element* aux2 = list2->front;
	int i, iterations = length(list2);
	int count;

	for (i = 0; i < iterations; ++i) {
		aux = list->front;
		count = 0;
		while (aux != NULL) {
			if (aux->data == aux2->data)
				++count;
			aux = aux->next;
		}
		push_front(count, result);
		aux2 = aux2->next;
	}

	return result;
}

void printList(List* list) {
	Element* aux = list->front;

	while (aux != NULL) {
		printf("%d ", aux->data);
		aux = aux->next;
	}
	printf("\n");
}

int main() {
	int lista1[] = {9, 4, 6, 2, 2, 3, 1, 5, 5, 0, 7};
	int lista2[] = {3, 2, 8, 5, 0};

	List* list1 = newList();
	List* list2 = newList();

	int i;

	for (i = 0; i < sizeof(lista1) / sizeof(int); ++i)
		push_front(lista1[i], list1);

	for (i = 0; i < sizeof(lista2) / sizeof(int); ++i)
		push_front(lista2[i], list2);

	List* list3 = countOccurences(list1, list2);

	printList(list3);

	return 0;
}
