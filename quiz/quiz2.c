#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Header {
    int n;
    struct Header *first;
    struct Header *last;
};

int main() {
    struct Header *header = (struct Header *)malloc(sizeof(struct Header));
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    
    header->n = 0;
    
    n1->data = 1;
    n1->next = n2;

    n2->data = 2;
    n2->next = NULL;

    header->first = n1;
    header->n++;

    header->last = n2;
    header->n++;
    
    free(n1);
    free(n2);
    
    free(header);

    return 0;

};