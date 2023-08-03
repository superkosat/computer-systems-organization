#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fileptr;
    fileptr = fopen("Project4Input.txt", "r");

    char line[100];

    if (fileptr == NULL) {
        printf("File could not be opened");
        return 1;
    }

    char **CachedArray = NULL;
    int cacheIndex = 0;

    while(fgets(line, sizeof(line), fileptr) != NULL) {
        char *token = strtok(line, ",");
        
        
        
    }

    int i = 0;
    while (CachedArray[i] != NULL) {
        printf("%s",CachedArray[i]);
        i++;
    }

    free(CachedArray);

    fclose(fileptr);

    return 0;
}