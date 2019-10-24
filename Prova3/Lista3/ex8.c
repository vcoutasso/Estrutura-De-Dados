/*
 * Escreva uma função recursiva para inserir um elemento em uma lista simplesmente encadeada.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

struct List {
    int data;
    List *next;
};

void insereElemento(List *list, int data) {
    if (list == NULL) {
        list = malloc(sizeof(List));
        list->data = data;
        list->next = NULL;
    }
    else if (list->next == NULL) {
        List *l = malloc(sizeof(List));
        l->data = data;
        l->next = NULL;
        list->next = l;
    }
    else
        insereElemento(list->next, data);
}
