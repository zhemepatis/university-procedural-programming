#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "list.h"

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
    if((*node)->value == criterea) {
        node_t *temp = createNode(value);
        temp->next = *node;
        *node = temp;
        return;
    }

    if((*node)->next != NULL)
        insertNode(&((*node)->next), criterea, value);
}

int loadList(node_t **head) {
    printf("Enter file name that contains list elements: ");
    char filename[256] = {0};
    scanf("%s", filename);

    FILE *in = fopen(filename, "r");
    if(in == NULL) {
        printErr("unable locate the file");
        return 1;
    }

    while(!feof(in)) {
        int value;
        if(!getInt(in, &value)) {
            printErr("unsuccessful attempt to load list elements. Process terminated");
            return 1;
        }

        node_t *temp = createNode(value);
        addNode(head, temp);
    }

    return 0;
}

void emptyList(node_t **node) {
    if((*node)->next != NULL)
        emptyList(&((*node)->next));
    
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