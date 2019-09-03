/*
 * Escreva uma função que receba uma pilha e retire todos os elementos ímpares da mesma.
 * NÃO É PERMITIDO ACESSAR OS ELEMENTOS DIRETAMENTE. Só é possível modificar a pilha utilizando as funções push e pop.
 * É permitido utilizar estruturas de dados auxiliares. A ordem original dos elementos deve ser preservada.
 * Por exemplo, uma pilha que começa com os valores (8,3,5,2,1,4) deve ficar com os valores (8,2,4) nesta ordem.
 */

#include <stdio.h>
#include <stdlib.h>

void retiraImpares(Stack* s) {
    Stack* aux = newStack();
    int data;

    // Esvazia a pilha e armazena os elementos pares na fila
    while(!isEmpty(s)) {
        data = pop(s);
        if (data % 2 == 0)
            push(data, aux);
    }

    while(!isEmpty(aux))
        push(pop(aux), s);

}
