#include <stdio.h>

int main() {
    int arr[100000];
    int num, i = 0, j, temp, n;

    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        arr[i] = num;
        i++;
    }

    n = i;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}