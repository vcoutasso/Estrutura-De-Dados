#ifndef __ARVORE_H_
#define __ARVORE_H_

#define LENGTH 100000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {
   int info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arvore_vazia(void);

void arvore_libera(Arvore* a);

Arvore* inserir(Arvore *a, int v);

Arvore* remover(Arvore *a, int v);

int buscar(Arvore *a, int v);

int min(Arvore *a);

int max(Arvore *a);

void imprime_decrescente(Arvore *a);

int maior_ramo(Arvore *a);

int ancestral(Arvore *a, int e1, int e2);

void busca_ord();

void busca_rand();

void pre_order(Arvore* a);

#endif // __ARVORE_H_
