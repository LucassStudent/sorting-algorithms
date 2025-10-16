#include <stdio.h>
#include <stdlib.h>

#define N 10000

int main() {
    FILE *fp;
    fp = fopen("numbers.txt", "w");
    
    if (fp == NULL) {
        printf("Erro ao criar arquivo!\n");
        return 1;
    }

    // Gera números em ordem decrescente (pior caso)
    for (int i = N; i > 0; i--) {
        fprintf(fp, "%d\n", i);
    }
    
    fclose(fp);
    printf("Arquivo com %d números gerado com sucesso!\n", N);
    return 0;
}