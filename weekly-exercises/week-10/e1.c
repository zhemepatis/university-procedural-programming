#include <stdio.h>
#include <assert.h>

int length(char string[]);

int main() {  
    char string[] = "hello";

    if(length(string) != 5) {
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