#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    int menu(char *caption, int optNum, char **options);
    void printErr(char *err);
    int getInt(FILE *in, int *input);

#endif