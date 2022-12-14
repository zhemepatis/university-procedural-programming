#ifndef FUNCTIONS_H
    #define FUNCTIONS_H
    #define MAX_FILENAME_LENGTH 256

    int menu(char *caption, int optNum, char **options);
    void printErr(char *err);
    int getInt(FILE *in, int *input);
    int getFilename(char *filename);
    FILE *openFile(char *filename, char *mode);

#endif