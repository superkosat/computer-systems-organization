#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fileptr;
    fileptr = fopen("Project4Input.txt", "r");

    char line[100];

    if (fileptr == NULL) {
        printf("File Error");
        return 1;
    }

    char **CachedArray = NULL;
    int cacheIndex = 0;

    while (fgets(line, sizeof(line), fileptr) != NULL) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            CachedArray = (char **)realloc(CachedArray, (cacheIndex + 1) * sizeof(char *));
            CachedArray[cacheIndex] = strdup(token);
            cacheIndex++;
            token = strtok(NULL, ",");
        }
    }

    char input[100];
    printf("Enter an address: ");
    scanf("%s", input);
    while (strcmp(input, "DONE") != 0) {

        //reads string as hex and stores in an int
        int intValue;
        sscanf(input, "%x", &intValue);
        printf("Base 10 value: %d\n", intValue);

        //extracts components of virtual address by bits
        int mask = 0xFF << 6;
        int VPN = (intValue & mask) >> 6;
        printf("VPN: %x\n", VPN);

        mask = 0x3 << 6;
        int TLBI = (intValue & mask) >> 6;
        printf("TLTI: %x\n", TLBI);

        mask = 0x3f << 8;
        int TLBT = (intValue & mask) >> 8;
        printf("TLTB: %x\n", TLBT);

        mask = 0x3f;
        int offset = (intValue & mask);
        printf("VPO: %x\n", offset);



        printf("Enter an address: ");
        scanf("%s", input);
    }

    //Print elements of cached array
    for (int i = 0; i < cacheIndex; i++) {
        printf("Element %d: %s\n", i, CachedArray[i]);
        if (strcmp(CachedArray[i], "TLB") == 0) {
            printf("TLB\n");
        }
    }

    for (int i = 0; i < cacheIndex; i++) {
        free(CachedArray[i]);
    }
    free(CachedArray);

    fclose(fileptr);

    

    return 0;
}

