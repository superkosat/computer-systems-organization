#include <stdio.h>

typedef struct {
    char *word;
    node *left;
    node *right;
} node;

node * createNode (char * word) {
    node *newNode = {word};
    return newNode;
}

void add(node ** root, char * word) {
    if (*root == NULL) {
        *root = createNode(&word);
        return;
    }
    if ((*root)->left == NULL) {
        add(&(*root)->left, &word);
    } else {
        add(&(*root)->right, &word);
    }
}

char * inorder(node ** root) {
    
}

int main() {
    node *root = NULL;
    return 0;
}