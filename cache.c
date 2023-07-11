#include <stdio.h>
#include <math.h>

typedef struct {
    int size;
    int addrLength;
    int blockSize;
    int assoc;
} cache;

int getBlock(cache c) {
    return log2(c.blockSize);
}

int getSet(cache c) {
    int sets = (c.size * 1024) / c.blockSize;
    if (c.assoc > 0) {
        sets /= c.assoc;
    }
    return log2(sets);
}

int getTag(cache c) {
    return c.addrLength - getSet(c) - getBlock(c);
}

int main () {
    cache c = {64, 16, 16, 4};
    int set = getSet(c);
    int block = getBlock(c);
    int tag = getTag(c);
    printf("%d %d %d", tag, set, block);
    return 0;
}