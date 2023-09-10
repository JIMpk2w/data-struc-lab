#include <stdio.h>
#include <limits.h>

int main() {
    int N, currentSum;
    scanf("%d", &N);

    int garden[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &garden[i][j]);
        }
    }

    int maxSum = INT_MIN;

    for (int left = 0; left < N; left++) {
        int temp[N];
        for (int i = 0; i < N; i++) {
            temp[i] = 0;
        }

        for (int right = left; right < N; right++) {
            for (int i = 0; i < N; i++) {
                temp[i] += garden[i][right];
            }

            if(temp[0] >= 0){
                currentSum = temp[0];
            }else{
                currentSum = 0;
            }

            int maxSumTemp = currentSum;

            for (int i = 1; i < N; i++) {
                if (currentSum <= 0) {
                    currentSum = temp[i];
                } else {
                    currentSum += temp[i];
                }

                if (currentSum > maxSumTemp) {
                    maxSumTemp = currentSum;
                }
            }

            if (maxSumTemp > maxSum) {
                maxSum = maxSumTemp;
            }
        }
    }

    printf("%d\n", maxSum);

    return 0;
}