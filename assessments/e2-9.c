#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define ARRAY_CAPACITY 1000

// Function validating user input
// input name - the text to be printed when user is asked to enter a value
// lowerLimit - the smallest possible value of input
// upperLimit - the biggest possible value of input
int dataValidation(char inputName[], int lowerLimit, int upperLimit);

int main() {
    int vectorSize = dataValidation("vector size", 1, ARRAY_CAPACITY);

    int vectorChange[ARRAY_CAPACITY];   // Array indicating whether vector is decreasing/increasing
    vectorChange[0] = 0;

    int extremumsIndex[ARRAY_CAPACITY]; // Array that stores extremum indexes
    int numOfExtremums = 0;

    int prevVectorElement;
    for(int i = 0; i < vectorSize; ++i) { 
        char number[5];
        itoa((i + 1), number, 10);
        char inputName[ARRAY_CAPACITY + 27] = "element of vector No. ";
        strcat(inputName, number);

        int vectorElement = dataValidation(inputName, INT_MIN+1, INT_MAX-1);

        if(!i) {
            prevVectorElement = vectorElement;
            continue;
        }

        // Checking whether vector is decreasing/increasing
        if(vectorElement < prevVectorElement)
            vectorChange[i] = -1;
        else if(vectorElement > prevVectorElement)
            vectorChange[i] = 1;
        else if(vectorElement == prevVectorElement)
            vectorChange[i] = 0;

        // If the current point is an extremum then save its index
        if(vectorChange[i] != 0 && vectorChange[i-1] != 0 && vectorChange[i] != vectorChange[i-1])
            extremumsIndex[numOfExtremums++] = i-1;

        prevVectorElement = vectorElement;
    }

    // Getting and printing the results
    if(numOfExtremums < 2) {
        printf("Impossible to find the biggest distance between extremums.\n");
        return 0;
    }

    int maxDistance = extremumsIndex[numOfExtremums-1]-extremumsIndex[0];
    printf("The biggest distance between two extremums is: %d", maxDistance);
    
    return 0;
}

int dataValidation(char inputName[], int lowerLimit, int upperLimit) {
    int scannedValue;

    printf("Enter %s: ", inputName);
    if(scanf("%d", &scannedValue) != 1 || getchar() != '\n') {
        printf("Incorrect input. The value must be an integer.\n");

        char temp;
        scanf("%*[^\n]%c", &temp, &temp);
        scannedValue = dataValidation(inputName, lowerLimit, upperLimit);
    }

    if(lowerLimit > scannedValue || upperLimit < scannedValue) {
        printf("Incorrect input. It must fall in the interval [%d; %d].\n", lowerLimit, upperLimit);
        scannedValue = dataValidation(inputName, lowerLimit, upperLimit);
    }

    return scannedValue;
}