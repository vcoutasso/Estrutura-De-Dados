/*
 * Implementar um deque (do inglês double-ended queue). Nesta estrutura de dados, os elementos podem ser inseridos e retirados ou no fim ou no começo da lista.
 */

#include <stdio.h>
#include <stdlib.h>

#define NULL_DEQUE_ERR		printf("Error! Deck is NULL.\n");
#define MEM_ALLOC_ERR		printf("Error! Could not allocate memory.\n");
#define EMPTY_DEQUE_ERR		printf("Error! Deque is empty.\n");

typedef struct Deque Deque;
typedef struct Element Element;

struct Deque {
	Element* front;
	Element* back;
};

struct Element {
	int data;
	Element* next;
	Element* prev;
};

Deque* newDeque() {
	Deque* deque = malloc(sizeof(Deque));

	if (deque != NULL) {
		deque->front = NULL;
		deque->back = NULL;

		return deque;
	}
	else {
		MEM_ALLOC_ERR
		return NULL;
	}
}

int back(Deque* deque) {
	if (deque != NULL) {
		if (deque->back != NULL)
			return deque->back->data;
		else {
			printf("Error! Deque back is NULL.\n");
			return 0;
		}
	}
	else {
		NULL_DEQUE_ERR
		return 0;
	}
}

void push_back(int data, Deque* deque) {
	if (deque != NULL) {
		Element *e = malloc(sizeof(Element));

		if (e != NULL) {
			e->data = data;
			e->next = NULL;

			// Se estiver vazio back também apontará para NULL, mas idealmente apenas uma verificação é necessária pois Deque vazio deve ser a única condição para front apontar para NULL.
			if (deque->front == NULL) {
				e->prev = NULL;
				deque->front = e;
			} else {
				deque->back->next = e;
				e->prev = deque->back;
			}

			// back agora aponta para o novo elemento.
			deque->back = e;

		}
		else
			MEM_ALLOC_ERR
	}
	else
		NULL_DEQUE_ERR
}

void pop_back(Deque* deque) {
	if (deque != NULL) {
		if (deque->back != NULL) {
			// Se for o ultimo elemento do Deque
			if (deque->back->prev == NULL) {
				free(deque->back);

				// Estado inicial do Deque. Indica que está vazio.
				deque->back = NULL;
				deque->front = NULL;
			} else {
				Element *aux = deque->back;

				deque->back = deque->back->prev;
				// Agora é o ultimo elemento do Deque, então deve apontar para NULL.
				deque->back->next = NULL;

				free(aux);
			}
		}
		else
			EMPTY_DEQUE_ERR
	}
	else
		NULL_DEQUE_ERR
}

int front(Deque* deque) {
	if (deque != NULL) {
		if (deque->front != NULL)
			return deque->front->data;
		else {
			printf("Error! Deque front is NULL.\n");
			return 0;
		}
	}
	else {
		NULL_DEQUE_ERR
		return 0;
	}
}

void push_front(int data, Deque* deque) {
	if (deque != NULL) {
		Element *e = malloc(sizeof(Element));

		if (e != NULL) {
			e->data = data;
			// Primeiro elemento do Deque. Não há nada que o anteceda.
			e->prev = NULL;

			// Se estiver vazio
			if (deque->front == NULL) {
				deque->back = e;
				e->next = NULL;
			}
			else {
				e->next = deque->front;
				deque->front->prev = e;
			}

			deque->front = e;
		}
		else
			MEM_ALLOC_ERR
	}
	else
		NULL_DEQUE_ERR
}

void pop_front(Deque* deque) {
	if (deque != NULL) {
		if (deque->front != NULL) {
			// Se for o ultimo elemento do Deque
			if (deque->front->next == NULL) {
				free(deque->front);

				deque->front = NULL;
				deque->back = NULL;
			} else {
				Element *aux = deque->front;

				// aux->next passa a ser o primeiro elemento do Deque, fazendo com que nada o anteceda.
				deque->front = deque->front->next;
				deque->front->prev = NULL;

				free(aux);
			}
		}
		else
			EMPTY_DEQUE_ERR
	}
	else
		NULL_DEQUE_ERR
}


int main() {
	Deque* deque = newDeque();
	int i;

	for (i = 0; i<10; i++)
		push_back(i, deque);

	printf("Deque back to front (push_back): \n");

	for (i = 0; i<10; i++) {
		printf("%d ", back(deque));
		pop_back(deque);
	}

	printf("\n");

	for (i = 0; i<10; i++)
		push_front(i, deque);

	printf("\nDeque front to back (push_front): \n");

	for (i = 0; i<10; i++) {
		printf("%d ", front(deque));
		pop_front(deque);
	}

	printf("\n");

	return 0;
}
