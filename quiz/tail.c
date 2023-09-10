#include <stdio.h>

int tailRecursion(int n, int current) {
    if (n == 1) {
        return current;
    } else {
        return tailRecursion(n - 1, current + 3);
    }
}

int linearRecursion(int n) {
    if (n == 1) {
        return 2;
    } else {
        return linearRecursion(n - 1) + 3;
    }
}

int main() {

    int t = tailRecursion(5, 2);
    
    int l = linearRecursion(5);

    printf("%d\n%d", t, l);

    return 0;
}