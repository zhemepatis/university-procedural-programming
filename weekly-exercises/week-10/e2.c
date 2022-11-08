#include <stdio.h>
#include <assert.h>

int compareStrings(char *string1, char *string2);
int length(char string[]);

int main() {  
    char string1[] = "ABCD";
    char string2[] = "abcd";
    char string3[] = "ABCDE";

    if(compareStrings(string1, string2) != -1) {
        // ABCD ? abcd
        assert(0);
    }
    else if(compareStrings(string1, string3) != -1) {
        // ABCD ? ABCDE
        assert(0);
    }
    else if(compareStrings(string1, string1) != 0) {
        // ABCD ? ABCD
        assert(0);
    }
    else if(compareStrings(string2, string1) != 1) {
        // abcd ? ABCD
        assert(0);
    }

    return 0;
}

int compareStrings(char *string1, char *string2) {
    int length1 = length(string1);
    int length2 = length(string2);

    if(length1 > length2)
        return 1;
    else if (length1 < length2)
        return -1;

    for(int i = 0; i < length1; ++i) {
        if(string1[i] > string2[i])
            return 1;
        else if(string1[i] < string2[i])
            return -1;
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