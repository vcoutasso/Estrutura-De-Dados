/*
 * Neste exercício, deve-se realizar uma comparação das movimentações e comparações realizadas para ordenar um vetor
 * utilizando os métodos vistos em sala de aula (Insertion sort, Selection sort e Merge sort).
 * O tamanho do vetor utilizado deve ser razoavelmente grande (100 mil posições, por exemplo).
 *
 * Obs: Adicionado bubble sort como um bonus para as comparações
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int size) {
	int i, j;
	int aux;
	long long comp = 0, mov = 0;

	int *a = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) a[i] = arr[i];

	clock_t start, end;

	start = clock();

	for (i = 1; i < size; i++) {
		j = i - 1;
		aux = a[i];
		while (j >= 0 && a[j] > aux) {
			comp++;
			mov++;
			a[j+1] = a[j];
			j--;
		}
		mov++;
		a[j + 1] = aux;
	}

	end = clock();

	printf("Insertion Sort\nComparisons: %lli\nMovements:   %lli\nTime Taken:  %.2f s\n\n", comp, mov, (float)(end - start)/CLOCKS_PER_SEC);

	free(a);
}

void selectionSort(int arr[], int size) {
	int i, j;
	int aux;
	int minPos;
	long long comp = 0, mov = 0;

	int *a = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) a[i] = arr[i];

	clock_t start, end;

	start = clock();

	for (i = 0; i < size; i++) {
		minPos = i;
		for (j = i; j < size; j++) {
			comp++;
			if (a[j] < a[minPos])
				minPos = j;
		}
		mov += 2;
		aux = a[i];
		a[i] = a[minPos];
		a[minPos] = aux;
	}

	end = clock();

	printf("Selection Sort\nComparisons: %lli\nMovements:   %lli\nTime Taken:  %.2f s\n\n", comp, mov, (float)(end - start)/CLOCKS_PER_SEC);

	free(a);
}

void reuneMergeSort(int a[], int inicio, int meio, int fim, long long *comp, long long *mov)
{
	int i, j, k;
	int n1 = meio - inicio + 1;
	int n2 = fim - meio;
	int *aux1 = malloc(n1*sizeof(int));
	int *aux2 = malloc(n2*sizeof(int));

	for (i = 0; i < n1; i++) { aux1[i] = a[inicio + i]; (*mov)++; }

	for (j = 0; j < n2; j++) { aux2[j] = a[meio + 1 + j]; (*mov)++; }

	i = 0;
	j = 0;
	k = inicio;

	while (i < n1 && j < n2)
	{
		(*comp) += 3;
		(*mov)++;
		if (aux1[i] <= aux2[j])
		{
			a[k] = aux1[i];
			i++;
		}
		else
		{
			a[k] = aux2[j];
			j++;
		}
		k++;
	}

	// para copiar ao vetor principal os elementos que porventura sobrem em aux1
	while (i < n1)
	{
		(*comp)++;
		(*mov)++;
		a[k] = aux1[i];
		i++;
		k++;
	}

	// para copiar ao vetor principal os elementos que porventura sobrem em aux2
	while (j < n2)
	{
		(*comp)++;
		(*mov)++;
		a[k] = aux2[j];
		j++;
		k++;
	}
	free(aux1);
	free(aux2);
}

void mergeSort(int a[], int inicio, int fim, long long *comp, long long *mov)
{
	// Condiзгo de parada da recursгo - elementos todos jб sozinhos
	if (inicio < fim)
	{
		(*comp)++;
		// Achar a posiзгo do m do vetor
		int meio = (fim + inicio)/2;

		// Recursгo, dividindo sucessivamente o vetor e executando o algoritmo
		// em cada metade
		mergeSort(a, inicio, meio, comp, mov);
		mergeSort(a, meio + 1, fim, comp, mov);

		// Uma vez ordenados, vai remontando o vetor (usando um vetor temporбrio
		// para o armazenamento da nova versгo)
		reuneMergeSort(a, inicio, meio, fim, comp, mov);
	}
}

void bubbleSort(int arr[], int size) {
	int i, j;
	int aux;
	long long comp = 0, mov = 0;

	clock_t start, end;

	start = clock();

	int *a = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) a[i] = arr[i];

	for (i = 0; i < size - 1; i++) {
		for (j = i; j < size; j++) {
			comp++;
			if (a[j] < a[i]) {
				mov += 2;
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}

	end = clock();

	printf("\nBubble Sort\nComparisons: %lli\nMovements:   %lli\nTime Taken:  %.2f s\n\n", comp, mov, (float)(end - start)/CLOCKS_PER_SEC);

	free(a);
}

int main() {
	int i, n;

	srand(time(NULL));

	printf("Informe o tamanho do vetor a ser ordenado: ");
	scanf("%d", &n);

	int *arr = malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		arr[i] = rand() % (3 * n);

	bubbleSort(arr, n);
	selectionSort(arr, n);
	insertionSort(arr, n);

	clock_t start, end;
	long long comp = 0, mov = 0;

	start = clock();
	mergeSort(arr, 0, n, &comp, &mov);
	end = clock();

	printf("Merge Sort\nComparisons: %lli\nMovements:   %lli\nTime Taken:  %.2f s\n\n", comp, mov, (float)(end - start)/CLOCKS_PER_SEC);

	free(arr);

	return 0;
}
