#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "list.h"

void initElement(element *list, int value) {
    (*list).value = value;
    (*list).next = NULL;
}

void addElement(element *list, int value) {
    if(list->next != NULL) {
        addElement(list->next, value);
    }
    else {
        list->next = malloc(sizeof(element));
        initElement(list->next, value);
    }
}

int loadElements(element *list) {
    printf("Enter file name that contains list elements: ");
    char filename[256] = {0};
    scanf("%s", filename);

    FILE *in = fopen(filename, "r");
    if(in == NULL) {
        printErr("unable locate the file");
        return 1;
    }

    int listInitialised = 0;
    while(!feof(in)) {
        int value;
        if(!getInt(in, &value)) {
            printErr("unsuccessful attempt to load list elements. Process terminated");
            return 1;
        }

        if(!listInitialised) {
            initElement(list, value);
            listInitialised = 1;
            continue;
        }

        addElement(list, value);
    }

    return 0;
}

void emptyList(element *list) {
    if(list->next != NULL) {
        emptyList(list->next);
    }
    free(list);
}

void printList(element list) {
    printf("%d ", list.value);

    if(list.next != NULL)
        printList(*(list.next));
}