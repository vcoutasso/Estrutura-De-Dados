#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
typedef struct Element Element;

struct Queue {
    Element* back;
    Element* front;
};

struct Element {
    int data;
    Element* next;
};


Queue* newQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->back = NULL;
    q->front = NULL;

    return q;
}

Element* newElement(int data) {
    Element* e = malloc(sizeof(Element));
    e->data = data;

    return e;
}

void push(int data, Queue *q) {
    Element* e = newElement(data);
    if (q->back == NULL && q->front == NULL) {      // Se a fila estiver vazia
        q->back = e  ;
        q->front = e;
        e->next = NULL;
    }
    else {
        q->back->next = e;       // Ultimo elemento aponta para o novo elemento
        q->back = e;             // Atualiza o ultimo elemento
        e->next = NULL;          // Faz com que aponte para nulo pois sera o ultimo elemento a ser retirado
    }
}

int pop(Queue *q) {
    int data = q->front->data;

    Element *aux = q->front;
    q->front = q->front->next;

    if (q->front->next == NULL) {        // Se a fila estiver vazia, reseta os ponteiros de back e front
        q->back = NULL;
        q->front = NULL;
    }

    free(aux);      // Libera memoria que nao sera mais utilizada

    return data;
}

void printQueue(Queue* q) {
    Queue *aux = q;
    while (aux->front != NULL) {
        printf("%d\n", aux->front->data);
        aux->front = aux->front->next;
    }
}

int main() {
    Queue *q = newQueue();

    push(1, q);
    push(1, q);
    printQueue(q);

    return 0;
}
