#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "arrays.h"

void printArr(int *arr, int num) {
    if(num == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array: ");
    for(int i = 0; i < num; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}

int cmpArr(int *arr1, int num1, int *arr2, int num2) {
    if(num1 != num2)
        return 0;

    for(int i = 0; i < num1; ++i) {
        if(arr1[i] != arr2[i])
            return 0;
    }

    return 1;
}