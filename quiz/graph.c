#include<stdio.h>
#include<stdlib.h>

int** createGraph(const int n) {
    int** adjMatrix = malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++) {
        adjMatrix[i] = malloc(sizeof(int)*n);
        for (int j=0; j<n; j++)
            adjMatrix[i][j] = 0;
    }
    return adjMatrix;
}

void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
}

void printGraph(int** adjMatrix, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
        printf("%d ", adjMatrix[i][j]);
        }
    printf("\n");
    }
}

int main() {
    int n = 5;

    int** adjMatrix = createGraph(n);

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 2, 4);
    addEdge(adjMatrix, 4, 3);

    printGraph(adjMatrix, n);
    return 0;
    
}