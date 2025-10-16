#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx_max = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[idx_max]) {
                idx_max = j;
            }
        }
        if (idx_max != i) {
            int temp = arr[i];
            arr[i] = arr[idx_max];
            arr[idx_max] = temp;
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void loadArray(int arr[], const char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    
    for (int i = 0; i < N; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    
    fclose(fp);
}

int main() {
    int *arr = (int*)malloc(N * sizeof(int));
    clock_t start, end;
    double cpu_time_used;

    // Bubble Sort
    loadArray(arr, "numbers.txt");
    start = clock();
    bubbleSort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %.2f segundos\n", cpu_time_used);

    // Selection Sort
    loadArray(arr, "numbers.txt");
    start = clock();
    selectionSort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %.2f segundos\n", cpu_time_used);

    // Insertion Sort
    loadArray(arr, "numbers.txt");
    start = clock();
    insertionSort(arr, N);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %.2f segundos\n", cpu_time_used);

    free(arr);
    return 0;
}