#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_CAPACITY 1000

void generateArray(int data[], int size, int low, int high);

int main() {
    int data[ARRAY_CAPACITY];

    int arrSize;
    printf("Enter array size: ");
    scanf("%d", &arrSize);

    int lowerLimit, upperLimit;
    printf("Enter the lower limit: ");
    scanf("%d", &lowerLimit);
    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);

    generateArray(data, arrSize, lowerLimit, upperLimit);

    printf("Result: ");
    for(int i = 0; i < arrSize; ++i)
        printf("%d ", data[i]);

    return 0;
}

void generateArray(int data[], int size, int low, int high) {
    srand(time(NULL));

    for(int i = 0; i < size; ++i)
        data[i] = rand() % (high - low + 1) + low;
}