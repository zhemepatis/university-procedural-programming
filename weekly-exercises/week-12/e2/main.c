#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "random.h"
#include "arrays.h"

#define ARR_SIZE 1000
#define ARR_MIN_VALUE -100
#define ARR_MAX_VALUE 100
#define MENU_OPTIONS 4
#define SORT_TYPES 5

double timeCount = 0.0;

struct Statistics {
    char *name;
    void (*function)(int *, int);
    int cmpCount;
    int assignCount;
    double timeCount;
};

void initStats(struct Statistics *stats);
void printStats(struct Statistics *stats);
void printHelp();
int menu(int optNum, char **options);
int getInteger(char *msg);
void newData(int *arr, int arrSize, struct Statistics *stats);
int checkAlgorithm(void sortFunction(int *, int), int *arr, int arrSize);

int main() {
    struct Statistics stats[SORT_TYPES];
    initStats(stats);
        
    char *menuOptions[] = { "Add random data set", "Print statistics", "Help", "Exit"};
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
                printStats(stats);
                break;

            case 3:
                printHelp();
                break;
            
            case 4:
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
        element.timeCount = 0.0;

        stats[i] = element;
    }

    stats[0].function = bubbleSort; 
    stats[1].function = quickSort; 
    stats[2].function = insertionSort; 
    stats[3].function = selectionSort; 
    stats[4].function = mergeSort; 
}

void printStats(struct Statistics *stats) {
    printf("\n%16s | %8s | %7s | %14s \n", "Algorithm name", "Compares", "Assigns", "Execution time");
    printf("--------------------------------------------------------\n");

    for(int i = 0; i < SORT_TYPES; ++i) {
        printf("%-16s | %-8d | %-7d | %-15f \n", stats[i].name, stats[i].cmpCount, stats[i].assignCount, stats[i].timeCount);
    }
}

void newData(int *arr, int arrSize, struct Statistics *stats) {  
    for(int i = 0; i < SORT_TYPES; ++i) {
        int algorithmCheck = checkAlgorithm(stats[i].function, arr, arrSize);

        if(!algorithmCheck) {
            printf("An error accured in %s algorithm.\n", stats[i].name);
            stats[i].cmpCount = -1;
            stats[i].assignCount = -1;
            stats[i].timeCount = -1.0;
        }
        else if(stats[i].cmpCount != -1 && stats[i].assignCount != -1) {
            stats[i].cmpCount += cmpCount;
            stats[i].assignCount += assignCount;
            stats[i].timeCount += timeCount;
        }
    }
}

int checkAlgorithm(void sortFunction(int *, int), int *arr, int arrSize) {
    int *tempArr = malloc(arrSize*sizeof(int));
    memcpy(tempArr, arr, arrSize*sizeof(int));

    time_t time = clock();
    sortFunction(tempArr, arrSize);
    time = clock() - time;
    timeCount = ((double) time)/CLOCKS_PER_SEC;

    if(!checkNumberLayout(tempArr, arrSize)) {
        free(tempArr);
        return 0;
    }
    free(tempArr);

    return 1;
}

void printHelp() {
    printf("\nThis program compares the performance of different sorting algorithms by counting the number of times two adjacent elements are compared and the number of times they are assigned values.\n");
    printf("Option 1 creates an array of %d elements, fills it with random values from %d to %d, and runs all sorting algorithms through it. All the data is added to the final statistics.\n", ARR_SIZE, ARR_MIN_VALUE, ARR_MAX_VALUE);
    printf("Option 2 prints all the statistics.\n");
    printf("Option 3 terminates the program.\n");
    printf("A value of -1 in the final table means that an error occurred during the execution of this algorithm, so no statistics were collected about its performance.\n");
}

int menu(int optNum, char **options) {
    printf("\nMENU\n");
    for(int i = 0; i < optNum; ++i) {
        printf("%d.%s\n", (i+1), options[i]);
    }

    return getInteger("Enter menu option number");
}

int getInteger(char *msg) {
    printf("%s: ", msg);
    
    int scannedValue;
    if(scanf("%d", &scannedValue) != 1 || getchar() != '\n') {
        printf("Incorrect input. The value must be an integer.\n");

        char temp;
        scanf("%*[^\n]%c", &temp, &temp);
        scannedValue = getInteger(msg);
    }

    return scannedValue;
}