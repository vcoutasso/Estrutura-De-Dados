#include "arvore.h"

Arvore* cria_arvore_vazia(void) {
    return NULL;
}

void arvore_libera(Arvore* a) {
    if (a != NULL) {
        arvore_libera (a->esq);
        arvore_libera (a->dir);
        free(a);
    }
}

/*
 * Baseado nas notas de aula e usando o código disponibilizado no Moodle, implemente as funções para realizar inserção, busca e remoção em uma árvore binária de busca (ABB).
 */
Arvore* inserir(Arvore *a, int v) {
    if (a == NULL) {
        a = (Arvore*)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (v < a->info)
        a->esq = inserir(a->esq, v);
    else if (v > a->info)
        a->dir = inserir(a->dir, v);

    return a;
}


Arvore* remover(Arvore *a, int v) {
    if (a == NULL)
        return NULL;
    else {
        if (a->info > v)
            a->esq = remover(a->esq, v);
        if (a->info < v)
            a->dir = remover(a->dir, v);
        else {
            if ((a->esq == NULL) && (a->dir == NULL)) {
                free(a);
                a = NULL;
            }
            else if (a->esq == NULL) {
                Arvore *tmp = a;
                a = a->dir;
                free(tmp);
            }
            else if (a->dir == NULL) {
                Arvore *tmp = a;
                a = a->esq;
                free(tmp);
            }
            else {
                Arvore *tmp = a->esq;

                while (tmp->dir != NULL)
                    tmp = tmp->dir;

                a->info = tmp->info;
                tmp->info = v;
                a->esq = remover(a->esq, v);
            }
        }
    }

    return a;
}


int buscar(Arvore *a, int v) {
    if (a == NULL)
        return 0;
    else if (v < a->info)
        return buscar(a->esq, v);
    else if (v > a->info)
        return buscar(a->dir, v);

    return 1;

}

/*
 * Escreva uma função "min" que encontre (e imprima) uma chave mínima em uma árvore binária de busca.
 * Escreva uma função "max" que encontre (e imprima) uma chave máxima.
 * Utiilze os seguintes protótipos para a sua função:
 *
 * int min(Arvore *a);
 * int max(Arvore *a);
 */
int min(Arvore *a) {
    if (a == NULL)
        return 0;

    if (a->esq != NULL)
        return min(a->esq);

    printf("%d\n", a->info);

    return 1;
}

int max(Arvore *a) {
    if (a == NULL)
        return 0;

    if (a->dir != NULL)
        return max(a->dir);

    printf("%d\n", a->info);

    return 1;
}

/*
 * Escreva uma função recursiva que imprime uma árvore binária de busca em ordem decrescente.
 * Utilize o seguinte protótipo para a sua função:
 *
 * void imprime_decrescente(Arvore *a);
 */

void imprime_decrescente(Arvore *a) {
    if (a != NULL) {
        imprime_decrescente(a->dir);
        printf("%d ", a->info);
        imprime_decrescente(a->esq);
    }
}

/*
 * Escreva uma função que retorna o valor do maior caminho (soma dos valores dos nós) da raiz até algum nó folha da árvore.
 * Utilize o seguinte protótipo para a sua função:
 *
 * int maior_ramo(Arvore *a);
 */
int maior_ramo(Arvore *a) {
    if (a != NULL) {
        int esq = a->info + maior_ramo(a->esq);
        int dir = a->info + maior_ramo(a->dir);

        return esq > dir ? esq : dir;
    }

    return 0;
}

/*
 * Escreva uma função que retorna o ancestral comum de maior nível de dois nós fornecidos.
 * Utilize o seguinte protótipo para a sua função:
 *
 * int ancestral(Arvore *a, int e1, int e2);
 */
int ancestral(Arvore *a, int e1, int e2) {
    if (a != NULL) {
        if (buscar(a->esq, e1) && buscar(a->esq, e2))
            return ancestral(a->esq, e1, e2);
        else if (buscar(a->dir, e1) && buscar(a->dir, e2))
            return ancestral(a->dir, e1, e2);
        else if (buscar(a, e1) && buscar(a, e2))
            return a->info;
        else
            return 0;
    }

    return 0;
}

/*
 * Escreva um programa que produza 100000 números em ordem de 0 até 99999. Insira esses números em um árvore binária de busca (ABB).
 * Procure por um valor que não existe (por exemplo 100000).
 * Quanto tempo a busca levou?
 */
void busca_ord() {
    Arvore *a_ord = cria_arvore_vazia();
    int i;

    printf("Inserindo elementos...\n");
    // Insere os valores na árvore enquanto preenche arr
    for (i = 0; i < LENGTH; i++) {
        a_ord = inserir(a_ord, i);
    }

    printf("Realizando busca...\n");
    clock_t start = clock();
    buscar(a_ord, LENGTH);
    clock_t end = clock();

    printf("A busca levou %.6f segundos\n", (float)(end - start) / CLOCKS_PER_SEC);

    arvore_libera(a_ord);
}

/*
 * Escreva um programa que produza 100000 números aleatórios entre 0 e 99999. Insira esses números em um árvore binária de busca (ABB).
 * Procure por um valor que não existe (por exemplo 100000).
 * Quanto tempo a busca levou?
 */
void busca_rand() {

    srand(time(NULL));

    Arvore *a_rand = cria_arvore_vazia();
    int tmp, j, i;

    //  Array com os números a serem inseridos na ABB.
    int arr[LENGTH];

    // Inicializa array
    for (i = 0; i < LENGTH; i++)
        arr[i] = i;

    printf("Gerando lista de números aleatórios...\n");
    // Randomiza os elementos do array criado anteriormente
    for (i = 0; i < LENGTH; i++) {
        j = rand() % LENGTH;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    printf("Inserindo elementos...\n");
    // Insere os valores na árvore
    for (i = 0; i < LENGTH; i++) {
        a_rand = inserir(a_rand, arr[i]);
    }

    printf("Realizando busca...\n");
    clock_t start = clock();
    buscar(a_rand, LENGTH);
    clock_t end = clock();

    printf("A busca levou %.6f segundos\n", (float)(end - start) / CLOCKS_PER_SEC);

    arvore_libera(a_rand);
}

void pre_order(Arvore* a) {
    if (a != NULL) {
        printf("%d ", a->info);
        pre_order (a->esq);
        pre_order (a->dir);
    }
}

