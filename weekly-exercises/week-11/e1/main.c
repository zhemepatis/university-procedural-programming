#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"

int *fillArray(int arrSize, int high, int low);
void printArray(int *arr, int arrSize);

int main() {
    int arrSize = 10;
    int *m1 = fillArray(arrSize, 0, 100);

    printArray(m1, arrSize);
    saveToFile(m1, arrSize, "hello.txt");

    int *m2 = loadFromFile("hello.txt");
    printArray(m2, arrSize);

    int noError = 1;
    for(int i = 0; i < arrSize; ++i) {
        if(*(m1+i) != *(m2+i)) {
            noError = 0;
            printf("something\47s wrong");
            break;
        }
    }
    if(noError) {
        printf("all good");
    } 

    free(m1);
    free(m2);

    return 0;
}

int *fillArray(int arrSize, int high, int low) {
    int *arr = calloc(arrSize, sizeof(int));
    srand(time(NULL));

    for(int i = 0; i < arrSize; ++i)
        arr[i] = rand() % (high - low + 1) + low;

    return arr;
}

void printArray(int *arr, int arrSize) {
    for(int i = 0; i < arrSize; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}