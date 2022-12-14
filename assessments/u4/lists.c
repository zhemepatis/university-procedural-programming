#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "lists.h"

node_t *createNode(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

void addNode(node_t **head, node_t *node) {
    node_t **temp = head;
    
    while(*temp != NULL)
        temp = &((*temp)->next);

    *temp = node;
}

void insertNode(node_t **node, int criterea, int value) {
    // Checking if node exists
    if((*node) == NULL) 
        return;

    // Checking whether the node value is one we need
    // If so, a new node is created and inserted into the list
    if((*node)->value == criterea) {
        node_t *temp = createNode(value);
        temp->next = *node;
        *node = temp;
        return;
    }

    // If previous conditions were false, checking if it's not the last node
    // If it's not, recursively moving to the next node
    if((*node)->next != NULL)
        insertNode(&((*node)->next), criterea, value);
}

int loadList(FILE *in, node_t **head) {
    while(!feof(in)) {
        // Taking value of the next node in the list
        int value;
        if(!getInt(in, &value)) {
            printErr("unsuccessful attempt to load list elements. Process terminated");
            emptyList(head);
            return 1;
        }

        // Creating node and inserting it into list
        node_t *temp = createNode(value);
        addNode(head, temp);
    }

    return 0;
}

void emptyList(node_t **node) {
    // Recursive search for the last element
    if((*node)->next != NULL)
        emptyList(&((*node)->next));
    
    // Freeing memory that was allocated for the (last) node and setting new end of the list 
    free(*node);
    *node = NULL;
}

void printList(node_t *head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");

    node_t *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("\n");
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