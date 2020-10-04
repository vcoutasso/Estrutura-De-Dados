#include <stdio.h>
#include <limits.h>

void minHeapify(int V[], int size, int idx) {
    int idx_esq = idx * 2 + 1;
    int idx_dir = idx * 2 + 2;

    int idx_menor;

    if (idx_esq < size && V[idx_esq] < V[idx])
        idx_menor = idx_esq;
    else
        idx_menor = idx;

    if (idx_dir < size && V[idx_dir] < V[idx_menor])
        idx_menor = idx_dir;

    if (idx_menor != idx) {
        int tmp = V[idx];
        V[idx] = V[idx_menor];
        V[idx_menor] = tmp;
        minHeapify(V, size, idx_menor);
    }

}

void buildMinHeap(int V[], int size) {
    int i;

    for (i = size/2 - 1; i >= 0; --i)
        minHeapify(V, size, i);

}

int heapMinimum(int V[]) {
    return V[0];
}

int heapExtractMin(int V[], int *size) {
    if (*size < 1) {
        printf("Error: Heap underflow\n");
        return INT_MAX;
    }

    int min = heapMinimum(V);

    V[0] = V[*size - 1];
    (*size)--;
    minHeapify(V, *size, 0);

    return min;
}

int parent(int idx) {
    return (idx - 1) / 2;
}

void heapDecreaseKey(int V[], int idx, int key) {
    if (key > V[idx]) {
        printf("Error: Expected key lesser than %d, got %d.\n", V[idx], key);
        return;
    }

    V[idx] = key;
    while (idx > 0 && V[parent(idx)] > V[idx]) {
        int tmp = V[idx];
        V[idx] = V[parent(idx)];
        V[parent(idx)] = tmp;
        idx = parent(idx);
    }
}

// Para manter a implementação simples essa função assume que a posição V[*size-1] é válida (o que, convenientemente, ocorre no exemplo fornecido)
void minHeapInsert(int V[], int *size, int key) {
    (*size)++;
    V[*size-1] = INT_MAX;
    heapDecreaseKey(V, (*size)-1, key);
}

// Exemplo fornecido para teste da implementação
int main() {
    int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = sizeof(V) / sizeof(int);
    int i;

    printf("vec:\n");
    for (i = 0; i < size; i++)
        printf("%d, ", V[i]);
    printf("\n");

    buildMinHeap(V, size);

    printf("\nheap:\n");
    for (i = 0; i < size; i++)
        printf("%d, ", V[i]);
    printf("\n");

    heapExtractMin(V, &size);

    printf("\nextract min:\n");
    for (i = 0; i < size; i++)
        printf("%d, ", V[i]);
    printf("\n");

    heapDecreaseKey(V, 8, 1);

    printf("\ndecrease key:\n");
    for (i = 0; i < size; i++)
        printf("%d, ", V[i]);
    printf("\n");

    minHeapInsert(V, &size, 0);

    printf("\nheap insert :\n");
    for (i = 0; i < size; i++)
        printf("%d, ", V[i]);
    printf("\n");

    return 0;

}
