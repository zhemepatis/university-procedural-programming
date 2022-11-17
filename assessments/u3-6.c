#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_LENGTH 256

void orgLine(char *line);
void orgFile(FILE *inFile, FILE *outFile);

int main() {
    FILE *input = fopen("file.txt", "rb");
    FILE *output = fopen("rez.txt", "wb");

    char str[] = "Hello santa! Ive waited you so long!";
    orgLine(str);
    // orgFile(input, output);


    return 0;
}

// [] Only spaces
// [] Only characters
// [] kol kas skaito dar ir to ko nereikia
// [] fix random smiles
// [] check while condition

void orgLine(char *line) {
    int lineLength = strlen(line);

    char **words = NULL;
    int arrSize = 0;
    int wrdCount = 0;
    int wrdSize[100];
    wrdSize[0] = 0;

    while(lineLength != 0) {
        char *word = calloc(lineLength, sizeof(char));
        sscanf(line, "%s", word);
        int wrdLength = strlen(word);

        words = realloc(words, (arrSize + wrdLength + 1)*sizeof(char));
        memmove((words + arrSize*sizeof(char)), word, wrdLength+1);

        arrSize += wrdLength+1;
        ++wrdCount;
        wrdSize[wrdCount] = arrSize;
        free(word);

        memmove(line, (line+wrdLength), (lineLength-wrdLength+1));
        printf("%d: %s\n", strlen(line), line);
        lineLength = strlen(line);
        
        int index = 0;
        int spaceCount = 0;
        while(isspace(line[index])) {
            ++spaceCount;
            ++index;
        }

        lineLength = strlen(line);
        memmove(line, (line+spaceCount), lineLength-spaceCount+1);
        lineLength = strlen(line);
    }

    // 37 - 32

    // char *result = calloc(LINE_LENGTH, sizeof(char));
    // for(int i = wrdCount-1; i > 0; --i) {
    //     int wrdLength = wrdSize[i]-wrdSize[i-1];
    //     printf("word size: %d\n", wrdLength);

    //     char *word = calloc(wrdLength, sizeof(char));
    //     word = memmove(word, (words + wrdSize[i]*sizeof(char)), wrdLength);

    //     // printf("%d: %s\n", wrdSize[i], (words + wrdSize[i]*sizeof(char)));
    //     strcat(result, word);

    //     printf("%s\n", word);
    // }

    // free(words);

    // return result;
} 

void orgFile(FILE *inFile, FILE *outFile) {
    char *line = calloc(LINE_LENGTH, sizeof(char));
    while(!feof(inFile)) {
        fgets(line, LINE_LENGTH-1, inFile);
        printf("%s\n", line);

        
    }
}