#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int saveCount = 0;
int loadCount = 0;

void saveToFile(int *arr, int arrSize, char *filename) {
    FILE *fp;
    fp = fopen(filename, "wb");

    fprintf(fp, "%d\n", arrSize);
    for(int i = 0; i < arrSize; ++i) {
        fprintf(fp, "%d ", arr[i]);
    }

    saveCount++;
    fclose(fp);
}

int *loadFromFile(char *filename) {
    FILE *fp; 
    fp = fopen(filename, "rb");

    int arrSize;
    fscanf(fp, "%d", &arrSize);

    int *arr = calloc(arrSize, sizeof(int));
    for(int i = 0; i < arrSize; ++i) {
        fscanf(fp, "%d", (arr + i));
    }
    fclose(fp);

    loadCount++;
    return arr;
}