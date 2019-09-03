/*
 * Implemente uma função que receba uma fila e a reverta. Novos elementos NÃO podem ser alocados, apenas ponteiros.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef struct Element Element;

// Função solicitada no enunciado do exercicio
void reverse(Stack **s);

struct Stack {
    Element* top;
};

struct Element {
    int data;
    Element* next;
};

Stack* newStack() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;

    return s;
}

Element* newElement(int data) {
    Element *e = malloc(sizeof(Element));
    e->data = data;

    return e;
}

void push(int data, Stack *s) {
    Element *e = newElement(data);
    e->next = s->top;
    s->top = e;
}

void pushElement(Element *e, Stack *s) {
    e->next = s->top;
    s->top = e;
}

int pop(Stack *s) {
    Element *aux = s->top;

    if (aux != NULL) {
        int data = aux->data;
        s->top = aux->next;
        free(aux);
        return data;
    }
    return -1;
}

void printStack(Stack *s) {
    Element *it = s->top;

    while (it != NULL) {
        printf("%d\n", it->data);
        it = it->next;
    }
}

void reverse(Stack **s) {
    Stack *aux = newStack();
    Element *it = (*s)->top;
    Element cp;     // Mantem uma copia do endereco do proximo elemento a ser utilizado

    while (it != NULL) {
        // Faz a copia do valor atual de it
        cp = *it;
        // Na primeira execucao, o primeiro valor a ser colocado na pilha tera next apontando para NULL, ja que este eh o valor inicial. Nas proximas execucoes, next aponta para top (elemento anterior).
        it->next = aux->top;
        // Atualiza o topo da pilha.
        aux->top = it;
        // Itera mais uma vez pela pilha original, mas usando o endereco guardado em cp pois o valor de it foi alterado
        it = cp.next;
    }

    // Inverte a ordem dos elementos da pilha passada por parametro.
    // O que é feito aqui é fazer com que s aponte para aux. Se aux for liberado, nao havera nada na pilha
    *s = aux;
    // Libera memoria
    free(it);
}

int main() {
    Stack *s = newStack();
    push(1, s);
    push(2, s);
    push(3, s);
    push(4, s);
    push(5, s);
    push(6, s);
    push(7, s);
    push(8, s);
    push(9, s);

    printf("Imprimindo a pilha no estado atual..\n");
    printStack(s);

    printf("Pressione enter para inverter e imprimir a pilha..");
    getchar();

    reverse(&s);
    printStack(s);

    return 0;
}
