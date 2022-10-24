#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int * createArray(int size, int low, int high);
int getRandomValue(int low, int high);

int main() {
    int arraySize = 5;

    int *array = createArray(5, 0, 5);
    free(array);

    return 0;
}

int * createArray(int size, int low, int high) {
    int *array = calloc(size, sizeof(int));

    if(array == NULL)
        return NULL;

    srand(time(NULL));
    for(int i = 0; i < size; ++i) {
        array[i] = getRandomValue(low, high);
    }

    return array;
}

int getRandomValue(int low, int high) {
    return rand() % (high - low + 1) + low;
}