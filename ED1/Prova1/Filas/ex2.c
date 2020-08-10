/*
 * Escreva um programa para organizar a fila de um banco. Nesta fila, as pessoas com mais de 60 anos, grávidas e portadoras de necessidades especiais devem ser atendidas antes.
 * Ao final do processo, imprima a fila na ordem correta
 * Nota: A fila preferencial implementada ignora a ordem de chegada entre atendimento preferencial e normal, colocando todas as pessoas da fila de atendimento preferencial na frente da fila normal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <stdbool.h>

typedef struct Queue Queue;
typedef struct Element Element;

struct Queue {
    Element* front;
    Element* back;
};

struct Element {
    bool pref;      // preferencial
    int num;
    Element* next;
};

Queue* newQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL;
    q->back = NULL;

    return q;
}

Element* newElement() {
    Element* e = malloc(sizeof(Element));

    return e;
}

void push(bool pref, int num, Queue* q) {
    Element* e = newElement();

    e->pref = pref;
    e->num = num;
    e->next = NULL;

    if (q->front == NULL && q->back == NULL) {
        q->front = e;
        q->back = e;
    }
    else {
        q->back->next = e;
        q->back = e;
    }
}

int pop(Queue* q) {
    Element* aux = newElement();

    aux = q->front;
    q->front = q->front->next;
    int num = aux->num;

    free(aux);

    if (q->front == NULL) {
        q->back = NULL;
    }

    return num;
}

void printQueue(Queue* q) {
    Queue *aux = newQueue();
    char prefix;
    int num;

    aux = q;
    clear();

    printw("Encerrando fila e imprimindo estado atual..\n\n\n");

    while (aux->front != NULL) {
        if (aux->front->pref)
            prefix = 'P';
        else
            prefix = 'N';


        printw("%c%d\n", prefix, pop(aux));
    }
    refresh();
}

// Similar a push() mas com um Element que ja foi criado anteriormente
void pushElement(Element* e, Queue* q) {
    if (q->front == NULL && q->back == NULL) {
        q->front = e;
        q->back = e;
    }
    else {
        q->back->next = e;
        q->back = e;
    }
}

// Itera pelos elementos de src e passa o endereco de memoria de cada um para a Queue dest. Ao chegar no fim de src, libera o ponteiro
void pushQueueIntoQueue(Queue* src, Queue* dest) {
    while (src->front != NULL) {
        pushElement(src->front, dest);
        src->front = src->front->next;      // Se usar pop() o ponteiro pro elemento sera liberado e nao sera possivel acessar a memoria
    }
    free(src);
}


int main() {
    Queue* normalQ = newQueue();
    Queue* prefQ = newQueue();
    Queue* finalQ = newQueue();

    int prefCount = 1, normalCount = 1;
    char input;

    initscr();

    do {
        clear();
        printw("----------Bem vindo ao Banco do FIFO----------\n\n");
        printw("Necessita de atendimento preferencial? (y/n): ");
        refresh();
        input = getchar();

        if (input == 'y') {
            printw("Sua senha eh: P%d\n", prefCount);
            push(true, prefCount, prefQ);
            prefCount++;
        }
        else if (input == 'n') {
            printw("Sua senha eh: N%d\n", normalCount);
            push(false, normalCount, normalQ);
            normalCount++;
        }
        else
            continue;       // Caso contrario, vai pra proxima iteracao e, consequentemente, encerra o loop

        printw("Pressione qualquer tecla para continuar..");
        refresh();
        getchar();


    } while(input == 'y' || input == 'n');

    pushQueueIntoQueue(prefQ, finalQ);
    pushQueueIntoQueue(normalQ, finalQ);

    printQueue(finalQ);

    printw("\n\nPressione qualquer tecla para sair..");
    refresh();
    getchar();

    endwin();
    return 0;
}
