/*
* Escreva um programa para gerenciar reservas de passagens de avião. O programa deve mostrar um menu com as seguintes opções: reservar uma passagem,
* cancelar uma passagem, verificar se uma passagem está reservada para uma determinada pessoa, e mostrar os passageiros com passagem reservada.
* A informação deve ser armazenada em uma lista (com os nomes em ordem alfabética). Assuma que cada pessoa pode reservar apenas uma passagem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

#define MAX_SIZE 64
#define ENTER 13
#define PRESS refresh();printw("\nPressione ENTER para continuar...\n"); refresh(); getchar();

typedef struct List List;
typedef struct Element Element;

struct List {
	Element* front;
};

struct Element {
	char* name;
	Element* next;
};

List* newList() {
	List* l = malloc(sizeof(List));

	l->front = NULL;

	return l;
}

// Retorna o indice que contem a string name. Se nao encontrar, retorna -1
int indexOf(List* l, char* name) {
	Element* aux = l->front;
	int i = 0;

	// Converte para uppercase
	while (*(name+i) != '\0') {
		*(name+i) = toupper(*(name+i));
		++i;
	}

	i = 0;

	while(aux != NULL) {
		if (strcmp(name, aux->name) == 0)
			return i;
		++i;
		aux = aux->next;
	}
	return -1;
}

// Insere nova entrada na lista em ordem alfabética
void push(List* l, char* name) {
	Element* e = malloc(sizeof(Element));
	int i = 0;

	// Converte para uppercase
	while (*(name+i) != '\0') {
		*(name+i) = toupper(*(name+i));
		++i;
	}

	if (indexOf(l, name) != -1) {
		printw("Erro! Ja existe uma reserva nesse nome!\n");
		PRESS
		return;
	}

	e->name = name;

	if (l->front == NULL) {
		e->next = l->front; // NULL
		l->front = e;
	}
	else { // Se a lista não estiver vazia, coloca a entrada na posição correta (ordem alfabética)

		if (strcmp(name, l->front->name) < 0) {
			e->next = l->front;
			l->front = e;
		}
		else if (strcmp(name, l->front->name) == 0) {
			printw("Erro! Ja existe uma reserva no nome de %s\n", name);
			return;
		}

		else {
			Element* prev = l->front;
			Element* aux = l->front->next;

			while (aux != NULL) {
				if (strcmp(name, aux->name) < 0)  { // Se name vier antes, na ordem alfabética, que aux->name
					prev->next = e;
					e->next = aux;
					return;
				}
				else if (strcmp(name, l->front->name) == 0) {
					printw("Erro! Ja existe uma reserva no nome de %s\n", name);
					return;
				}
				// Se não, continua tentando
				aux = aux->next;
				prev = prev->next;
			}
			// Se chegou ate aqui, a nova entrada pertence ao final da lista
			prev->next = e;
			e->next = aux;
		}
	}
}

char* pop(List* l, int index) {
    char* name;
    int cont = 1;

	if (index == -1) {
		printw("Nao existe reserva nesse nome.\n");
		PRESS
		return NULL;
	}
    else if (index == 0) {
		if (l->front != NULL) {
			Element* aux = l->front;
	        name = l->front->name;
	        l->front = l->front->next;
	        free(aux);

	        return name;
		}
		else
			return NULL;
    }
    else {
	    Element* prev = l->front; // Elemento que aponta para o elemento que sera removido
	    Element* aux = l->front->next; // Elemento que sera removido

        while (cont < index) {
            aux = aux->next;
            prev = prev->next;
            ++cont;
        }

        name = aux->name;
        prev->next = aux->next;

        free(aux);
        return name;
    }
	printw("Reserva cancelada com sucesso!\n");
	PRESS
}


void printList(List* l) {
	Element* aux = l->front;

	clear();
	printw("Lista de passageiros com reserva cadastrada: \n\n");

	while(aux != NULL) {
		printw("%s\n", aux->name);
		aux = aux->next;
	}

	printw("\n\nPressione qualquer tecla para continuar..");
	refresh();
	getchar();
}


void printMenu() {
	clear();
	printw("--------------------Sistema de gerenciamento de passagens--------------------\n\n");
	printw("Escolha uma das opcoes abaixo:\n\n");
	printw(" 1 - Reservar uma passagem.\n");
	printw(" 2 - Cancelar uma reserva.\n");
	printw(" 3 - Verificar se uma reserva foi efetuada.\n");
	printw(" 4 - Mostrar passageiros com passagem reservada.\n");
	printw(" 5 - Sair do sistema.\n\n");
	printw("Opcao desejada: ");
	refresh();
}

int main() {
	List* l = newList();;

	char option;
	char *name;

	initscr();

	do {
		printMenu();
		option = getch();

		if (option - '0' >= 0 && option - '0' <= 9)
			printw("\nPressione Enter para confirmar a opcao %d", option - '0');
		else
			printw("\n\nOpcao invalida. Pressione qualquer tecla para continuar");
		refresh();

		if (getchar() == ENTER) {
			switch(option) {
				case '1':
					name = malloc(sizeof(char) * MAX_SIZE);
					printw("\n\nDigite seu nome para realizar a reserva: ");
					refresh();
					getnstr(name, MAX_SIZE);
					push(l, name);

					break;
				case '2':
					name = malloc(sizeof(char) * MAX_SIZE);
					printw("\n\nDigite seu nome para cancelar a reserva: ");
					refresh();
					getnstr(name, MAX_SIZE);
					pop(l, indexOf(l, name));
					break;
				case '3':
					name = malloc(sizeof(char) * MAX_SIZE);
					printw("\n\nDigite seu nome para procurar a reserva: ");
					refresh();
					getnstr(name, MAX_SIZE);
					if(indexOf(l, name) != -1)
						printw("Reserva encontrada em nome de %s!\n", name);
					else
						printw("Nao existe reserva em nome de %s!\n", name);
					PRESS
					break;
				case '4':
					printList(l);
					break;
				default:
					break;
			}
		}
		else
			option = 'q';
	} while(option != '5');

	endwin();

	return 0;
}
