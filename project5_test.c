#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void merge(int array[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

int main() {
    int numbers[100000];
    for (int i = 0; i < 100000; i++) {
        numbers[i] = rand() % 100 + 1;
    }

    pid_t child_pid;

    char filename[20];
    
    for (int i = 0; i < 10; i++) {
        snprintf(filename, sizeof(filename), "child%d.txt", i);
        child_pid = fork();
        
        if (child_pid == 0) {
            FILE *fp = fopen(filename, "w");
            
            int start = i * 10000;
            int end = start + 10000 - 1;
            
            mergeSort(numbers, start, end);
            
            for (int j = start; j <= end; j++) {
                fprintf(fp, "%d,", numbers[j]);
            }
            
            fclose(fp);
            exit(0);
        }
        
    }
    
    for (int i = 0; i < 10; i++) {
        wait(NULL);
    }
    
    FILE *output_fp = fopen("sorted_output.txt", "w");
    
    for (int i = 0; i < 10; i++) {
        snprintf(filename, sizeof(filename), "child%d.txt", i);
        
        FILE *input_fp = fopen(filename, "r");
        
        int num;
        while (fscanf(input_fp, "%d,", &num) != EOF) {
            fprintf(output_fp, "%d,", num);
        }
        
        fclose(input_fp);
    }
    
    fclose(output_fp);

    return 0;
}