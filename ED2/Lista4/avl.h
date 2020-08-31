#ifndef __AVL_H_
#define __AVL_H_

typedef struct node {
   char chave;
   int altura;
   struct node* esq;
   struct node* dir;
} No, Arvore;

int maior (int esq, int dir);

int altura (Arvore* a);

int atualizar_altura (Arvore *a);

int balanceamento (Arvore *a);

Arvore* rotacao_simples_esq (Arvore* a);

Arvore* rotacao_simples_dir (Arvore* a);

Arvore* rotacao_dupla_esq (Arvore* a);

Arvore* rotacao_dupla_dir (Arvore* a);

Arvore* atualizar_fb_dir (Arvore *a);

Arvore* atualizar_fb_esq (Arvore *a);

Arvore* inserir (Arvore *a, char chave);

Arvore* remover (Arvore *a, char chave);

void imprimir_in_order (Arvore* a, int nivel);

#endif // __AVL_H_
