/*
 * Escreva uma função ListaInt* numFaixa(ListaInt *listaOriginal, int inicioFaixa, int fimFaixa) que recebe uma lista simplesmente encadeada de números inteiros, um inteiro “inicioFaixa” e outro inteiro chamado “fimFaixa”.
 * Esta função deve criar uma segunda lista simplesmente encadeada contendo os elementos da lista original cujo valor está contido no intervalo fechado [inicioFaixa, fimFaixa].
 * Não é permitido utilizar as funções prontas da lista. A lista original não está ordenada, e deve ser preservada. É permitido alocar memória. Não é necessário que os números estejam na lista final na mesma ordem em que estavam na lista original.
 */

#include <stdio.h>
#include <stdlib.h>

ListaInt* numFaixa(ListaInt *listaOriginal, int inicioFaixa, int fimFaixa) {
	ListaInt* lista = malloc(sizeof(ListaInt));
	Element* aux = listaOriginal->front;

	lista->front = NULL;

	while (aux != NULL) {
		if (aux->data >= inicioFaixa && aux->data <= fimFaixa) {
			Element* e = malloc(sizeof(Element));
			e->data = aux->data;
			e->next = lista->front;
			lista->front = e;
		}
		aux = aux->next;
	}
	return lista;
}
