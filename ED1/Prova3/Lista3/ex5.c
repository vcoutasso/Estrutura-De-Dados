int tamanho(ListaInt *lista) {
	if (lista == NULL)
		return 0;
	else
		return 1 + tamanho(lista->next);
}
