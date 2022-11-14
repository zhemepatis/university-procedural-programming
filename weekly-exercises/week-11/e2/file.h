#ifndef FILE_H
    #define FILE_H
    
    extern int saveCount;
    extern int loadCount;

    void saveToFile(int *arr, int arrSize, char *filename);
    int *loadFromFile(char *filename);

#endif