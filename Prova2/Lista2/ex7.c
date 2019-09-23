/*
 * Escreva uma função para verificar se uma lista simplesmente encadeada de números inteiros está ordenada (em ordem crescente).
 * Ela deve retornar 1 se esta afirmação for verdadeira e 0 se for falsa. Considere que elementos repetidos podem existir na lista, e isto não invalida a ordem.
 * Por exemplo, uma lista {1,3,5,6,6,8,10} está ordenada.
 */

#include <stdio.h>
#include <stdlib.h>

int isSorted(List* list) {
	Element* aux = list->front->next;
	int num = list->front->data;

	while (aux != NULL) {
		if (num < aux->data)
			return 0;

		num = aux->data;
		aux = aux->next;
	}

	return 1;
}
