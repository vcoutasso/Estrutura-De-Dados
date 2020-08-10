/*
 * Escreva uma função que recebe uma lista duplamente encadeada não circular e a transforme em lista duplamente encadeada circular, SEM ALOCAR NOVOS ELEMENTOS, NEM LIBERAR MEMÓRIA DOS EXISTENTES.
 */

// Asumi que DoublyLinkedList tem ponteiros para seu primeiro e ultimo elementos.
void toCircular(DoublyLinkedList* list) {
	list->front->prev = list->back;
	list->back->next = list->front;

	// Alternativamente, pode-se percorrer a lista em busca do ultimo elemento:
	// Element* aux = list->front; while(aux->next != NULL) { aux = aux->next; }
	// list->front->prev = aux; aux->next = list->front;
}
