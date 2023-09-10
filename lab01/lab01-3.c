#include <stdio.h>

int main() {
    int num, min;
    scanf("%d", &num);
    int heights[num+1];
    
    for (int i = 0; i < num; i++) {
        scanf("%d", &heights[i]);
    }
    
    int compare = 0;

    for (int i = 0; i < num-1; i++) {
        for (int j = i+1; j < num; j++) {

            if(heights[i] > heights[j]){
                min = heights[j];
            }else{
                min = heights[i];
            }

            int has_taller = 1;

            for (int k = i + 1; k < j; k++) {
                if (heights[k] >= min) {
                    has_taller = 0;
                    break;
                }
            }

            if (has_taller) {
                compare++;
            }
        }
    }
    printf("%d", compare);
    return 0;
}