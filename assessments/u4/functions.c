#include <stdio.h>
#include "functions.h"

int menu(char *caption, int optNum, char **options) {
    int optionIsValid = 0;
    int option = 0;

    while(!optionIsValid) {
        printf("\n%s\n", caption);
        for(int i = 0; i < optNum; ++i)
            printf("%d. %s\n", i+1, options[i]);

        printf("Enter option number: ");
        if(!getInt(stdin, &option))
            continue; 

        if(option < 1 || option > optNum) {
            printErr("there is no such option");
            continue;
        }

        optionIsValid = 1;
    }

    return option;
}

void printErr(char *err) {
    printf("ERROR: %s.\n", err);
}

int getInt(FILE *in, int *input) {
    if(fscanf(in, "%d", input) != 1 || (in == stdin && fgetc(in) != '\n')) {
        printErr("input should be integer");
        while(in == stdin && fgetc(in) != '\n');
        return 0;
    }

    return 1;
}