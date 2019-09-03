/*
 * Escreva um método que inverta uma fila. Para manipular a fila, apenas as operações de inserção e retirada podem ser utilizadas.
 * Outras estruturas de dados podem ser usadas como apoio. Obs.: considere os métodos de inserção e retirada da fila
 * (e da pilha, caso use uma) já implementados.
 */

#include <stdio.h>
#include <stdlib.h>

void invertQ(Queue* q) {
    Stack* aux;

    // Percorre a fila e armazena os elementos na pilha aux até que a fila fique vazia
    while (!isEmptyQueue(q))
        push(pop_front(q), aux);

    // Percorre a pilha recolocando os elementos na ordem que que forem retirados. Por ser uma estrutura LIFO, a pilha devolvera os elementos
    // na ordem invertida em relacao a ordem dos elementos da fila no momento que a funcao foi chamada
    while (!isEmptyStack(aux))
        push_back(pop(aux), q);

}
