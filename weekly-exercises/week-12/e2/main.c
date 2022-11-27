#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"
#include "arr.h"

#define ARR_SIZE 20
#define ARR_MIN_VALUE 0
#define ARR_MAX_VALUE 100

int checkAlgorithm(void sortFunction(), int *arr, int arrSize);
int printArr(int *arr, int arrSize);
void printStats();

int main() {
    // Creating array
    int initArr[ARR_SIZE];
    generateArray(initArr, ARR_SIZE, ARR_MIN_VALUE, ARR_MAX_VALUE);

    printf("\n%16s | %8s | %7s \n", "Algorithm name", "Compares", "Assigns");
    printf("--------------------------------------\n");

    // Checking bubble sort algorithm
    if(!checkAlgorithm(bubbleSort, initArr, ARR_SIZE)) {
        printf("An error accured in bubble sort algorithm.\n");
        cmpCount = -1;
        assignCount = -1;
    }
    printStats("Bubble sort");

    // Checking quick sort algorithm
    if(!checkAlgorithm(quickSort, initArr, ARR_SIZE)) {
        printf("An error accured in quick sort algorithm.\n");
        cmpCount = -1;
        assignCount = -1;
    }
    printStats("Quick sort");

    // Checking insertion sort algorithm
    if(!checkAlgorithm(insertionSort, initArr, ARR_SIZE)) {
        printf("An error accured in insertion sort algorithm.\n");
        cmpCount = -1;
        assignCount = -1;
    }
    printStats("Insertion sort");

    // Checking selection sort algorithm
    if(!checkAlgorithm(selectionSort, initArr, ARR_SIZE)) {
        printf("An error accured in selection sort algorithm\n");
        cmpCount = -1;
        assignCount = -1;
    }
    printStats("Selection sort");

    // Checking merge sort algorithm
    if(!checkAlgorithm(mergeSort, initArr, ARR_SIZE)) {
        printf("An error accured in merge sort algorithm\n");
        cmpCount = -1;
        assignCount = -1;
    }
    printStats("Merge sort");

    return 0;
}

int checkAlgorithm(void sortFunction(), int *arr, int arrSize) {
    int *tempArr = malloc(arrSize*sizeof(int));
    memcpy(tempArr, arr, arrSize*sizeof(int));

    sortFunction(tempArr, arrSize);
    if(!checkNumberLayout(tempArr, arrSize)) {
        free(tempArr);
        return 0;
    }
    free(tempArr);

    return 1;
}

void printStats(char *algorithmName) {
    printf("%-16s | %-8d | %-7d \n", algorithmName, cmpCount, assignCount);
}
