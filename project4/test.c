#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//method signatures for program's constituent functions
void searchTLB(int TLBT, int TLBI, int cacheIndex, char **physicalPageNumber, char **CachedArray);
void searchPageTable(int VPN, int cacheIndex, char **physicalPageNumber, char **CachedArray);
void searchCache(int offset, int cacheIndex, char **physicalPageNumber, char **CachedArray);

//main method assumes the input file is named "Project4Input.txt" and executes accordingly
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

        //searches tlb entries matching tlb tag and tlb index
        char *physicalPageNumber = "MISS";
        searchTLB(TLBT, TLBI, cacheIndex, &physicalPageNumber, &(*CachedArray));
        if (strcmp(physicalPageNumber, "MISS") == 0) {
            //search page table and retrieve physical page number
            printf("Not in TLB\n");
            searchPageTable(VPN, cacheIndex, &physicalPageNumber, &(*CachedArray));
            if (strcmp(physicalPageNumber, "MISS") == 0) {
                printf("Not in Page Table\n");
                printf("Cannot be determined\n");
            } else {
                //combine relevant bits with offset. then extract tag, index, offset, and search cache
                printf("In Page Table\n");
                printf("%s", physicalPageNumber);
                searchCache(offset, cacheIndex, &physicalPageNumber, &(*CachedArray));
                
            }

        } else {
            //combine relevant ppn bits with offset. then extract tag, index, and offset, search cache
            printf("In TLB\n");
            printf("%s", physicalPageNumber);
            searchCache(offset, cacheIndex, &physicalPageNumber, &(*CachedArray));
        }


        printf("Enter an address: ");
        scanf("%s", input);
    }

    /*
    //Print elements of cached array
    for (int i = 0; i < cacheIndex; i++) {
        printf("Element %d: %s\n", i, CachedArray[i]);
    }*/

    for (int i = 0; i < cacheIndex; i++) {
        free(CachedArray[i]);
    }
    free(CachedArray);

    fclose(fileptr);

    return 0;
}

//searches tlb for matching tlb tag and tlb index and modifies physical page number accordingly
void searchTLB(int TLBT, int TLBI, int cacheIndex, char **physicalPageNumber, char **CachedArray) {
    for (int i = 0; i < cacheIndex; i++) {
        if (strcmp(CachedArray[i], "TLB") == 0) {
            int tag;
            int index;
            sscanf(CachedArray[i + 1], "%x", &tag);
            sscanf(CachedArray[i + 2], "%x", &index);
            if (tag == TLBT && index == TLBI) {
                *physicalPageNumber = CachedArray[i + 3];
            }
        }
    }
    return;
}

//searches page table for vpn entry and modifies physical page number accordingly
void searchPageTable(int VPN, int cacheIndex, char **physicalPageNumber, char **CachedArray) {
    for (int i = 0; i < cacheIndex; i++) {
        if (strcmp(CachedArray[i], "Page") == 0) {
            int VPNEntry;
            sscanf(CachedArray[i + 1], "%x", &VPNEntry);
            if (VPN == VPNEntry) {
                *physicalPageNumber = CachedArray[i + 2];
            }
        }
    }
    return;
}

void searchCache(int offset, int cacheIndex, char **physicalPageNumber, char **CachedArray) {
    //extract tag, index, and offset from physical address
    int tagBits;
    sscanf(*physicalPageNumber, "%x", &tagBits);
    int offsetBits = offset & 0x03;
    int indexBits = offset & 0x3c;

    //search cache and return byte if present
    for (int i = 0; i < cacheIndex; i++) {
        if (strcmp(CachedArray[i], "Cache") == 0) {
            int tagEntry;
            int indexEntry;
            sscanf(CachedArray[i + 1], "%x", &tagEntry);
            sscanf(CachedArray[i + 2], "%x", &indexEntry);
            if (tagBits == tagEntry && indexBits == indexEntry) {
                printf("Byte returned: %s\n", CachedArray[i + offsetBits + 3]);
                return;
            }
        }
    }
    printf("Not in Cache\n");
    printf("Cannot be determined\n");
}