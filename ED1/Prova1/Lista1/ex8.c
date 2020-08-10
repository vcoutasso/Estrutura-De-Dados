/*
 * Implemente uma função calculadora RPN, que recebe uma string e retorna um resultado float.
 * Assuma que os números contidos na string são todos positivos com um algarismo apenas.
 * Se for utilizar alguma estrutura de dados, não é necessário implementá-la, apenas esclarecer qual está usando.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Stack Stack;
typedef struct Element Element;

struct Stack {
    Element* top;
};

struct Element {
    float data;
    Element* next;
};

Stack* newStack() {
    Stack* s = malloc(sizeof(Stack));
    s->top = NULL;

    return s;
}

void push(float data, Stack* s) {
    Element* e = malloc(sizeof(Element));

    e->data = data;
    e->next = s->top;
    s->top = e;
}

float pop(Stack* s) {
    Element* aux = s->top;

    if (aux != NULL) {
        float data = s->top->data;
        s->top = s->top->next;
        free(aux);

        return data;
    }

    return 0;
}

// A funcao assume que a string de entrada é um conjunto de operacoes valido. Ex: 12+3* retorna 9
float calcRPN(char* str) {
    Stack* s = newStack();
    int i;
    float y;
    float x;

    char ch;


    for (i = 0; *(str+i) != '\0'; i++) {
        ch = *(str+i);

        if (ch >= '0' && ch <= '9')
            push(ch - '0', s);
        else if (ch == '+') {
            x = pop(s);
            y = pop(s);
            push(y + x, s);
        }
        else if (ch == '-') {
            x = pop(s);
            y = pop(s);
            push(y - x, s);
        }
        else if (ch == '*') {
            x = pop(s);
            y = pop(s);
            push(y * x, s);
        }
        else if (ch == '/') {
            x = pop(s);
            y = pop(s);
            push(y / x, s);
        }
        else if (ch == '^') {
            x = pop(s);
            y = pop(s);
            push(pow(y, x), s);
        }
    }
    return pop(s);
}

int main() {
    char str[] = "13*4+2^";

    printf("Resultado da operacao %s: %.5f\n", str, calcRPN(str));

        return 0;
    }
