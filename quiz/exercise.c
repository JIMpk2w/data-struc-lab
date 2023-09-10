#include <stdio.h>

int factorial(int a){
    if (a <= 1) {
        return 2;
    } else {
        return factorial(a-1) + 3;
    }
}

int main(){
    int a = factorial(5);
    printf("%d", a);
}