#include "arvore.h"

Arvore* cria_arv_vazia () {
   return NULL;
}

void destroi_arv (Arvore *arv) {
   if (arv != NULL) {
      destroi_arv (arv->esq); 
      destroi_arv (arv->dir);
      free(arv); 
   }
}

Arvore* constroi_arv (char elem, Arvore *esq, Arvore *dir) {
   Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
   arv->info = elem;
   arv->esq = esq;
   arv->dir = dir;
   return arv;
}

