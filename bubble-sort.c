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

    /* Bubble Sort decrescente */
    for (int i = 0; i < n - 1; ++i) {
        int trocou = 0;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (a[j] < a[j + 1]) { /* para decrescente: maior para frente */
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                trocou = 1;
            }
        }
        if (!trocou) break; /* otimização: vetor já ordenado */
    }
    printf("Depois (Bubble Sort, decrescente):\n");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");

    return 0;
}