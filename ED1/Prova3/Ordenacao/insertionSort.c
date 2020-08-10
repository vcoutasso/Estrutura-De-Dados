#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int* arr, int size) {
	int i, j;
	int aux;
	int pos = 0;

	for (i = 1; i < size; i++) {
		j = i - 1;
		aux = *(arr+i);
		while (j >= 0 && *(arr+j) > aux) {
			*(arr+j+1) = *(arr+j);
			j--;
		}
		*(arr+j + 1) = aux;
	}
}

int main() {
	int i, size;

	srand(time(NULL));

	printf("Informe o tamanho do vetor que sera gerado aleatoriamente: ");
	scanf("%d", &size);

	int *arr = malloc(size * sizeof(int));

	printf("\nVetor original: \n");

	for (i = 0; i < size; i++) {
		*(arr+i) = rand() % (3 * size);
		printf("%d ", *(arr+i));
	}

	insertionSort(arr, size);

	printf("\n\nVetor ordenado: \n");

	for (i = 0; i < size; i++)
		printf("%d ", *(arr+i));

	printf("\n");
}
