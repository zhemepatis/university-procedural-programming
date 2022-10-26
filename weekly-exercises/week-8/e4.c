#include <stdio.h>
#include <stdlib.h>

int splitData(int *initialArray, int arraySize, int firstPartSize, int **newArray1, int **newArray2);

int main() {
    int arraySize = 6;
    int array[] = {5, 6, 5, 3, 12, 77};

    int *firstArray = NULL;
    int *secondArray = NULL;

    splitData(array, arraySize, 3, &firstArray, &secondArray);

    free(firstArray);
    free(secondArray);

    return 0;
}

int splitData(int *initialArray, int arraySize, int firstPartSize, int **newArray1, int **newArray2) {
    if(initialArray == NULL || arraySize < firstPartSize || *newArray1 != NULL || *newArray2 != NULL)
        return -1;

    *newArray1 = calloc(firstPartSize, sizeof(int));

    int secondArraySize = arraySize - firstPartSize;
    *newArray2 = calloc(secondArraySize, sizeof(int));

    if(*newArray1 == NULL || *newArray2 == NULL)
        return -1;

    for(int i = 0; i < arraySize; ++i) {
        if(i < firstPartSize) {
            *(*newArray1+i) = initialArray[i];
            continue;
        }

        int index = i - firstPartSize;
        *(*newArray2+index) = initialArray[i];
    }

    return 0;
}