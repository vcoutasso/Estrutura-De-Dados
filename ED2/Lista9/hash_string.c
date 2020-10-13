#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
   char k[256];
   struct node *next;
} Node;

typedef struct {
    Node** list;
    int M;
} Hash;

Hash* create_hash(int M) {
    Hash* H = malloc(sizeof(Hash*));

    H->list = malloc(M*sizeof(Node**));
    H->M = M;

    return H;
}

int hash_function(char *v, int M) {
    int i;
    int h = v[0];

    for (i = 1; v[i] != '\0'; ++i)
        h = (h * 256 + v[i]) % M;

    return h;
}

void print_hash (Hash *H) {
   int h;
   for (h = 0; h < H->M; h++) {
      Node *aux;
      for (aux = H->list[h]; aux != NULL; aux = aux->next) {
         printf ("| %s ", aux->k);
      }
      printf ("| \n");
   }
}

void free_hash (Hash *H) {
   int h;
   for (h = 0; h < H->M; h++) {
      free (H->list[h]);
   }
   free (H);
}

void insert_chained(Hash *H, char* str) {
    int idx = hash_function(str, H->M);
    Node* aux = H->list[idx];

    if (aux == NULL) {
        H->list[idx] = malloc(sizeof(Node));
        aux = H->list[idx];
        aux->next = NULL;
    }
    else {
        while (aux->next != NULL)
            aux = aux->next;

        aux->next = malloc(sizeof(Node));
        aux = aux->next;
        aux->next = NULL;
    }

    strcpy(aux->k, str);
}

int main () {

   int M = 7;

   Hash *H = create_hash (M);
  
   insert_chained (H, "Marina");
   insert_chained (H, "Pedro");
   insert_chained (H, "Joana");
   insert_chained (H, "Thais");
   insert_chained (H, "Fabio");
   insert_chained (H, "Jonas");
   insert_chained (H, "Joaquim");
   insert_chained (H, "Mauricio");
   insert_chained (H, "Jorge");
   insert_chained (H, "Ana");
   insert_chained (H, "Patricia");
   insert_chained (H, "Henrique");

   print_hash (H);

   free_hash (H);
 
   return 0;
}

