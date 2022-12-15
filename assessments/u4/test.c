#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "functions.h"
#include "arrays.h"
#include "lists.h"

void convertList(node_t *head, int **arr, int *arrSize);
void testAddNode();
void testInsertElement();
void testEmptyList();

int main() {
    // Testing adding nodes
    testAddNode();    

    // Testing inserting nodes
    testInsertElement();

    // Testing emptying list
    testEmptyList();

    return 0;
}

void convertList(node_t *head, int **arr, int *arrSize) {
    int tempNum = 0;
    int *tempArr = NULL;

    // Checking, whether next list node exist
    // If it does, then new array element is created
    while(head != NULL) {
        ++tempNum;
        tempArr = realloc(tempArr, tempNum*sizeof(int));
        tempArr[tempNum-1] = head->value;
        head = head->next;
    }

    *arr = tempArr;
    *arrSize = tempNum;
}

void testAddNode() {
    // Creating list
    node_t *head = NULL;
    node_t *node = createNode(1);
    addNode(&head, node);

    node = createNode(2);
    addNode(&head, node);
    
    node = createNode(3);
    addNode(&head, node);

    // Converting list to an array to make it esier to check
    int *listArr;
    int listArrSize;
    convertList(head, &listArr, &listArrSize);

    // Creating model array to be compared with list array
    int modelArr[] = {1, 2, 3};
    int modelArrSize = 3;
    
    // Comparing model array with list array
    assert(cmpArr(listArr, listArrSize, modelArr, modelArrSize));

    // Clearing memory
    free(listArr);
    emptyList(&head);
}

void testInsertElement() {
    // Creating list
    node_t *head = NULL;
    node_t *node = createNode(1);
    addNode(&head, node);

    node = createNode(2);
    addNode(&head, node);
    
    node = createNode(3);
    addNode(&head, node);

    // Inserting nodes
    insertNode(&head, 2, 3);
    insertNode(&head, 3, 4);
    insertNode(&head, 1, 47);
    insertNode(&head, 50, 50);

    // Converting list to an array to make it esier to check
    int *listArr;
    int listArrSize;
    convertList(head, &listArr, &listArrSize);

    // Creating model array to be compared with list array
    int modelArr[] = {47, 1, 4, 3, 2, 3};
    int modelArrSize = 6;

    // Comparing model array with list array
    assert(cmpArr(listArr, listArrSize, modelArr, modelArrSize));

    // Clearing memory
    free(listArr);
    emptyList(&head);
}

void testEmptyList() {
    // Creating list
    node_t *head = NULL;
    node_t *node = createNode(1);
    addNode(&head, node);

    node = createNode(2);
    addNode(&head, node);
    
    node = createNode(3);
    addNode(&head, node);

    // Emptying list
    emptyList(&head);

    // Converting list to an array to make it esier to check
    int *listArr;
    int listArrSize;
    convertList(head, &listArr, &listArrSize);

    // Creating model array to be compared with list array
    int *modelArr = NULL;
    int modelArrSize = 0;

    // Comparing model array with list array
    assert(cmpArr(listArr, listArrSize, modelArr, modelArrSize));

    free(listArr);
}

