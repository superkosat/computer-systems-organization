#include <stdio.h>

struct node {
    char * word;
    struct node * next;
};

void addFront(struct node * n, struct node ** head) {
    n->next = (*head);
    (*head) = n;
}

void addSecond(struct node * n, struct node ** head) {
    n->next = (*head)->next;
    (*head)->next = n;
}

void deleteFront(struct node ** head) {
    *head = (*head)->next;
}

int main() {
    struct node * head = 0; // head p o i n t e r for the list
    struct node n1 = { "hello", 0};
    struct node n2 = { "cso201", 0};
    struct node n3 = { "students", 0} ;
    addFront ( &n1, &head);
    addFront ( &n2, &head);
    addFront ( &n3, &head);
    struct node * current = head;
    while (current != 0 ) {
        printf ("%s ", current->word );
        current = current->next;
    }
    printf("\n");
    return 0;
}
