#include <stdio.h>

#define MAX_SIZE 10

int towerA[MAX_SIZE], towerB[MAX_SIZE], towerC[MAX_SIZE];
int topA = -1, topB = -1, topC = -1;

int moveCount = 1;

void push(int tower[], int *top, int value) {
    if (*top >= MAX_SIZE - 1) {
        return;
    }
    (*top)++;
    tower[*top] = value;
}

int pop(int tower[], int *top) {
    if (*top < 0) {
        return -1;
    }
    int value = tower[*top];
    tower[*top] = 0;
    (*top)--;
    return value;
}

void printTowers() {
    printf("tower A:");
    for (int i = 0; i <= topA; i++) {
        printf(" %d", towerA[i]-1);
    }
    printf("\ntower B:");
    for (int i = 0; i <= topB; i++) {
        printf(" %d", towerB[i]-1);
    }
    printf("\ntower C:");
    for (int i = 0; i <= topC; i++) {
        printf(" %d", towerC[i]-1);
    }
    printf("\n");
}

void move(char source, char auxiliary, char destination, int *sourceTop, int *destinationTop, int sourceTower[], int destinationTower[]) {
    int disk = pop(sourceTower, sourceTop);
    push(destinationTower, destinationTop, disk);
    printf("Move #%d: move(1,%c,%c,%c)\n", moveCount, source, auxiliary, destination);
    printTowers();
    moveCount++;
}

void towerOfHanoi(int n, char source, char auxiliary, char destination,
                  int *sourceTop, int *auxiliaryTop, int *destinationTop,
                  int sourceTower[], int auxiliaryTower[], int destinationTower[]) {
    if (n == 1) {
        move(source, auxiliary, destination, sourceTop, destinationTop, sourceTower, destinationTower);
        return;
    }
    
    towerOfHanoi(n - 1, source, destination, auxiliary, sourceTop, destinationTop, auxiliaryTop, sourceTower, destinationTower, auxiliaryTower);
    move(source, auxiliary, destination, sourceTop, destinationTop, sourceTower, destinationTower);
    towerOfHanoi(n - 1, auxiliary, source, destination, auxiliaryTop, sourceTop, destinationTop, auxiliaryTower, sourceTower, destinationTower);
}

int main() {
    int n = 3;

    for (int i = n; i > 0; i--) {
        push(towerA, &topA, i);.
    }

    printf("Start\n");
    printTowers();

    towerOfHanoi(n, 'A', 'B', 'C', &topA, &topB, &topC, towerA, towerB, towerC);

    return 0;
}
