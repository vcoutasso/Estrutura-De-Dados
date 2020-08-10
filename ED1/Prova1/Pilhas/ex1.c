/*
 * A partir de uma string de entrada, verifique se todos os delimitadores de texto (parênteses, colchetes, chaves) estão balanceados. Todo parêntese/colchete/chave iniciado deve ser terminado.
 * Por exemplo, a sequência [ novo ( carro ) ] está balanceada, mas a sequência [ novo ( carro ] ) não está. Você pode fazer a função, que deve receber uma string, retornar 1 para o caso balanceado e 0
 * para o desbalanceado ou apenas escrever na tela o resultado.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 2000

typedef struct Stack Stack;

struct Stack{
    char ch;
    Stack *next;
};

Stack* newStack() {
    Stack *s = malloc(sizeof(Stack));
    s->ch = '\0';
    s->next = NULL;

    return s;
}

Stack* newElement(char ch) {
    Stack *s = malloc(sizeof(Stack));
    s->ch = ch;
    s->next = NULL;
    return s;
}

void push(char ch, Stack **s) {
    Stack *top = newElement(ch);
    top->next = *s;
    *s = top;
}

char pop(Stack **s) {
    Stack *aux = *s;
    char ch = (*s)->ch;
    *s = (*s)->next;
    free(aux);

    return ch;
}

void strToStack(char *str, Stack **s) {
    for (int i = 0; i < MAX; i++) {
        if (str[i] == '\n')     // \n vem antes do \0
            break;
        else
            push(str[i], s);
    }
}

int isEmpty(Stack *s) {
    if (s->next == NULL || s == NULL)
        return 1;

    return 0;
}

int isValid(char ch, Stack **s) {
    char lf;
    if (ch == '(')
        lf = ')';
    else if (ch == '[')
        lf = ']';
    else
        lf = '}';

    if (!isEmpty(*s)) {
        if ((*s)->ch == lf) {
            pop(s);
            return 1;
        }
    }

    return 0;
}

int isBalanced(Stack **s) {
    char ch;
    Stack *aux = newStack();

    while ((*s)->next != NULL) {
        ch = pop(s);

        if (!isalnum(ch)) {
            if (ch == ')' || ch == ']' || ch == '}')
                push(ch, &aux);
            else if (ch == '(' || ch == '[' || ch == '{')
                if (!isValid(ch, &aux))
                    return 0;   // string desbalanceada
        }
    }

    if (!isEmpty(aux))
        return 0;

    return 1;
}

int main() {
    char str[MAX];
    Stack *s = newStack();

    printf("Informe a string que deve ser verificada: ");
    fgets(str, MAX, stdin);

    strToStack(str, &s);

    if (isBalanced(&s))
        printf("String balanceada!\n");
    else
        printf("String desbalanceada!\n");

    return 0;
}
