#include "exercicios.h"

/* 
 * Exercicio 1:
 * Considerando a  ́árvore a seguir, escreva funções considerando os seguintes tipos de percursos:
 *
 * - pré-ordem
 * - in-ordem
 * - pós-ordem
 *
 *       a
 *      / \
 *     b   c
 *      \ / \
 *      d e f
 */
void pre_ordem(Arvore* a) {
    if (a != NULL) {
        printf("%c ", a->info);
        pre_ordem(a->esq);
        pre_ordem(a->dir);
    }
}

void in_ordem(Arvore* a) {
    if (a != NULL) {
        in_ordem(a->esq);
        printf("%c ", a->info);
        in_ordem(a->dir);
    }
}

void pos_ordem(Arvore* a) {
    if (a != NULL) {
        pos_ordem(a->esq);
        pos_ordem(a->dir);
        printf("%c ", a->info);
    }
}

/*
 * Exercicio 2:
 * Para  descrever   ́árvores  binárias,  podemos  usar  a  seguinte  notação  textual:  a ́árvore  vazia  ́e  representada  por <>,  e   ́árvores  não-vazias,  por <raiz  esq  dir >.
 * Com  essa notação, a  ́árvore do exercício 1) é representada por:
 *
 * <a<b<><d<><>>><c<e<><>><f<><>>>>
 *
 * Escreva uma função que recebe uma árvore de entrada e a imprime utilizando essa notação.
 *
 * Protótipo:
 *
 * void imprime_arv_marcadores (Arvore* arv)
 */
void imprime_arv_marcadores(Arvore* arv) {
    if (arv != NULL) {
        printf("<");
        printf("%c", arv->info);
        imprime_arv_marcadores(arv->esq);
        imprime_arv_marcadores(arv->dir);
        printf(">");
    }
    else {
        printf("<>");
    }
}

/*
 * Exercicio 3:
 * Escreva uma função que retorna um valor booleano (um ou zero) que indica a ocorrência ou não de um dado caractere na árvore.  Considere o seguinte protótipo para a sua função:
 *
 * int pertence_arv(Arvore *a, char c);
 *
 * onde char c é o caractere que deve ser procurado na árvore a.
 */
int pertence_arv(Arvore *a, char c) {
    if (a != NULL) {
        if (a->info == c || pertence_arv(a->esq, c) || pertence_arv(a->dir, c))
            return 1;
    }

    return 0;
}

/*
 * Exercicio 4:
 * Escreva uma função que conte o número de nós de uma ́árvore binária.  Utilize o seguinte protótipo para a sua função:
 *
 * int conta_nos(Arvore *a);
 */
int conta_nos(Arvore *a) {
    if (a != NULL) 
        return 1 + conta_nos(a->esq) + conta_nos(a->dir);

    return 0;
}

/*
 * Exercicio 5:
 * Escreva uma função que calcula a altura de uma árvore binária.  Utilize o seguinte protótipo para a sua função:
 * 
 * int calcula_altura_arvore(Arvore *a);
 */
int calcula_altura_arvore(Arvore *a) {
    if (a != NULL) {
        int h_esq = calcula_altura_arvore(a->esq);
        int h_dir = calcula_altura_arvore(a->dir);

        if (h_esq > h_dir)
            return h_esq + 1;

        return h_dir + 1;
    }

    return -1;
}

/*
 * Exercicio 6:
 * Escreva uma função que conta o número de nós folhas em uma árvore binária. Utilize o seguinte protótipo para a sua função:
 *
 * int conta_nos_folha(Arvore *a);
 */
int conta_nos_folha(Arvore *a) {
    if (a != NULL)
        return conta_nos_folha(a->esq) + conta_nos_folha(a->dir) + (a->esq == NULL && a->dir == NULL ? 1 : 0);

    return 0;
}
