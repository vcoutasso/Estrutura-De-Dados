#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Element Element;

struct List {
    Element* back;
    Element* front;
};

struct Element {
    int data;
    Element* next;
};

List* newList() {
    List* l = malloc(sizeof(List));

    l->back = NULL;
    l->front = NULL;

    return l;
}

void push_back(List* l, int data) {
    Element* e = malloc(sizeof(Element));

    if (l->front == NULL)
        l->front = e;

    e->data = data;
    l->back = e;
    // Aponta para null pois é o elemento mais recente
    e->next = NULL;

}

int pop_front(List* l) {
    Element* aux = l->front;

    if (l->front != NULL) {
        int data = l->front->data;

        l->front = l->front->next;

        if(l->front == NULL) // Se a lista estiver vazia
            l->back = NULL;

        free(aux);

        return data;
    }
    else
        return 0;
}

int size(List* l) {
    Element* aux = l->front;
    int size = 0;

    while (aux != NULL) {
        ++size;
        aux = aux->next;
    }

    return size;
}

int empty(List *l) {
    if (l->front == NULL)
        return 1;
    return 0;
}

void push(List* l, int data, int pos) {
    Element* e = malloc(sizeof(Element)); // Elemento a ser inserido
    Element* aux1 = l->front->next; // Elemento para qual e->next vai apontar
    Element* aux2 = l->front; // Aponta para a posicao que sera inserido
    int count = 0;

    if (pos > size(l)) {
        printf("Error! Position %d is out of bounds.\n", pos);
        return;
    }

    e->data = data;

    if (pos == 0) {
        e->next = l->front;
        l->front = e;
    }
    else {
        while (count != pos) {
            aux1 = aux1->next;
            aux2 = aux2->next;
            ++count;
        }
        aux2->next = e;
        e->next = aux1;
    }

}

int pop(List* l, int pos) {
    Element* aux1 = l->front; // Elemento que aponta para o elemento que sera removido
    Element* aux2 = l->front->next; // Posicao do elemento que sera removido
    int data;
    int cont = 0;

    while (cont != pos) {
        aux1 = aux1->next;
        aux2 = aux2->next;
        ++cont;
    }

    data = aux2->data;
    aux1->next = aux2->next;

    free(aux2);
    return data;
}

void printList(List* l) {
    Element* aux = l->front;

    while(aux != NULL) {
        printf("%d\n", aux->data);
        aux = aux->next;
    }
}


int main() {
    List* l = newList();
    push(l, 1, 0);
    push(l, 2, 0);
    push(l, 3, 0);
    push(l, 4, 0);
//    printList(l);
//    pop(l, 2);
//    printList(l);

    return 0;
}
