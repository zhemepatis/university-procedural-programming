#ifndef ARR_H
    #define ARR_H

    extern int cmpCount;
    extern int assignCount;

    void generateArray(int data[], int size, int low, int high);
    int checkNumberLayout(int *arr, int arrSize);
    int *createCustomArray();
    
    void bubbleSort(int *arr, int arrSize);

    void quickSort(int *arr, int arrSize);
    void quickSortRecursion(int *arr, int start, int end);
    int partition(int *arr, int start, int end);

    void insertionSort(int *arr, int arrSize);

    void selectionSort(int *arr, int arrSize);

    void mergeSort(int *arr, int arrSize);
    void mergeSortRecursion(int *arr, int leftPart, int rightPart);
    void mergeArr(int *arr, int leftPart, int middle, int rightPart);

#endif