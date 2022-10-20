#include <stdio.h>

long getFileSize(char *fileName);

int main() {
    char filename[80];
    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Result: %ld", getFileSize(filename));

    
    return 0;
}

long getFileSize(char *fileName) {
    FILE *fp;
    fp = fopen(fileName, "r+");

    if(fp == NULL || fseek(fp, SEEK_SET, SEEK_END) != 0)
        return -1l;

    return ftell(fp);
}