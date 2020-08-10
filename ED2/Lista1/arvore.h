#include <stdio.h>
#include <stdlib.h>

typedef struct _arvore {
   char info;
   struct _arvore *esq;
   struct _arvore *dir;
} Arvore;

Arvore* cria_arv_vazia ();

void destroi_arv (Arvore *arv);

Arvore* constroi_arv (char elem, Arvore *esq, Arvore *dir);

