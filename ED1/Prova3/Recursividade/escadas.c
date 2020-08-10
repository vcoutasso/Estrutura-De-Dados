#include <stdio.h>

void desce(int n) {
    if (n > 0) {
        printf("Descendo o degrau %d\n", n);
        desce(n - 1);
    }
    else
        printf("Fim da escada!\n");
}

int main() {
    desce(8);

    return 0;
}
