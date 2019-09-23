/*
 * Escreva uma função para verificar a integridade de uma lista duplamente encadeada circular.
 */

#include <stdio.h>
#include <stdlib.h>

// Conta a quantidade de elementos percorrendo a lista pelos dois sentidos. Em uma lista íntegra, o tamanho deve ser o mesmo.
// Se encontrar um link quebrado, a lista for invalida ou obter tamanhos diferentes, retorna -1. Caso contrário, retorna 1 indicando que é uma lista circular válida.
int checkIntegrity(List* list) {

	if (list != NULL) {
		int length2 = 1;
		int length1 = 1;

		if (list->front != NULL) {
			Element* e = list->front->next;

			while (e != list->front) {
				++length1;
				e = e->next;

				if (e == NULL)
					return -1;
			}

			e = list->front->prev;

			while (e != list->front && e != NULL) {
				++length2;
				e = e->prev;

				if (e == NULL)
					return -1;
			}
		}
		else {
			printf("Error! List front is NULL.\n");
			return -1;
		}

		if (length1 == length2)
			return 1;
		else
			return -1;
	}
	else {
		printf("Error! List is NULL.\n");
		return -1;
	}
}
