#include "exercicios.h"

int main() {
    // Cria a árvore de teste
    Arvore *a = constroi_arv ('a',
            constroi_arv('b',
                cria_arv_vazia(),
                constroi_arv('d',cria_arv_vazia(),cria_arv_vazia())
                ),
            constroi_arv('c',
                constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
                constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
                )
            );

    // Testa as funções

    // Ex. 1
    printf("Ex. 1:\n");
    pre_ordem(a);
    printf("\n");
    in_ordem(a);
    printf("\n");
    pos_ordem(a);
    printf("\n");

    // Ex. 2
    printf("\nEx. 2:\n");
    imprime_arv_marcadores(a);
    printf("\n");

    // Ex. 3
    // Testa para valores contidos na raiz, na subárvore esquerda e na direita
    printf("\nEx. 3:\n");
    printf("%d\n", pertence_arv(a, 'a'));
    printf("%d\n", pertence_arv(a, 'b'));
    printf("%d\n", pertence_arv(a, 'c'));
    // Testa para valor que não pertence à arvore
    printf("%d\n", pertence_arv(a, 'g'));

    // Ex. 4
    printf("\nEx. 4:\n");
    printf("%d\n", conta_nos(a));

    // Ex. 5
    printf("\nEx. 5:\n");
    printf("%d\n", calcula_altura_arvore(a));

    // Ex. 6
    printf("\nEx. 6:\n");
    printf("%d\n", conta_nos_folha(a));

    destroi_arv(a);

    return 0;
}
