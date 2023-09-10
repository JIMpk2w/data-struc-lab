#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_people;
    scanf("%d", &num_people);
    
    int meetings[num_people][2];

    for (int i = 0; i < num_people; i++) {
        int start_time, end_time;
        scanf("%d %d", &start_time, &end_time);
        meetings[i][0] = start_time;
        meetings[i][1] = end_time; 
    }

    int max_count = 0;
    for (int i = 1; i <= num_people; i++) {
        int current_count = 1;
        
        int left_idx = i;
        while (meetings[left_idx - 1][0] != 0) {
            int temp = meetings[left_idx - 1][0];
            meetings[left_idx - 1][0] = 0;
            left_idx = temp;
            current_count++;
        }

        int right_idx = i;
        while (meetings[right_idx - 1][1] != 0) {
            int temp = meetings[right_idx - 1][1];
            meetings[right_idx - 1][1] = 0;
            right_idx = temp;
            current_count++;
        }

        if (current_count > max_count) {
            max_count = current_count;
        }
    }

    printf("%d", max_count);
}