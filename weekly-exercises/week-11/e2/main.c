#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"

int *fillArray(int arrSize, int high, int low);
void printArray(int *arr, int arrSize);

int main() {
    int arrSize = 10;
    int *m1 = fillArray(arrSize, 0, 100);
    int *m2 = fillArray(arrSize, 0, 100);
    int *m3 = fillArray(arrSize, 0, 100);

    saveToFile(m1, arrSize, "hello.txt");
    saveToFile(m3, arrSize, "hello.txt");

    m1 = loadFromFile("hello.txt");

    saveToFile(m3, arrSize, "hello2.txt");
    m3 = loadFromFile("hello2.txt");
    m2 = loadFromFile("hello.txt");

    if(saveCount == 3 && loadCount == 3) {
        printf("all good");
    } 
    else {
        printf("something\47s wrong");
    }

    free(m1);
    free(m2);
    free(m3);

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