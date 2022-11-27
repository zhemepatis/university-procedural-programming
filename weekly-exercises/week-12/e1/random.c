#include <stdlib.h>
#include <time.h>

int getRandomNum(int low, int high) {
    return (rand() % (high - low + 1) + low);
}

void generateArray(int data[], int size, int low, int high) {
    srand(time(NULL));

    for(int i = 0; i < size; ++i)
        data[i] = getRandomNum(low, high);
}