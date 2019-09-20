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

int length(List* l) {
    int len = 0;

    if (l->front != NULL) {
        Element* aux = l->front;

        while (aux != NULL) {
            len++;
            aux = aux->next;
        }
    }
    return len;
}

void push(int d, List *l, int index) {
    Element* e = newElement(d);

    // 0 indica o comeco da lista (front)
    if (index == 0) {
        if (l->front == NULL && l->back == NULL) // Se a lista estiver vazia
            l->back = e;


        if (l->front != NULL)
            l->front->prev = e;
        e->next = l->front;
        e->prev = NULL;
        l->front = e;
    }
        // -1 indica o fim da lista (back)
    else if (index == -1) {
        if (l->front == NULL && l->back == NULL) // Se a lista estiver vazia
            l->front = e;

        if (l->back != NULL)
            l->back->next = e;
        e->prev = l->back;
        l->back = e;
        e->next = NULL;
    }
    else {
        if (index < length(l)) {
            int count = 1;
            Element *aux = l->front->next;

            while (count != index) {
                aux = aux->next;
                count++;
            }
            aux->prev->next = e;
            e->prev = aux->prev;

            e->next = aux;
            aux->prev = e;
        }
    }

}

int pop(List *l, int index) {

    if (l->front != NULL) {
        Element* aux;
        int data;

        if (index == 0) {
            aux = l->front;
            data = aux->data;
            aux->next->prev = NULL;
            l->front = aux->next;

            if (l->front->next == NULL) // Se for o ultimo elemento que restou
                l->back = l->front;

            free(aux);
        }
        else if (index == -1 || index == length(l) - 1) {
            aux = l->back;
            data = aux->data;
            aux->prev->next = NULL;
            l->back = aux->prev;

            if (l->back->prev == NULL) // Se for o ultimo elemento que restou
                l->front = l->back;

            free(aux);
        }
        else {
            if (index < length(l)) {
                int count = 0;
                aux = l->front;

                while (count != index) {
                    count++;
                    aux = aux->next;
                }

                data = aux->data;

                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }
        }


        return data;
    }

    // Retorna 0 se a lista estiver vazia
    return 0;
}

// Percore a lista a partir do primeiro elemento e imprime todos os valores
void printList(List *l) {
    if (l->front != NULL) {
        Element* aux = l->front;
        while (aux != NULL) {
            printf("%d ", aux->data);
            aux = aux->next;
        }
    }
}


int main() {
    List* l = newList();

    push(0, l, 0);
    push(1, l, -1);
    push(3, l, -1);
    push(2, l, 2);
    push(4, l, 0);
	// 4 0 1 2 3
    pop(l, 0);
	// 0 1 2 3

    printList(l);
    printf("\nElements: %d\n", length(l));

    return 0;
}
