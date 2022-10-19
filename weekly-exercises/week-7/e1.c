#include <stdio.h>
#include <string.h>

int isInRange(int number, int low, int high);

int main() {
    int num;
    printf("Enter a whole number: ");
    scanf("%d", &num);

    int lowerLimit, upperLimit;
    printf("Enter the lower limit: ");
    scanf("%d", &lowerLimit);
    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);

    if(upperLimit < lowerLimit) {
        printf("Error: the upper limit is less than the lower limit.");
        return 0;
    }

    int rangeCheckRes = isInRange(num, lowerLimit, upperLimit);

    char result[60] = "the number exceeds the limit (function returned false)";
    if(rangeCheckRes) {
        strcpy(result, "the number do not exceed the limit (function returned true)");
    }
    printf("Result: %s", result);

    return 0;
}

int isInRange(int number, int low, int high) {
    if (number > high || number < low)
        return 0;
    
    return 1;
}