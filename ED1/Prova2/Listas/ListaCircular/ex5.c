
/*
 * Escreva um programa para resolver o problema de Josephus. Neste problema, há um certo número de pessoas em um círculo esperando serem executadas. A cada passo, pula-se um número aleatório de pessoas e a próxima é executada,
 * sempre seguindo na mesma direção. Este processo continua até sobrar apenas uma pessoa, a qual é dada liberdade.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct CircularList CircularList;
typedef struct Element Element;

struct CircularList {
	Element* front;
};

struct Element {
	int data;
	Element* next;
};

CircularList* newCircularList() {
	CircularList* list = malloc(sizeof(CircularList));

	list->front = NULL;

	return list;
}

void push(int data, CircularList* list) {
	Element* e = malloc(sizeof(Element));

	e->data = data;

	if (list->front == NULL) {    // Se a lista estiver vazia
		list->front = e;
		e->next = e;
	}
	else {
		Element* aux = list->front;

		while (aux->next != list->front)
			aux = aux->next;

		aux->next = e;
		e->next = list->front;
	}

}

// Itera pela lista e retira o elemento em que cair na posicao count
// Retorna zero quando a lista esta vazia
int pop(CircularList* list, int count) {

	// Se a lista não estiver vazia
	if (list->front != NULL) {
		int data;

		// Se houver apenas um elemento
		if (list->front == list->front->next) {
			data = list->front->data;

			free(list->front);

			list->front = NULL;

			return data;
		}
		// Se houver mais de um elemento
		else if (list->front != list->front->next) {
			Element *aux = list->front->next;

			if (count == 0) {
				Element *first = list->front;
				while (aux->next != list->front)
					aux = aux->next;

				// Ultimo elemento antes de voltar ao comeco da fila
				aux->next = first->next;
				list->front = first->next;

				data = first->data;

				free(first);

				return data;
			}
			// Se o elemento a ser removido nao for list->front
			else {
				Element *prev = list->front;
				int i = 1;

				while (i != count) {
					++i;
					aux = aux->next;
					prev = prev->next;
				}

				prev->next = aux->next;

				// Redefine o começo da lista para continuar contagem onde parou
				list->front = prev;

				data = aux->data;

				free(aux);

				return data;
			}
		}
	}

	return 0;
}

int length(CircularList* list) {
	int len = 0;

	if (list->front != NULL) {
		Element* aux = list->front;
		++len;

		while (aux->next != list->front) {
			++len;
			aux = aux->next;
		}
	}

	return len;
}

int main() {
	CircularList* list = newCircularList();
	int num, i;
	int r;

	srand(time(NULL));

	printf("Informe a quantidade de pessoas no circulo: ");
	scanf("%d", &num);

	if (num > 0) {
		for (i = 1; i <= num; ++i)
			push(i, list);

		// Num passa a representar o valor maximo que podera ser obtido aleatoriamente
		num *= 2;

		printf("Gerando numeros aleatorios entre 0 e %d...\n\n", num-1);

		setbuf(stdin, NULL);

		while (length(list) != 1) {
			//printf("Pressione ENTER para executar uma vitima...");
			//getchar();
			r = rand() % num;
			i = pop(list, r);
			printf("Voce executou a pessoa de numero %d!\n", i);
		}
		printf("\nA pessoa de numero %d sobreviveu todas as rodadas!\n", pop(list, 0));
	}
	else
		printf("Nao ha ninguem no circulo!\n");



	return 0;
}
