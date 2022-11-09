#include <stdio.h>
#include <assert.h>
#include <string.h>

void includeChars(char string[], char value, int num);

int main() {
    char string[] = "abc";

    includeChars(string, 'm', 2);
    assert(strcmp(string, "mmc") == 0);

    includeChars(string, 'g', 0);
    assert(strcmp(string, "mmc") == 0);

    return 0;
}

void includeChars(char string[], char value, int num) {
    for(int i = 0; i < num; ++i) {
        string[i] = value;
    }
}

