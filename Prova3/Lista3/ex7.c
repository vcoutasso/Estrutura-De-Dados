/*
 * Escreva uma função int altura(PilhaInt *pilha) que retorne a altura de uma pilha. É PROIBIDO utilizar laços (for, while, do).*
 */
 
int altura(PilhaInt *pilha) {
	if (pilha == NULL)
		return 0;
	else
		return 1 + altura(pilha->next);
}
