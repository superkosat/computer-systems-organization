#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

void merge(int array[], int l, int m, int r) {
    int length1 = m - l + 1;
    int length2 = r - m;

    int arrayl[length1];
    int arrayr[length2];

    for (int i = 0; i < length1; i++) {
        arrayl[i] = array[l + i];
    }

    for (int i = 0; i < length2; i++) {
        arrayr[i] = array[m + i + 1];
    }

    int i = 0, j = 0, k = l;
    while (i < length1 && j < length2) {
        if (arrayl[i] <= arrayr[j]) {
            array[k++] = arrayl[i++];
        } else {
            array[k++] = arrayr[j++];
        }
    }

    while (i < length1) {
        array[k++] = arrayl[i++];
    }

    while (j < length2) {
        array[k++] = arrayr[j++];
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


int main (int argc, char **argv) {

    srand(time(NULL));
    
    int array[100000];
    for (int i = 0; i < 100000; i++) {
        array[i] = rand() % 100 + 1;
    }

    //holds generated filenames, i.e. "child_0.txt"
    char filename[12];

    pid_t pid;

    //fork 10 child processes, each of which takes
    for (int i = 0; i < 10; i++) {

    }


    return 0;

}