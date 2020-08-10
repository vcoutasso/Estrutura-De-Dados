/*
 * Escreva uma função que receba um número decimal, e retorne uma estrutura dentre as vistas em aula contendo os algarismos decimais
 * deste número separados. Utilize as funções prontas da estrutura escolhida.
 */

#include <stdio.h>
#include <stdlib.h>

Stack* algarismos(long int num) {
    Stack* s = newStack();

    while (num) {
        push(num % 10, s);
        num /= 10;
    }

    return s;
}
