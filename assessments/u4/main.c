#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "list.h"

#define NUM_OF_OPTIONS 4

int main() { 
    node_t *head = NULL;

    char *options[] = {"Load list elements", "Print list elements", "Insert element", "Exit application"};
    int option = -1;
    while(option != NUM_OF_OPTIONS) {
        option = menu("MENU", 4, options);

        switch (option) {
            case 1:
                if(head != NULL) {
                    printf("Warning\n");
                    emptyList(&head);
                }
                loadList(&head);
                break;

            case 2:
                printList(head);
                break;

            case 3:
                printf("Enter criterea: ");
                int criterea, value;
                getInt(stdin, &criterea);
                printf("Enter value: ");
                getInt(stdin, &value);
                insertNode(&head, criterea, value);
                
                break;
        }
    }

    if(head != NULL)
        emptyList(&head);

    return 0;
}