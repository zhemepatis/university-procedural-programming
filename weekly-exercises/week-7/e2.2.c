#include <stdio.h>

int getFactorial(int number);

int main() {
    int num;
    printf("Enter a whole number from 1 to 12: ");
    scanf("%d", &num);

    int result = getFactorial(num);
    printf("Result: %d", result);
    
    return 0;
}

int getFactorial(int number) {
    if(number <= 0  || number > 12)
        return 0;

    int result = 1;
    for(int i = number; i > 1; --i)
        result *= i;

    return result;
}