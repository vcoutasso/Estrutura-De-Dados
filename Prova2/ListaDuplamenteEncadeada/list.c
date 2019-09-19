#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Element Element;

struct List {
		Element* front;
		Element* back;
};

struct Element {
		int data;
		Element* prev;
		Element* next;
};

Element* newElement(int data) {
	Element* e = malloc(sizeof(Element));

	e->data = data;

	return e;
}

List* newList() {
	List* l = malloc(sizeof(List));

	l->front = NULL; // Elemento mais antigo
	l->back = NULL; // Elemento mais recente

	return l;
}

void push(int d, List *l, int index) {
		Element* e = newElement(d);
		Element* aux = l->front->next;

		int count = 1;

		// 0 indica o comeco da lista (front)
		if (index == 0) {
			l->front->prev = e;
			e->next = l->front;
			e->prev = NULL;
			l->front = e;
		}
		// -1 indica o fim da lista (back)
		else if (index == -1) {
			l->back->next = e;
			e->prev = l->back;
			l->back = e;
			e->next = NULL;
		}
		// Verificar se uma inserção em index é valida
		else {
			while (count != index) {
				aux = aux->next;
				count++;
			}
			aux->prev->next = e;
			e->prev = aux->prev;

			e->next = aux;
			aux->prev = e;
		}

		if (l->front == NULL && l->back == NULL) // Se a lista estiver vazia
			l->front = e;
						

		// Novo elemento fica no final da lista
		l->back = e;
}

int pop(List *l, int index) {
	if (l->front != NULL) {

		data = l->front->data

		return data;
	}
	
	// Retorna 0 se a lista estiver vazia
	return 0;
}

int main() {

	return 0;
}
