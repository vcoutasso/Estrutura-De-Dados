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
    int count = 0;


    e->data = data;

    if (pos == 0) {
        e->next = l->front;
        l->front = e;
        l->back = e;
    }
    else if (pos >= size(l)) {
        printf("Error! Position %d is out of bounds.\n", pos);
        return;
    }
    else if (pos == -1) { // Insere no final da lista
        e->next = NULL;
        if (l->back != NULL)
            l->back->next = e;
        l->back = e;
    }
    else {
        Element* aux1 = l->front->next; // Elemento para qual e->next vai apontar
        Element* aux2 = l->front; // Aponta para a posicao que sera inserido
        while (count != pos) {
            aux1 = aux1->next;
            aux2 = aux2->next;
            ++count;
        }
        aux2->next = e;
        e->next = aux1;
    }

    if (l->back == NULL)
        l->back = e;

}

int pop(List* l, int pos) {
    Element* prev = l->front; // Elemento que aponta para o elemento que sera removido
    Element* aux = l->front->next; // Elemento que sera removido
    int data;
    int cont = 1;

    if (pos >= size(l)) {
        if (pos == 0)
            printf("Error! List is empty.\n");
        else
            printf("Error! Position %d is out of bounds.\n", pos);
        return 0;
    }

    else if (pos == 0) {
        data = prev->data;
        l->front = aux;
        free(prev);

        return data;
    }
    else if (pos == -1) {
        while (cont < size(l) - 1) {
            aux = aux->next;
            prev = prev->next;
            ++cont;
        }

        data = aux->data;
        prev->next = NULL;

        free(aux);
        return data;
    }
    else {
        while (cont < pos) {
            aux = aux->next;
            prev = prev->next;
            ++cont;
        }

        data = aux->data;
        prev->next = aux->next;

        free(aux);
        return data;
    }
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
    push(l, 2, -1);
    push(l, 3, -1);
    push(l, 4, -1);
    push(l, 5, -1);
    pop(l, -1);
    printList(l);

    return 0;
}
