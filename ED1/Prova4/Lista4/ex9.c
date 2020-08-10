/*
 * Escreva uma função de inserção em uma tabela hash que utilize o método linear probing para o tratamento de colisões.
 * Essa função precisa receber como parâmetros:
 * i) um valor inteiro a ser inserido,
 * ii) a própria tabela hash, e
 * iii) o número de buckets/contêineres/posições da tabela.
 * A assinatura dessa função é obrigatoriamente:
 *
 * int insere(int valor, int hashTable[ ], int nBuckets);
 */

#include <stdio.h>


// Assumi que a tabela só trabalha com valores positivos, portanto -1 indica que a posição não está ocupada, e nao armazena valores repetidos.
int insere(int valor, int hashTable[], int nBuckets) {
	int pos = valor % nBuckets;
	int count = 0;

	while (hashTable[pos] == -1) {
		if (hashTable[pos] == valor) // Valor ja existe
			return -1;
		if (++pos >= nBuckets)
			pos = 0;
		if (count >= nBuckets)	// Sem espaço
			return -2;

		count++;
	}

	hashTable[pos] = valor;

	return pos;
}
