#include <stdio.h>
#include <assert.h>

char *findChar(char string[], char character);
int length(char string[]);

int main() {

    char string[] = "Hello world!";

    if(findChar(string, '?') != NULL) {
        assert(0);
    }
    if(findChar(string, 'l') != (string + sizeof(char)*2)) {
        assert(0);
    }
    if(findChar(string, ' ') != (string + sizeof(char)*5)) {
        assert(0);
    }

    return 0;
}

char *findChar(char string[], char character) {
    int stringLength = length(string);

    for(int i = 0; i < stringLength; ++i) {
        if(string[i] == character)
            return (string + i*sizeof(char));
    }

    return NULL;
}

int length(char string[]) {
    int stringLength = 0;

    while(string[stringLength] != '\0') {
        ++stringLength;
    }

    return stringLength;
}

