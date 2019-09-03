/*
 *  Escreva uma função push para uma pilha de números inteiros que só aceite inserir um novo elemento:
 *
 *  se a pilha estiver vazia, ou
 *  se o novo elemento for par E o elemento no fundo da pilha também for par, ou
 *  se o novo elemento for ímpar E o elemento no fundo da pilha também for ímpar;
 *
 *  Se as condições forem atendidas, a função insere o novo elemento da pilha e retorna 0.
 *  Se as condições não forem atendidas, a função não modifica a pilha e retorna -1.
 *  NÃO É PERMITIDO PERCORRER A PILHA, NEM USAR LAÇOS DE QUALQUER TIPO, INCLUINDO RECURSÃO
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue Queue;
typedef struct Element Element;

// Funcao solicitada no enunciado da questao
int push(int data, Queue *q);

struct Queue {
    Element* front;
    Element* back;
};

struct Element {
    int data;
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

    // Todo novo elemento aponta para NULL para sinalizar que é o elemento mais recente
    e->next = NULL;

    return e;
}

// Funcao para dar push efetivamente, para evitar a necessidade de repetir codigo em push()
void pusha(Element* e, Queue* q) {
    // Se nao apontar para NULL, atualiza o endereco de next. Caso contrario nao precisa, pois nao ha nenhum elemento la para apontar para o novo.
    if (q->back != NULL)
        q->back->next = e;
    q->back = e;
}

int push(int data, Queue* q) {
    Element* e = newElement();
    e->data = data;

    // Se a fila estiver vazia
    if (q->front == NULL && q->back == NULL) {
        pusha(e, q);
        // Se a pilha estava vazia antes de inserir o elemento, front e back devem apontar para e
        q->front = e;
    }
    // Se data for par e elemento apontado por q->front tambem for par
    else if (data % 2 == 0 && q->front->data % 2 == 0) {
        pusha(e, q);
    }
    // Se data for impar e elemento apontado por q->front tambem for impar
    else if (data % 2 != 0 && q->front->data % 2 != 0) {
        pusha(e, q);
    }
    // Caso contrario, nao modifica a pilha, libera a memoria do elemento criado e retorna -1
    else {
        free(e);
        return -1;
    }

    // Elemento inserido, retorna 0
    return 0;
}

void printQueue(Queue* q) {
    Element* it  = q->front;

    while (it != NULL) {
        printf("%d\n", it->data);
        it = it->next;
    }
}

int main() {
    Queue* q = newQueue();

    push(2, q);
    push(2, q);
    push(2, q);
    push(2, q);
    push(2, q);
    push(2, q);
    push(2, q);
    printQueue(q);

    return 0;
}
