/*
 * Escreva uma função que recebe uma lista duplamente encadeada contendo números float, e que retorne uma segunda lista duplamente encadeada contendo a diferença entre os números da primeira lista.
 * Por exemplo, ao receber uma lista contendo {8; 5; 7; 3; 2; 10; 5}, a lista retornada conteria {-3; 2; -4; 1; 8; -5}.
 * Não é permitido utilizar nenhuma função das listas, apenas manipulá-las diretamente pelos ponteiros dos elementos.
 */

#include <stdio.h>
#include <stdlib.h>

void push_front(int data, List* list) {
	Element* e = malloc(sizeof(Element));
	e->data = data;

	if (list->front != NULL) {
		list->front->prev = e;
	}
	e->next = list->front;
	list->front = e;
}

List* diff(List* list) {
	List* result = malloc(sizeof(List));
	result->front = NULL;

	Element* aux = list->front;

	while (aux->next != NULL)
		aux = aux->next;

	while (aux->prev != NULL) {
		push_front(aux->prev->data - aux->data, result);
		aux = aux->prev;
	}

	return result;
}
