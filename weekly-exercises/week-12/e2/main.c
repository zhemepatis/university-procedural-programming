#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"
#include "arrays.h"

#define ARR_SIZE 20
#define ARR_MIN_VALUE 0
#define ARR_MAX_VALUE 100
#define MENU_OPTIONS 4
#define SORT_TYPES 5

struct Statistics {
    char *name;
    void (*function)(int *, int);
    int cmpCount;
    int assignCount;
};

void initStats(struct Statistics *stats);
void newData(int *arr, struct Statistics *stats);
int menu(int optNum, char **options);

int checkAlgorithm(void sortFunction(int *, int), int *arr, int arrSize);
void printStats(struct Statistics *stats);

int main() {
    struct Statistics stats[SORT_TYPES];
    initStats(stats);

    char *menuOptions[] = { "Add random data set", "Add custom data set", "Print statistics", "Exit"};
    int opt = 0;

    while(opt != MENU_OPTIONS) {
        opt = menu(MENU_OPTIONS, menuOptions);

        switch (opt) {
            case 1:
                int *randArr = malloc(ARR_SIZE*sizeof(int));
                generateArray(randArr, ARR_SIZE, ARR_MIN_VALUE, ARR_MAX_VALUE);
                newData(randArr, stats);
                free(randArr);
                break;

            case 2:
                int *customArr = createCustomArray();
                newData(customArr, stats);
                break; 
            
            case 3:
                printStats(stats);
                break;
        }
    }

    return 0;
}

void initStats(struct Statistics *stats) {
    char *algorithms[] = {"Bubble sort", "Quick sort", "Insertion sort", "Selection sort", "Merge sort"};
    for(int i = 0; i < SORT_TYPES; ++i) {
        struct Statistics element = stats[i];

        strcpy(element.name, algorithms[i]);
        printf("huh?");
        element.cmpCount = 0;
        element.assignCount = 0;

        stats[i] = element;
    }

    stats[0].function = bubbleSort; 
    stats[1].function = quickSort; 
    stats[2].function = insertionSort; 
    stats[3].function = selectionSort; 
    stats[4].function = mergeSort; 
}

void newData(int *arr, struct Statistics *stats) {  
    for(int i = 0; i < SORT_TYPES; ++i) {
        int algorithmCheck = checkAlgorithm(stats[i].function, arr, ARR_SIZE);

        if(!algorithmCheck) {
            printf("An error accured in %s algorithm.\n", stats[i].name);
            cmpCount = -1;
            assignCount = -1;
        }
        else {
            stats[i].cmpCount += cmpCount;
            stats[i].assignCount += assignCount;
        }
    }
}

int checkAlgorithm(void sortFunction(int *, int), int *arr, int arrSize) {
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

void printStats(struct Statistics *stats) {
    printf("\n%16s | %8s | %7s \n", "Algorithm name", "Compares", "Assigns");
    printf("--------------------------------------\n");

    for(int i = 0; i < SORT_TYPES; ++i) {
        printf("%-16s | %-8d | %-7d \n", stats[i].name, stats[i].cmpCount, stats[i].assignCount);
    }
}

int menu(int optNum, char **options) {
    printf("\nMENU\n");
    for(int i = 0; i < optNum; ++i) {
        printf("%d.%s\n", (i+1), options[i]);
    }
    
    printf("\nEnter menu option number: ");
    int opt;
    scanf("%d", &opt);

    return opt;
}