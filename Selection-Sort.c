#include <stdio.h>

int main(void) {
    int n = 10;
    int a[10];

    /* Ler 10 inteiros com prompt e validação */
    for (int i = 0; i < n; ++i) {
        int ok = 0;
        while (!ok) {
            printf("Digite o %dº número: ", i + 1);
            fflush(stdout);
            if (scanf("%d", &a[i]) == 1) {
                ok = 1;
            } else {
                printf("Entrada inválida. Digite um número inteiro.\n");
                int c;
                while ((c = getchar()) != EOF && c != '\n'); /* descarta linha */
            }
        }
    }
    printf("Antes:\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    /* Selection Sort decrescente */
    for (int i = 0; i < n - 1; ++i) {
        int idx_max = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[idx_max]) idx_max = j; /* maior elemento */
        }
        if (idx_max != i) {
            int tmp = a[i];
            a[i] = a[idx_max];
            a[idx_max] = tmp;
        }
    }
    printf("Depois (Selection Sort, decrescente):\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    return 0;
}