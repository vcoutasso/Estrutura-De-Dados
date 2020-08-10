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

void insereElemento(List **list, int data) {
    if (*list == NULL) {
        *list = malloc(sizeof(List));
        (*list)->data = data;
        (*list)->next = NULL;
    }
    else if ((*list)->next == NULL) {
        List *l = malloc(sizeof(List));
        l->data = data;
        l->next = NULL;
        (*list)->next = l;
    }
    else
        insereElemento(&(*list)->next, data);
}

void printList(List *list) {
    if (list == NULL)
        printf("Error! List is NULL\n");
    else {
        printf("%d ", list->data);
        if (list->next != NULL)
            printList(list->next);
    }
}

int main() {
    List **list = malloc(sizeof(List*));

    printList(*list);
    insereElemento(list, 1);
    insereElemento(list, 2);
    insereElemento(list, 3);
    insereElemento(list, 4);
    printList(*list);

}
