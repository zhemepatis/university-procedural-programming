#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int length(char string[]);
char *copyStringCharacters(char string[], int charNum);

int main() {  
    char string1[] = "Hello";
    char string2[] = " ";

    if(strcmp(copyStringCharacters(string1, 6), "Hello") != 0){
        assert(0);
    }
    if(strcmp(copyStringCharacters(string1, 4), "Hell") != 0){
        assert(0);
    }
    if(strcmp(copyStringCharacters(string2, 1), " ") != 0){
        assert(0);
    }

    return 0;
}

int length(char string[]) {
    int stringLength = 0;

    while(string[stringLength] != '\0') {
        ++stringLength;
    }

    return stringLength;
}

char *copyStringCharacters(char string[], int charNum) {
    char *result = calloc(charNum, sizeof(char));

    for(int i = 0; i < charNum; ++i) {
        result[i] = string[i];
    }

    return result;
}