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

    int retNum = 1;
    if(number != 1)
        retNum = getFactorial(number-1);

    return number*retNum;
}