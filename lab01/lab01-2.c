#include <stdio.h>

int main() {
    int num, min = 10000, max = -10000, eq ;
    scanf("%d", &num);
    if(num>=1 && num<=1000){
        for(int i=0;i<num;i++){
            scanf("%d", &eq);
            if(eq>=-10000 && eq<=10000){
                if(eq <= min){
                    min = eq;
                }
                if(eq >= max){
                    max = eq;
                }
            }
        }
        printf("%d\n%d", min, max);
    }
}