#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define LINE_LENGTH 255

char *orgLine(char *dest, char *line);
void orgFile(FILE *inFile, FILE *outFile);
void cutStart(char *line, int sliceSize);
void fillArr(char *arr, int arrSize, char *inp, char *sep);

int main() {
    char *inpFilename = calloc(_MAX_FNAME, sizeof(char));
    printf("Enter input file name: ");
    scanf("%s", inpFilename);
    FILE *input = fopen(inpFilename, "rb");
    if(input == NULL) {
        perror("Error");
        return -1;
    }

    char *outFilename = calloc(_MAX_FNAME, sizeof(char));
    printf("Enter output file name: ");
    scanf("%s", outFilename);
    FILE *output = fopen(outFilename, "wb");
    if(output == NULL) {
        perror("Error");
        return -1;
    }

    orgFile(input, output);

    fclose(input);
    fclose(output);

    free(inpFilename);
    free(outFilename);

    return 0;
}

void orgFile(FILE *inFile, FILE *outFile) {
    while(!feof(inFile)) {
        char *line = calloc(LINE_LENGTH+1, sizeof(char));

        fscanf(inFile, "%255[^\n]", line);
        fscanf(inFile, "%*[^\n]");
        fscanf(inFile, "%*[\n]");

        char *result = calloc(LINE_LENGTH+1, sizeof(char));
        orgLine(result, line);
        fprintf(outFile, "%s\n", result);

        free(line);
    }

}

char *orgLine(char *dest, char *line) {
    char *wrdArr = calloc(1, sizeof(char));
    int wrdArrSize = 0;
    int wrdCount = 0;

    char *spcArr = calloc(1, sizeof(char));
    int spcArrSize = 0;
    int spcCount = 0;

    int lineLength = strlen(line);

    while(lineLength != 0) {
        // Counting spaces
        int spaceCount = 0;
        char *space = NULL;
        while(isspace(line[spaceCount])) {
            space = realloc(space, (spaceCount+2)*sizeof(char));
            space[spaceCount] = line[spaceCount];
            ++spaceCount;
            space[spaceCount] = '\0';
        }

        if(spaceCount) {
            ++spcCount;

            spcArrSize += spaceCount + 1;
            spcArr = realloc(spcArr, (spcArrSize+1)*sizeof(char));
            space = realloc(space, (spcArrSize+1)*sizeof(char));

            fillArr(spcArr, spcArrSize, space, "$");

            cutStart(line, spaceCount);
            lineLength = strlen(line);
        }
        free(space);

        // Counting words
        char *word = calloc(lineLength + 1, sizeof(char));
        sscanf(line, "%s", word);
        int wrdLength = strlen(word);

        if(wrdLength) {
            ++wrdCount;

            wrdArrSize += wrdLength + 1;
            wrdArr = realloc(wrdArr, (wrdArrSize+1)*sizeof(char));
            word = realloc(word, (wrdArrSize+1)*sizeof(char));

            fillArr(wrdArr, wrdArrSize, word, " ");

            cutStart(line, wrdLength);
            lineLength = strlen(line);
        }
        free(word);
    }

    int resLength = 0;
    lineLength = strlen(wrdArr);

    if(spcCount > wrdCount) {
        char *space = calloc(strlen(spcArr) + 1, sizeof(char));
        sscanf(spcArr, "%[^$]", space);
        int spcLength = strlen(space);

        if(spcLength) {
            resLength += spcLength + 1;

            strcat(dest, space);

            cutStart(spcArr, spcLength+1);
        }
        free(space);
    }

    while(lineLength != 0) {
        char *word = calloc(lineLength + 1, sizeof(char));
        sscanf(wrdArr, "%s", word);
        int wrdLength = strlen(word);

        if(wrdLength) {
            resLength += wrdLength + 1;
            strcat(dest, word);

            cutStart(wrdArr, wrdLength+1);
            lineLength = strlen(wrdArr);
        }
        free(word);


        char *space = calloc(strlen(spcArr) + 1, sizeof(char));
        sscanf(spcArr, "%[^$]", space);
        int spcLength = strlen(space);

        if(spcLength) {
            resLength += spcLength + 1;

            strcat(dest, space);

            cutStart(spcArr, spcLength+1);
        }
        free(space);
    }

    free(wrdArr);
    free(spcArr);
} 

void cutStart(char *line, int sliceSize) {
    int lineLength = strlen(line);
    memmove(line, (line + sliceSize), (lineLength-sliceSize+1));
}

void fillArr(char *arr, int arrSize, char *inp, char *sep) {  
    if(strcmp(sep, "$") == 0) {
        strcat(arr, inp);
        strcat(arr, sep);
    }
    else {
        char *temp = calloc(arrSize + 1, sizeof(char));

        strcpy(temp, sep);
        strcat(temp, arr);
        strcat(inp, temp);
        strcpy(arr, inp);

        free(temp);
    }
}