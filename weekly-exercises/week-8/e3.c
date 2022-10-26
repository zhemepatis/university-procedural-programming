#include <stdio.h>

void swap(int *num1, int *num2);

int main() {
    int a = 5, b = 6;
    
    swap(&a, &b);

    return 0;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}  