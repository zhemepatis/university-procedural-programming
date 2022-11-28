#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"
#include "arrays.h"

#define ARR_SIZE 20
#define ARR_MIN_VALUE 0
#define ARR_MAX_VALUE 100
#define MENU_OPTIONS 5
#define SORT_TYPES 5

struct Statistics {
    char *name;
    void (*function)(int *, int);
    int cmpCount;
    int assignCount;
};

void initStats(struct Statistics *stats);
void printStats(struct Statistics *stats);

int menu(int optNum, char **options);
void printHelp();
void newData(int *arr, int arrSize, struct Statistics *stats);
int checkAlgorithm(void sortFunction(int *, int), int *arr, int arrSize);

int main() {
    struct Statistics stats[SORT_TYPES];
    initStats(stats);
        
    char *menuOptions[] = { "Add random data set", "Add custom data set", "Print statistics", "Help", "Exit"};
    int opt = 0;

    while(opt != MENU_OPTIONS) {
        opt = menu(MENU_OPTIONS, menuOptions);

        switch (opt) {
            case 1:
                int *randArr = malloc(ARR_SIZE*sizeof(int));
                generateArray(randArr, ARR_SIZE, ARR_MIN_VALUE, ARR_MAX_VALUE);
                printArray(randArr, ARR_SIZE);
                newData(randArr, ARR_SIZE, stats);
                free(randArr);
                break;

            case 2:
                int *customArr;
                int arrSize;
                createCustomArray(customArr, &arrSize);
                printArray(customArr, arrSize);
                newData(customArr, arrSize, stats);
                free(customArr);
                break; 
            
            case 3:
                printStats(stats);
                break;

            case 4:
                printHelp();
                break;
            
            case 5:
                printf("Program finished its work.\n");
                break;
            
            default:
                printf("There's no such option. Please try again.\n");
                break;

        }
    }

    return 0;
}

void initStats(struct Statistics *stats) {
    char *algorithms[] = {"Bubble sort", "Quick sort", "Insertion sort", "Selection sort", "Merge sort"};
    for(int i = 0; i < SORT_TYPES; ++i) {
        struct Statistics element = stats[i];

        element.name = algorithms[i];
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

void printStats(struct Statistics *stats) {
    printf("\n%16s | %8s | %7s \n", "Algorithm name", "Compares", "Assigns");
    printf("--------------------------------------\n");

    for(int i = 0; i < SORT_TYPES; ++i) {
        printf("%-16s | %-8d | %-7d \n", stats[i].name, stats[i].cmpCount, stats[i].assignCount);
    }
}

void newData(int *arr, int arrSize, struct Statistics *stats) {  
    for(int i = 0; i < SORT_TYPES; ++i) {
        int algorithmCheck = checkAlgorithm(stats[i].function, arr, arrSize);

        if(!algorithmCheck) {
            printf("An error accured in %s algorithm.\n", stats[i].name);
            stats[i].cmpCount = -1;
            stats[i].assignCount = -1;
            assignCount = -1;
        }
        else if(stats[i].cmpCount != -1 && stats[i].assignCount != -1) {
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

void printHelp() {
    printf("This program compares the performance of different sorting algorithms by counting the number of times two adjacent elements are compared and the number of times they are assigned values.\n");
    printf("Option 1 creates an array of %d elements, fills it with random values from %d to %d, and runs all sorting algorithms through it. All the data is added to the final statistics.\n", ARR_SIZE, ARR_MIN_VALUE, ARR_MAX_VALUE);
    printf("Option 2 allows you to create your custom array, and runs all sorting algorithms through it. All the data is added to the final statistics.\n");
    printf("Option 3 prints all the statistics.\n");
    printf("Option 4 terminates the program.\n");
    printf("A value of -1 in the final table means that an error occurred during the execution of this algorithm, so no statistics were collected about its performance.\n");
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