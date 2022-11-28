#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"

int cmpCount;
int assignCount;

// General functions
void swap(int *a, int *b) {
    int tempPtr = *a;
    *a = *b;
    *b = tempPtr;
}

int checkNumberLayout(int *arr, int arrSize) {
    for(int i = 1; i < arrSize; ++i) {
        if(arr[i-1] > arr[i])
            return 0;
    }

    return 1;
}

int *createCustomArray() {
    int arrSize;
    printf("Enter array size: ");
    scanf("%d", &arrSize);

    int arr[100]; 
    for(int i = 0; i < arrSize; ++i) {
        printf("\nEnter array element number %d: ", i);
        scanf("%d", &(arr[i]));
    }

    return arr;
}

// Bubble sort
void bubbleSort(int *arr, int arrSize) {
    cmpCount = 0;
    assignCount = 0;

    for(int i = 0; i < arrSize-1; ++i) {
        for(int j = i+1; j < arrSize; ++j) {
            if(arr[i] > arr[j])
                swap(&arr[i], &arr[j]);

            ++cmpCount;
            assignCount += 2;
        }
    }
}

// Quick sort
int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int i = start;

    for(int j = start; j < end; ++j) {
        if(arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            ++i;

            assignCount += 2;
        }

        ++cmpCount;
    }
    swap(&arr[i], &arr[end]);
    assignCount += 2;

    return i;
}

void quickSortRecursion(int *arr, int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSortRecursion(arr, start, pivot-1);
        quickSortRecursion(arr, pivot+1, end);
    }
}

void quickSort(int *arr, int arrSize) {
    cmpCount = 0;
    assignCount = 0;

    quickSortRecursion(arr, 0, arrSize-1);
}

// Insertion sort
void insertionSort(int *arr, int arrSize) {
    cmpCount = 0;
    assignCount = 0;

    for(int i = 1; i < arrSize; ++i) {
        int currElement = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > currElement) {
            arr[j+1] = arr[j];
            --j;

            ++cmpCount;
            ++assignCount;
        }
        arr[j+1] = currElement;
        ++assignCount;
    }
}

// Selection sort
void selectionSort(int *arr, int arrSize) {
    cmpCount = 0;
    assignCount = 0;

    for(int i = 0; i < arrSize-1; ++i) {
        int minIndex = i;

        for(int j = i + 1; j < arrSize; ++j) {
            minIndex = (arr[minIndex] > arr[j]) ? j : minIndex;
            ++cmpCount;
        }
        swap(&arr[i], &arr[minIndex]);
        assignCount += 2;
    }
}

// Merge sort
void mergeArr(int *arr, int leftPart, int middle, int rightPart) {
    int leftLength = middle - leftPart + 1;
    int rightLength = rightPart - middle;

    int *tempLeft  = calloc(leftLength, sizeof(int));
    int *tempRight = calloc(rightLength, sizeof(int));

    for(int i = 0; i < leftLength; ++i)
        tempLeft[i] = arr[leftPart + i];
        
    for(int i = 0; i < rightLength; ++i)
        tempRight[i] = arr[middle + 1 + i];


    for(int i = 0, j = 0, k = leftPart; k <= rightPart; ++k) {
        if((i < leftLength) && (j >= rightLength || tempLeft[i] <= tempRight[j])) {
            arr[k] = tempLeft[i];
            ++i;
        }
        else {
            arr[k] = tempRight[j];
            ++j;
        }

        ++cmpCount;
        ++assignCount;
    }

    free(tempLeft);
    free(tempRight);
}

void mergeSortRecursion(int *arr, int leftPart, int rightPart) {
    if(leftPart < rightPart) {
        int middle = leftPart + (rightPart - leftPart) / 2;

        mergeSortRecursion(arr, leftPart, middle);
        mergeSortRecursion(arr, middle+1, rightPart);

        mergeArr(arr, leftPart, middle, rightPart);
    }
}

void mergeSort(int *arr, int arrSize) {
    cmpCount = 0;
    assignCount = 0;

    mergeSortRecursion(arr, 0, arrSize-1);
}
