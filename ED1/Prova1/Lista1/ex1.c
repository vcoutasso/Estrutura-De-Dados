/*
 * Implemente uma função que receba uma fila e a reverta. Novos elementos NÃO podem ser alocados, apenas ponteiros.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
typedef struct Element Element;

// Função solicitada no enunciado do exercicio
void reverse(Queue *q);

struct Queue {
    Element* front;
    Element* back;
};

struct Element {
    int data;
    Element* next;
};

Queue* newQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->back = NULL;

    return q;
}

Element* newElement(int data) {
    Element *e = malloc(sizeof(Element));
    e->data = data;

    return e;
}

void push(int data, Queue *q) {
    Element *e = newElement(data);

    e->next = NULL;

    if (q->front == NULL && q->back == NULL)
        q->front = e;
    else
        q->back->next = e;

    q->back = e;
}
/*
void pushElement(Element *e, Queue *s) {
    e->next = s->top;
    s->top = e;
}*/

int pop(Queue *q) {
    Element *aux = q->front;
    int data = aux->data;

    q->front = q->front->next;

    // Se a fila estiver vazia
    if (q->front == NULL)
        q->back = NULL;

    free(aux);

    return data;
}

void printQueue(Queue *q) {
    Element *it = q->front;

    while (it != NULL) {
        printf("%d\n", it->data);
        it = it->next;
    }
}

void reverse(Queue *q) {
    Element *prev = q->front;
    Element *it = q->front->next;
    Element *next = q->front->next->next;

    q->back = q->front;

    while (it->next != NULL) {
        it->next = prev;
        prev = it;
        it = next;
        next = next->next;
    }
    it->next = prev;
    q->front = it;

    q->back->next = NULL;
}

int main() {
    Queue *q = newQueue();
    push(1, q);
    push(2, q);
    push(3, q);
    push(4, q);
    push(5, q);
    push(6, q);
    push(7, q);
    push(8, q);
    push(9, q);

    printf("Imprimindo a fila no estado atual..\n");
    printQueue(q);

    printf("Pressione enter para inverter e imprimir a fila..");
    getchar();

    reverse(q);
    printQueue(q);

    return 0;
}
