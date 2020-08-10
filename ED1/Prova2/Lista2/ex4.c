/*
 * Escreva uma função que recebe uma lista duplamente encadeada não circular, E um número inteiro X.
 * A função deve “cortar” a lista na posição X, de forma que a lista original tenha todos os membros das posições menores que X,
 * e retornar uma lista que contenha todos os membros da lista original a partir posição X (inclusive).NÃO É PERMITIDO ALOCAR NOVAS ESTRUTURAS, NEM UTILIZAR FUNÇÕES PRONTAS.
 * Obs.: Assuma que a posição pedida é sempre válida, isto é, não-negativa e menor que o tamanho da lista.
 */

#include <stdio.h>
#include <stdlib.h>

Lista split(Lista* original, int X) {
	Lista list;
	Element* aux = original->front;
	int count = 0;

	while (count < X) {
		aux = aux->next;
		++count;
	}

	aux->prev->next = NULL;
	aux->prev = NULL;
	lista->front = aux;

	return list;
}
