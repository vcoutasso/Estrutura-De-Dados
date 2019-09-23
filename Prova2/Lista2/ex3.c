/*
 * Escreva uma função que receba uma lista duplamente encadeada não circular e inverta a ordem de seus elementos, SEM ALOCAR NOVOS ELEMENTOS, NEM LIBERAR MEMÓRIA DOS EXISTENTES.
 */

#include <stdio.h>
#include <stdlib.h>

void reverse(List* list) {
	if (list != NULL) {
		if (list->front != NULL) {
			Element* firstElement = list->front;
			Element* aux = list->front;
			Element* prev;

			while (aux->next != NULL)
				aux = aux->next;

			// O começo agora aponta para o final
			list->front = aux;
			prev = aux->prev;

			while (aux != NULL) {
				aux->prev = aux->next;
				aux->next = prev;
				aux = prev;
				if (prev != NULL)
					prev = prev->prev;
			}
			// O final aponta para o começo
			list->back = firstElement;
		}
		else
			printf("Error! List front is NULL.\n");
	}
	else
		printf("Error! List is NULL.\n");
}
