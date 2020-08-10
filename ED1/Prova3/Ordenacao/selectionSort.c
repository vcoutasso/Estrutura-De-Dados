#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *arr, int size) {
	int i, j;
	int aux;
	int minPos;

	for (i = 0; i < size; i++) {
		minPos = i;
		for (j = i; j < size; j++) {
			if (*(arr+j) < *(arr+minPos))
				minPos = j;
		}
		aux = *(arr+i);
		*(arr+i) = *(arr+minPos);
		*(arr+minPos) = aux;
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

	selectionSort(arr, size);

	printf("\n\nVetor ordenado: \n");

	for (i = 0; i < size; i++)
		printf("%d ", *(arr+i));

	printf("\n");
}
