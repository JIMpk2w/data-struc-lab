#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int capacity;
    int* elements;
} Vector;

Vector* createVector() {
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    vector->size = 0;
    vector->capacity = 2;
    vector->elements = (int*)malloc(vector->capacity * sizeof(int));
    return vector;
}

void pushBack(Vector* vector, int value) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->elements = (int*)realloc(vector->elements, vector->capacity * sizeof(int));
    }
    vector->elements[vector->size++] = value;
}

void insertFront(Vector* vector, int value) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->elements = (int*)realloc(vector->elements, vector->capacity * sizeof(int));
    }
    for (int i = vector->size; i > 0; i--) {
        vector->elements[i] = vector->elements[i - 1];
    }
    vector->elements[0] = value;
    vector->size++;
}

void printVector(Vector* vector) {
    for (int i = 0; i < vector->size; i++) {
        printf("%d ", vector->elements[i]);
    }
    printf("\n");
}

void freeVector(Vector* vector) {
    free(vector->elements);
    free(vector);
}

int main() {
    int N;
    scanf("%d", &N);

    Vector** rows = (Vector**)malloc(N * sizeof(Vector*));
    int rowIdx = 0;

    int temp;
    scanf("%d", &temp);

    Vector* newRow = createVector();
    pushBack(newRow, temp);
    rows[rowIdx++] = newRow;

    for (int i = 1; i < N; i++) {
        scanf("%d", &temp);
        if (temp > rows[rowIdx - 1]->elements[rows[rowIdx - 1]->size - 1])
            pushBack(rows[rowIdx - 1], temp);
        else if (temp < rows[rowIdx - 1]->elements[0])
            insertFront(rows[rowIdx - 1], temp);
        else {
            newRow = createVector();
            pushBack(newRow, temp);
            rows[rowIdx++] = newRow;
        }
    }

    for (int i = 0; i < rowIdx; i++) {
        printVector(rows[i]);
    }

    for (int i = 0; i < rowIdx; i++) {
        freeVector(rows[i]);
    }
    free(rows);

    return 0;
}