#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * biggestFile(int num, char **filenames);
long getFileSize(char *fileName);

int main(int argc, char **argv) {
    int filesNum = argc - 1;
    char **fileNames = (argv + sizeof(char));

    char *biggestFileName =  biggestFile(filesNum, fileNames);

    return 0;
}

char * biggestFile(int num, char **filenames) {
    long maxSize = -1;
    char *result = calloc(10, sizeof(char));

    for(int i = 0; i < num; ++i) {
        long fileSize = getFileSize(filenames[i]);

        if(fileSize > maxSize) {
            int fileNameLenght = strlen(filenames[i]);
            result = realloc(result, sizeof(char)*fileNameLenght);

            strcpy(result, filenames[i]);
            maxSize = fileSize;
        }
    }

    return result;
}

long getFileSize(char *fileName) {
    FILE *fp;
    fp = fopen(fileName, "r+");

    if(fp == NULL || fseek(fp, SEEK_SET, SEEK_END) != 0)
        return -1l;

    long fileSize = ftell(fp);
    fclose(fp);

    return fileSize;
}