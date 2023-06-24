#include <stdio.h>
#include <string.h>

struct node {
    char * word;
    struct node * next;
    struct node * prev;
};

void MoveThird (struct node **head) {
    struct node * second = (*head ) -> next;
    struct node * third = (*head) -> next -> next;
    second -> next = third->next;
    third -> next = (*head);
    (*head) = third;
}

void DuplicateIT (struct node ** head, char * c) {
    if (*head == 0) {
        return;
    }
    struct node * current = *head;
    while (current != NULL) {
        if (strcmp(current->word,c) == 0) {
            struct node * newNode = (c, 0);
            newNode->next = current->next;
            current->next = newNode;
            current = current->next->next;
        } else {
            current = current->next;
        }
    }
}



void addFront(struct node ** head, struct node * n) {
    n->next = *head;
    n->prev = 0;

    if (*head != 0) {
        (*head)->prev = n;
    }

    *head = n;
}

void add(struct node ** head, int index, struct node * n) {
    struct node * current = *head;
    for (int i = 1; i < index; i++) {
        current = current->next;
    }

    n->next = current->next;
    n->prev = current;

    if (current->next != 0) {
        current->next->prev = n;
    }

    current->next = n;
}

int countWord (struct node ** head, char * c) {
    struct node * current = *head;
    int count = 0;
    while (current != 0) {
        if (current->word == c) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void Reverse (struct node ** head) {
    struct node * current = *head;
    struct node * next;
    struct node * result;
    while (current != NULL) {
        next = current->next;
        current->next = result;

        result = current;
        current = next;
    }
    (*head) = result;
}

int main() {
    struct node * head = 0;
    struct node n1 = {"A"};
    struct node n2 = {"B"};
    struct node n3 = {"C"};
    struct node n4 = {"D"};
    struct node n5 = {"E"};

    char c = "B";
    char *ptrC = &c;

    addFront(&head, &n4);
    addFront(&head, &n3);
    addFront(&head, &n2);
    addFront(&head, &n1);
    //DuplicateIT(&head, ptrC);

    add(&head, 2, &n5);
    printf("occurrences of 'B': %d", countWord(&head, ptrC));

    struct node * current = head;
    while (current != 0) {
        printf("%s ", current->word);
        current = current->next;
    }
    
    return 0;
}