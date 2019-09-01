/* Implementar uma calculadora pós-fixada (RPN) de 4 operações, onde apenas os valores numéricos podem ocupar a pilha.
 * Quando uma operação é realizada (através da chamada da função correspondente), os operandos são retirados da pilha e o resultado da operação é inserido nela.
 * Quando uma operação não conseguir ser executada, a pilha deve continuar no mesmo estado em que estava quando a função foi chamada.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <curses.h>

#define ESC         27
#define DELETE      127
#define ENTER       13

typedef struct Stack Stack;

void push(double data, Stack** s);

struct Stack {
    double data;
    Stack* next;
};

Stack* newStack() {
    Stack *s = malloc(sizeof(Stack));

    s->data = 0;
    s->next = NULL;

    return s;
}

Stack* newElement(double data) {
    Stack *s = malloc(sizeof(Stack));

    s->data = data;
    s->next = NULL;

    return s;
}

int countElements(Stack** s) {
    int count = 0;

    Stack* aux = *s;

    for (; aux->next != NULL; count++)
        aux = aux->next;

    return count;
}

int isEmpty(Stack** s) {
    if ((*s)->next == NULL)
        return 1;

    return 0;
}

int isFull(Stack** s) {
    if (countElements(s) == 4)
        return 1;

    return 0;
}

double pop(Stack** s) {
    Stack *aux = *s;
    double data = aux->data;

    if (!isEmpty(s)) { // If stack is not empty, proceed normally. If it is, don't change anything since the first position holds the default data value (0).
        (*s) = (*s)->next;
        free(aux);
    }

    return data;
}

void push(double data, Stack **s) {
    Stack *aux = newElement(data);

    if (isFull(s)) { // Remove oldest entry to make room for data
        double y = pop(s);
        double z = pop(s);
        double t = pop(s);
        pop(s);
        push(t, s);
        push(z, s);
        push(y, s);
    }

    aux->next = (*s);
    (*s) = aux;
}


void printStack(Stack** s) {
    double reg_value[4] = {0, 0, 0, 0};
    char reg_label[4] = {'X', 'Y', 'Z', 'T'}; // Stack order. X holds the most recent value
    int i = 0;
    int j = 0;

    // Retrieve values in order (LIFO)
    while(!isEmpty(s)) {
        reg_value[i] = pop(s);
        i++;
    }

    clear();

    for (j = 3; j >= 0; j--)
        printw("%c: %.4f\n", reg_label[j], reg_value[j]);

    refresh();

    while(i >= 0) {
        push(reg_value[i], s);
        i--;
    }
}

void rollDown(Stack** s) {
    double reg_value[4] = {0, 0, 0, 0};
    int i = 0;

    // Retrieve values in order (LIFO)
    while(!isEmpty(s)) {
        reg_value[i] = pop(s);
        i++;
    }

    push(reg_value[0], s);
    push(reg_value[3], s);
    push(reg_value[2], s);
    push(reg_value[1], s);

}

void swapXY(Stack** s) {
    double x = pop(s);
    double y = pop(s);

    push(x, s);
    push(y, s);
}

void add(Stack** s) {
    double a = pop(s);
    double b = pop(s);

    push(a + b, s);
}

void subtract(Stack** s) {
    double a = pop(s);
    double b = pop(s);

    push(b - a, s);

}

void multiply(Stack** s) {
    double a = pop(s);
    double b = pop(s);

    push(a * b, s);
}

void divide(Stack** s) {
    double a = pop(s);
    double b = pop(s);

    if (a != 0)
        push(b / a, s);
    else {
        push(b, s);
        push(a, s);
    }
}

void power(Stack** s) {
    double a = pop(s);
    double b = pop(s);

    push(pow(a, b), s);
}

void inv(Stack** s) {
    double a = pop(s);

    push(1 / a, s);
}

int main() {
    Stack** stack = malloc(sizeof(Stack));
    *stack = newStack();

    char input = 'a';

    initscr();

    while (input != ESC && input != 'q') {
        printStack(stack);

        input = getchar();

        if (input >= '0' && input <= '9')
            push(input - '0', stack);
        else if (input == '+')
            add(stack);
        else if (input == '-')
            subtract(stack);
        else if (input == '*')
            multiply(stack);
        else if (input == '/')
            divide(stack);
        else if (input == '^')
            power(stack);
        else if (input == 'i')
            inv(stack);
        else if (input == 'r')
            rollDown(stack);
        else if (input == 's')
            swapXY(stack);
        else if (input == DELETE) {
            pop(stack);
            //push(0, stack);
        }
    }

    endwin();

    return 0;
}
