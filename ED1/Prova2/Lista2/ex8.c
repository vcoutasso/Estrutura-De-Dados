/*
 * Escreva uma função que receba um vetor de inteiros de 10 posições, e retorne uma lista simplesmente encadeada de inteiros contendo os valores do vetor.
 * É permitido utilizar as funções prontas da lista.
 */

#include <stdio.h>
#include <stdlib.h>

List* arrayToList(int arr[], int size) {
	List* list = newList();
	int i;

	for (i = 0; i < size; ++i)
		push(arr[i], list, -1);

	return list;
}
