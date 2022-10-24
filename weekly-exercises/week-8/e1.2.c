#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int * createArray(int size, int low, int high);
int getRandomValue(int low, int high);

int main() {
    int arraySize = 5;

    int *array_ptr = createArray(5, 0, 5);
    free(array_ptr);

    return 0;
}

int * createArray(int size, int low, int high) {
    int *array_ptr = calloc(size, sizeof(int));

    if(array_ptr == NULL)
        return NULL;

    srand(time(NULL));
    for(int i = 0; i < size; ++i) {
        *(array_ptr + i*sizeof(int)) = getRandomValue(low, high);
    }

    return array_ptr;
}

int getRandomValue(int low, int high) {
    return rand() % (high - low + 1) + low;
}