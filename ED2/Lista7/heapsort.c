#include <stdio.h>

int pai (int i) {
   return (i - 1)/2; 
}

void trocar (int V[], int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir (int V[], int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");
}

void max_heapify(int V[], int size, int i) {
    int esq = i * 2 + 1;
    int dir = i * 2 + 2;

    int maior;

    if (esq < size && V[esq] > V[i])
        maior = esq;
    else
        maior = i;

    if (dir < size && V[dir] > V[maior])
        maior = dir;

    if (maior != i) {
        int tmp = V[i];
        V[i] = V[maior];
        V[maior] = tmp;
        max_heapify(V, size, maior);
    }
}

void build_max_heap(int V[], int size) {
    int i;
    for (i = size/2 - 1; i >= 0; i--) {
        max_heapify(V, size, i);
    }
}

void heap_sort (int V[], int size) {
    int i;
    build_max_heap(V, size);
    
    for (i = size - 1; i >= 1; i--) {
        int tmp = V[0];
        V[0] = V[i];
        V[i] = tmp;
        size = i;
        max_heapify(V, size, 0);
    }
}

int main () {
   int i;
   int size = 10;

   int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  
   printf("Vetor inicial : ");
   imprimir (V, size);

   heap_sort (V, size);

   printf("Vetor ordenado: ");
   imprimir (V, size);

   return 0;
}
